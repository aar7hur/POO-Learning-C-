#include <gtk/gtk.h>
#include <string>

enum Window
{
	WINDOW_IS_BEING_CREATED,
	WINDOW_IS_BEING_SHOWN,
	WINDOW_CLOSED,
	WINDOW_ERROR,
};

/******************************************s
*
* Class used to create an user interface and
* gets user input 
*
******************************************/
class UserInterface
{
	private:
		GtkWidget *window;
		GtkWidget *button;
		GtkWidget *image;
		GtkWidget *menu_bar;
		GtkWidget *help_menu;
		GtkWidget *virtual_box;
		GtkWidget *file_menu;
		GtkWidget *menu_item;
		GtkWidget *menu;
		GtkWidget *layout;
		std::string user_input;
		enum Window window_status;
		static void destroy(GtkWidget *widget, gpointer data);
		void create_menu(void);
		void create_background_image(void);
		void display_window(void);
		static void menu_response(GtkWidget *menu_item, gpointer data);
		static void menu_event(GtkWidget *menu_event, gpointer data);
	public:
		UserInterface();
		UserInterface(int *argc, char ***argv);
		~UserInterface();
		std::string get_user_input(void);
		void run_window(void);
			
};