#pragma once

#include <wx/wx.h>

const int ID_SET = 100;

class LeftPanel : public wxPanel
{
public:
	LeftPanel(wxPanel* parent, const uint16_t height);

private:
	wxPanel* parent;

	wxStaticText* resolution_label;
	wxTextCtrl* resolution_input;

	wxStaticText* threshold_label;
	wxTextCtrl* threshold_input;

	wxStaticText* max_iterations_label;
	wxTextCtrl* max_iterations_input;

	wxButton* set_button;

	void OnSetParameters(wxCommandEvent& event);
};

