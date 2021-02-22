#include "LaunchBar.hpp"

LaunchBar::LaunchBar(){
    Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
    set_border_width(0);
    set_decorated(false);
    set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL);
    set_position(Gtk::WIN_POS_NONE);
    move((screen->get_width()-400)/2,40);
    set_size_request(400,120);
    set_resizable(false);
    set_keep_above(true);
    grab_focus();

    //LOAD_STYLE
    Glib::RefPtr<Gtk::CssProvider> style = Gtk::CssProvider::create();
    style->load_from_data(
    "window{"
    "background: #27282B;"
    "color: #fff;"
    "margin: 0;"
    "}"
    "#searchBox{"
    "color: #fff;"
    "box-shadow: none;"
    "border-radius: 0;"
    "border: none;"
    "border-bottom: 5px solid #295266;"
    "background: rgba(0,0,0,0);"
    "font-size: 17px;"
    "}"
    ".searchResult{"
    "padding: 5px;"
    "}"
    ".searchResult.active{"
    "background: #7F8082;"
    "}"
    ".title{"
    "font-size: 17px;"
    "padding-left: 5px;"
    "}"
    ".comment{"
    "font-size: 12px;"
    "padding-left: 10px;"
    "}"
    );
    get_style_context()->add_provider_for_screen(screen,style,GTK_STYLE_PROVIDER_PRIORITY_USER);
    //END
        
    add_events(Gdk::KEY_PRESS_MASK);
    signal_key_press_event().connect(sigc::mem_fun(*this,&LaunchBar::onKeyPress),false);

    searchBox.set_name("searchBox");
    searchBox.set_size_request(400,40);
    searchBox.signal_changed().connect(sigc::mem_fun(*this,&LaunchBar::onSearch));

    add(mainGrid);
    mainGrid.attach(searchBox,0,0,1,1);
    mainGrid.attach(result,0,1,1,1);
    mainGrid.show_all();
}

LaunchBar::~LaunchBar(){
}

bool LaunchBar::onKeyPress(GdkEventKey* event){
    if(event->keyval==GDK_KEY_Up){
        result.select(-1);
        mainGrid.show_all();
    }else if(event->keyval==GDK_KEY_Down){
        result.select(1);
        mainGrid.show_all();
    }else if(event->keyval==GDK_KEY_Return){
        result.runSelected();
        hide();
    }else if(event->keyval==GDK_KEY_Escape){
        hide();
    }
    return false;
}

void LaunchBar::onSearch(){
    Glib::ustring searchTxt = searchBox.get_text();
    result.find(searchTxt);
    mainGrid.show_all();
}