#include "ResultWindow.hpp"

//std::vector<Glib::RefPtr<Gio::AppInfo>> ResultWindow::appList = Gio::AppInfo::get_all();

ResultWindow::ResultWindow() : Gtk::Box(Gtk::ORIENTATION_VERTICAL,0){
    init();
}

ResultWindow::~ResultWindow(){
}

void ResultWindow::find(Glib::ustring searchStatement){
    clearResults(true);
    for(auto app : Gio::AppInfo::get_all()){
        if(Glib::ustring(app->get_name()).lowercase()
                .find(searchStatement.lowercase())!=std::string::npos){
            Glib::RefPtr<SearchResult> result (new SearchResult(app));
            results.push_back(result);
        }
    }
    updateResults();
}

void ResultWindow::select(int direction){
    if(selectedIdx+direction>results.size()-1 || selectedIdx+direction<0) return;
    clearResults();
    selectedIdx += direction;
    updateResults();
}

void ResultWindow::runSelected(){
    results[selectedIdx]->run();
}

void ResultWindow::init(){
    for(auto app : Gio::AppInfo::get_all()){
            Glib::RefPtr<SearchResult> result (new SearchResult(app));
            results.push_back(result);
    }
    updateResults();
}

void ResultWindow::clearResults(bool hardClear){
    int localIdx = selectedIdx%2;
    for(int i=0;i<2 && results.size()>i;i++)
        remove(*(results[selectedIdx-localIdx+i].get()));
    
    if(!hardClear) return;

    results.clear();
    selectedIdx = 0;
}

void ResultWindow::updateResults(){
    int localIdx = selectedIdx%2;
    for(int i=0;i<2 && results.size()>i;i++){
        Glib::RefPtr<SearchResult> result = results[selectedIdx-localIdx+i];
        result->select(localIdx==i);
        pack_start(*result.get());
    }
    show_all();
}