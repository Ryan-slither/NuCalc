#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    wxString name = "Big Calculator Time";
    MainFrame* mainFrame = new MainFrame(name);
    mainFrame->SetClientSize(400, 600);
    mainFrame->Center();
    mainFrame->Show();

    return true;
}