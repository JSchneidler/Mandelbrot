#include "LeftPanel.h"
#include <inttypes.h>
#include "App.h"
#include "RootWindow.h"

LeftPanel::LeftPanel(wxPanel* parent, const uint16_t height)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(100, height), wxBORDER_SUNKEN)
	, parent(parent)
	, resolution_label(new wxStaticText(this, wxID_ANY, wxT("Resolution"), wxPoint(10, 10)))
	, resolution_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%hu"), DEFAULT_RESOLUTION), wxPoint(10, 30), wxSize(75, -1)))
	, c_label(new wxStaticText(this, wxID_ANY, wxT("C Value"), wxPoint(10, 60)))
	, c_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%llu"), DEFAULT_C), wxPoint(10, 80), wxSize(75, -1)))
	, set_button(new wxButton(this, ID_SET, wxT("Set"), wxPoint(10, 130), wxSize(75, -1)))
{
	Connect(ID_SET, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnSetParameters));
}

void LeftPanel::OnSetParameters(wxCommandEvent& event)
{
	uint16_t resolution = wxAtoi(resolution_input->GetValue());
	uint64_t c = wxAtoi(c_input->GetValue());

	RootWindow* rw = (RootWindow *) parent->GetParent();
	rw->setParameters(resolution, c);
}