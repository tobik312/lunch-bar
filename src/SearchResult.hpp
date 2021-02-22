#pragma once
#include <giomm-2.4/giomm.h>
#include <gtkmm-3.0/gtkmm.h>

class SearchResult: public Gtk::Grid{

public:

    SearchResult(Glib::RefPtr<Gio::AppInfo> application);
    ~SearchResult();

    void select(bool isSelected);
    void run();

private:
    Glib::RefPtr<Gio::AppInfo> appToRun;

    Glib::RefPtr<Gdk::Pixbuf> iconImage;
    Gtk::Label title;
    Gtk::Label comment;
    Gtk::Image icon;

    void loadImage();
};