#include "SearchResult.hpp"

SearchResult::SearchResult(Glib::RefPtr<Gio::AppInfo> application) : appToRun(application){
    get_style_context()->add_class("searchResult");

    loadImage();
    
    Glib::ustring description = Glib::ustring(application->get_description());
    if(description.length()>40){
        description = description.substr(0,37)+"...";
    }

    title = Gtk::Label(application->get_name());
    comment = Gtk::Label(description);
    icon = Gtk::Image(iconImage);

    title.get_style_context()->add_class("title");
    comment.get_style_context()->add_class("comment");

    title.set_xalign(0);
    comment.set_xalign(0);

    attach(title,1,0,1,1);
    attach(comment,1,1,1,1);
    attach(icon,0,0,1,2);

    set_size_request(400,40);
}

SearchResult::~SearchResult(){

}

void SearchResult::select(bool isSelected){
    if(isSelected)
        get_style_context()->add_class("active");
    else
        get_style_context()->remove_class("active");
}

void SearchResult::run(){
    const std::vector<std::string> arguments = {""};
    appToRun->launch_uris(arguments);
}

void SearchResult::loadImage(){
    const Glib::RefPtr<Gtk::IconTheme> iconTheme = Gtk::IconTheme::get_default();

    Gtk::IconInfo iconInfo = iconTheme->lookup_icon(appToRun->get_icon(),
            40,Gtk::ICON_LOOKUP_FORCE_SIZE);

    if(iconInfo.gobj()==NULL)
        iconInfo = iconTheme->lookup_icon("application-x-executable",40,Gtk::ICON_LOOKUP_FORCE_SIZE);

    iconImage = iconInfo.load_icon();
}