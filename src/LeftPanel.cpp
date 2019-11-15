#include "LeftPanel.hpp"
#include "App.hpp"
#include "RootWindow.hpp"

LeftPanel::LeftPanel(wxPanel* parent, const uint16_t height)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(LEFT_PANEL_WIDTH, height), wxBORDER_SUNKEN)
	, parent(parent)
	, resolution_label(new wxStaticText(this, wxID_ANY, wxT("Resolution"), wxPoint(10, 10)))
	, resolution_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%llu"), DEFAULT_RESOLUTION), wxPoint(10, 30), wxSize(75, -1)))
	, real_label(new wxStaticText(this, wxID_ANY, wxT("Center Real"), wxPoint(10, 60)))
	, real_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%f"), DEFAULT_CENTER.real()), wxPoint(10, 80), wxSize(75, -1)))
	, imaginary_label(new wxStaticText(this, wxID_ANY, wxT("Center Imaginary"), wxPoint(10, 110)))
	, imaginary_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%f"), DEFAULT_CENTER.imag()), wxPoint(10, 130), wxSize(75, -1)))
	, scale_label(new wxStaticText(this, wxID_ANY, wxT("Scale"), wxPoint(10, 160)))
	, scale_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%f"), DEFAULT_SCALE), wxPoint(10, 180), wxSize(75, -1)))
	, threshold_label(new wxStaticText(this, wxID_ANY, wxT("Threshold"), wxPoint(10, 210)))
	, threshold_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%f"), DEFAULT_THRESHOLD), wxPoint(10, 230), wxSize(75, -1)))
	, max_iterations_label(new wxStaticText(this, wxID_ANY, wxT("Max Iterations"), wxPoint(10, 260)))
	, max_iterations_input(new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%llu"), DEFAULT_MAX_ITERATIONS), wxPoint(10, 280), wxSize(75, -1)))
	, set_button(new wxButton(this, ID_SET, wxT("Set"), wxPoint(10, 320), wxSize(75, -1)))
{
	Connect(ID_SET, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnSetParameters));
}

void LeftPanel::OnSetParameters(wxCommandEvent& event)
{
	double threshold = wxAtof(threshold_input->GetValue());
	uint64_t max_iterations = wxAtoi(max_iterations_input->GetValue());
	std::complex<double> center { wxAtof(real_input->GetValue()), wxAtof(imaginary_input->GetValue()) };
	double scale = wxAtof(scale_input->GetValue());
	uint64_t resolution = wxAtoi(resolution_input->GetValue());

	RootWindow* rw = (RootWindow *) parent->GetParent();
	rw->setParameters(threshold, max_iterations, center, scale, resolution);
}