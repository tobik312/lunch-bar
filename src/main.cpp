#include "LaunchBar.hpp"
#include <gtkmm/application.h>

int main (int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv, "lunch-bar");
    
    LaunchBar helloworld;
    return app->run(helloworld);
}