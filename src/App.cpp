#include "App.hpp"
#include "RootWindow.hpp"

IMPLEMENT_APP(App);

bool App::OnInit()
{
	RootWindow* rw = new RootWindow();
	rw->Show(true);

	return true;
}
