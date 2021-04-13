#include "LeftPanel.hpp"
#include "App.hpp"
#include "RootWindow.hpp"

LeftPanel::LeftPanel(wxPanel* parent, const uint16_t height)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(LEFT_PANEL_WIDTH, height), wxBORDER_SUNKEN)
	, parent(parent)
	, resolution_label(new wxStaticText(this, wxID_ANY, wxT("Resolution"), wxPoint(10, 10)))
	, resolution_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%llu"), DEFAULT_RESOLUTION), wxPoint(10, 30), wxSize(75, -1)))
	, threshold_label(new wxStaticText(this, wxID_ANY, wxT("Threshold"), wxPoint(10, 60)))
	, threshold_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%f"), DEFAULT_THRESHOLD), wxPoint(10, 80), wxSize(75, -1)))
	, max_iterations_label(new wxStaticText(this, wxID_ANY, wxT("Max Iterations"), wxPoint(10, 110)))
	, max_iterations_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%llu"), DEFAULT_MAX_ITERATIONS), wxPoint(10, 130), wxSize(75, -1)))
	, set_button(new wxButton(this, ID_SET, wxT("Set"), wxPoint(10, 160), wxSize(75, -1)))
{
	Connect(ID_SET, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnSetParameters));
}

void LeftPanel::OnSetParameters(wxCommandEvent&)
{
	uint64_t resolution = wxAtoi(resolution_input->GetValue());
	double threshold = wxAtof(threshold_input->GetValue());
	uint64_t max_iterations = wxAtoi(max_iterations_input->GetValue());

	RootWindow* rw = (RootWindow *) parent->GetParent();
	rw->setParameters(resolution, threshold, max_iterations);
}