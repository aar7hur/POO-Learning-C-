/**** TODO
 * --> CREATE METHODS TO HANDLE WITH USER INPUT.
 * --> CREATE EVENTS FOR INTERFACE MENUS
 * 
 * */


#include "UserInterface.h"
#include <cstring>
#define NDEBUG
#include <cassert>

/******************************************s
*
* Constructor used to instantiate private variables
* in userInterface class
*
******************************************/
UserInterface::UserInterface(int *argc, char ***argv)
{
    gtk_init(argc, argv);
	this->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    this->layout = gtk_layout_new(NULL, NULL);
    this->virtual_box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
	this->button = gtk_button_new_with_label("Start ");
	this->image =  gtk_image_new_from_file("/home/arthur/Downloads/StockMarket.jpg");
	this->menu = gtk_menu_new();
    this->menu_bar = gtk_menu_bar_new();
    this->help_menu = gtk_menu_item_new_with_label("Help");
    this->file_menu = gtk_menu_item_new_with_label("File");
    
}

UserInterface::UserInterface(){}
UserInterface::~UserInterface(){}
/******************************************
*
* Method used to destroy UserInterface Object and 
* also close the window
*
******************************************/
void UserInterface::destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit ();
}

void UserInterface::create_menu()
{
	const char* file[] = {"New","Check","Exit"};
    const char* help[] = {"About"};
    for(int i=0;i<3;i++)
    {
        this->menu_item = gtk_menu_item_new_with_label(file[i]);
        gtk_menu_shell_append(GTK_MENU_SHELL(this->menu),this->menu_item);
        g_signal_connect(this->menu_item,"activate",G_CALLBACK(menu_event),this->window);
    }
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(this->file_menu),this->menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(this->menu_bar),this->file_menu);
    
    this->menu_item=gtk_menu_item_new_with_label(help[0]);
    gtk_menu_shell_append(GTK_MENU_SHELL(this->menu), this->menu_item);
    g_signal_connect(this->menu_item,"activate",G_CALLBACK(this->menu_event),window);
    
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(this->menu_item), this->help_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(this->menu_bar), this->menu_item);
    gtk_box_pack_start(GTK_BOX(this->virtual_box),this->menu_bar,0,0,0);
    
    gtk_layout_put(GTK_LAYOUT(this->layout), this->virtual_box, 0, 0);
    this->window_status = WINDOW_IS_BEING_CREATED;

}

void UserInterface::display_window()
{
    try
    {
        gtk_window_set_title(GTK_WINDOW(this->window),"Stock Trading Robot");
        gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
        gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
        gtk_widget_show_all(this->window);
        gtk_main();
        this->window_status = WINDOW_IS_BEING_SHOWN;
    }
    catch(...)
    {
        this->window_status = WINDOW_ERROR;
    }
}

void UserInterface::create_background_image()
{
    try
    {
        layout = gtk_layout_new(NULL, NULL);c
        gtk_container_add(GTK_CONTAINER (this->window), layout);
        gtk_widget_show(layout);
        gtk_layout_put(GTK_LAYOUT(layout), this->image, 0, 0);
        this->window_status = WINDOW_IS_BEING_CREATED;  
    }
    catch(...)
    {
        this->window_status = WINDOW_ERROR;
    }
}
void UserInterface::run_window(void)
{   
    this->create_background_image();
    assert (this->window_status == WINDOW_IS_BEING_CREATED);
    this->create_menu();
    assert (this->window_status == WINDOW_IS_BEING_CREATED);
    this->display_window();
    assert (this->window_status.value == WINDOW_IS_BEING_SHOWN);
}

void UserInterface::menu_response(GtkWidget *menu_item, gpointer data)
{
    if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "Exit") == 0)
    {
        g_print("Exiting...");
    }
    if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "About") == 0)
    {
        g_print("About...");
    }
}

void UserInterface::menu_event(GtkWidget *menu_event, gpointer data){}