#include "UserInterface.h"


int main()
{
	UserInterface *usr = new UserInterface;
	usr->create_menu()
	usr->create_backgroung_image();
	usr->display_window();
}
