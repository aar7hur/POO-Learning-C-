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
    // initiate gtk application
    gtk_init(argc, argv);
    
    // if user clicks on 'x' the application will destroy
    // and closed the window
	this->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(this->window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
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
    g_signal_connect(this->menu_item,"activate", G_CALLBACK(menu_event),this->window);
    
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
        gtk_window_set_default_size(GTK_WINDOW(this->window), 600, 400);
        gtk_window_set_position(GTK_WINDOW(this->window), GTK_WIN_POS_CENTER);
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
        this->layout = gtk_layout_new(NULL, NULL);
        gtk_container_add(GTK_CONTAINER (this->window), this->layout);
        gtk_widget_show(this->layout);
        gtk_layout_put(GTK_LAYOUT(this->layout), this->image, 0, 0);
        this->window_status = WINDOW_IS_BEING_CREATED;  
    }
    catch(...)
    {
        this->window_status = WINDOW_ERROR;
    }
}

void UserInterface::create_user_entry()
{
    
    this->table = gtk_grid_new();
    gtk_layout_put(GTK_LAYOUT(this->layout), this->table, 0, 0);

    //create a text box 
    this->entry_action = gtk_entry_new();
    gtk_grid_attach (GTK_GRID (this->table), this->entry_action, 0, 0, 1, 1);

    // create a new label.
    this->label_action = gtk_label_new (" Qual ação deseja avaliar " );
    gtk_grid_attach (GTK_GRID (this->table), this->label_action, 1, 0, 1, 1);

    //create a text box 
    this->entry_money = gtk_entry_new ();
    gtk_grid_attach (GTK_GRID (this->table), this->entry_money, 0, 1, 1, 1);

    // create a new label.
    this->label_money = gtk_label_new ("Qual ação deseja avaliar");
    gtk_grid_attach (GTK_GRID (this->table), this->label_money, 1, 1, 1, 1);


    this->button = gtk_button_new_with_label("Run");
    g_signal_connect(this->button, "clicked", G_CALLBACK(entry_submit), this->entry_money);
    
    gtk_grid_attach (GTK_GRID (this->table), this->button, 0, 3, 2, 1);
 
}


void UserInterface::run_window(void)
{   
    this->create_background_image();
    assert (this->window_status == WINDOW_IS_BEING_CREATED);
    this->create_menu();
    assert (this->window_status == WINDOW_IS_BEING_CREATED);
    this->create_user_entry();
    this->display_window();
    assert (this->window_status.value == WINDOW_IS_BEING_SHOWN);
}


void UserInterface::menu_event(GtkWidget *menu_item, gpointer data)
{
    if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "Exit") == 0)
    {
        g_print("Exiting...");
        gtk_main_quit();
    }
    if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)), "About") == 0)
    {
        g_print("About...");
    }
}

void UserInterface::entry_submit(GtkWidget* button_clicked, gpointer data)
{
   
    g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(data)));
    gtk_editable_select_region(GTK_EDITABLE(data), 0,-1); // text from 0 to the end
    gtk_editable_copy_clipboard(GTK_EDITABLE(data));
    
}