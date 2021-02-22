#pragma once
#include <gtkmm-3.0/gtkmm.h>
#include "ResultWindow.hpp"

class LaunchBar : public Gtk::Window{

public:
    LaunchBar();
    ~LaunchBar();

private:
    Gtk::Grid mainGrid;
    Gtk::Entry searchBox;
    ResultWindow result;

    bool onKeyPress(GdkEventKey* event);
    void onSearch();
};