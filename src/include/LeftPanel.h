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
	wxStaticText* c_label;
	wxTextCtrl* c_input;
	wxButton* set_button;

	void OnSetParameters(wxCommandEvent& event);
};

