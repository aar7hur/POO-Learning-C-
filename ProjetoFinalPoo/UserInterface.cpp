#include "UserInterface.h"

/******************************************
*
* Constructor used to instantiate private variables
* in userInterface class
*
******************************************/
UserInterface::UserInterface()
{
	this->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	this->button = gtk_button_new_with_label("Start ");
	this->image =  gtk_image_new_from_file("C:\Users\amaralA\Pictures/Stock-Market-2")
	this->menu_bar = gtk_menu_bar_new();
    this->help_menu = gtk_menu_new();
    this->file_menu = gtk_menu_new();
    this->virtual_box = gtk_vbox_new(0,0);
}

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
	
 	menu_item = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), this->file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(this->menu_bar), menu_item);
 
    menu_item = gtk_menu_item_new_with_label("Help");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), this->help_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(this->menu_bar), menu_item);
 
    menu_item = gtk_menu_item_new_with_label("Exit");
    gtk_menu_shell_append(GTK_MENU_SHELL(this->file_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);
 
    menu_item = gtk_menu_item_new_with_label("About");
    gtk_menu_shell_append(GTK_MENU_SHELL(this->help_menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(menu_response), NULL);
 
    gtk_box_pack_start(GTK_BOX(this->vbox), this->menu_bar,0,0,0);
    gtk_box_pack_start(GTK_BOX(this->vbox), this->button,0,0,0);
 
    gtk_container_add(GTK_CONTAINER(this->window), this->vbox);
 
}

Window UserInterface::display_window()
{
	gtk_widget_set_size_request(window, 300, 300);
    gtk_window_set_title(GTK_WINDOW(window),"Stock Tradind Robot");
    gtk_widget_show_all(window);
    gtk_main();
}

Window UserInterface::create_background_image()
{
	gtk_container_add(GTK_CONTAINER(this->window), this->image);
}

Window UserInterface::run_window(&Window)
{
	this->display_window();
}
