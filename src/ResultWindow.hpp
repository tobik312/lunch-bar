#pragma once
#include <giomm-2.4/giomm.h>
#include <gtkmm-3.0/gtkmm.h>

#include "SearchResult.hpp"

//TODO
//Load most open app sorting

class ResultWindow : public Gtk::Box{

public:
    ResultWindow();
    ~ResultWindow();

    void find(Glib::ustring searchStatement);
    void select(int direction);
    void runSelected();

private:
    Glib::ustring searchTxt;
    int selectedIdx = 0;

    void init();

    std::vector<Glib::RefPtr<SearchResult>> results = {};
    void clearResults(bool hardClear = false);
    void updateResults();
};