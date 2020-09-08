#include <gtk/gtk.h>
#include <string>

enum Window
{
	WINDOW_IS_BEING_CREATED,
	WINDOW_IS_BEING_SHOWN;
	WINDOW_CLOSED;
}

/******************************************
*
* Class used to create an user interface and
* gets user input 
*
******************************************/
Class UserInterface:
	private:
		GtkWidget *window;
		GtkWidget *button;
		GtkWidget *image;
		GtkWidget *menu_bar;
		GtkWidget *help_menu;
		GtkWidget *virtual_box;
		GtkWidget *file_menu;
		std::string user_input;
		static void destroy(GtkWidget *widget, gpointer data);
		Window create_menu(void);
		Window create_background_image(void);
		Window display_window(void);
	public:
		UserInterface();
		std::string get_user_input()
		Window run_window(&Window);	
