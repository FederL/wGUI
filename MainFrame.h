#pragma once

#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title); 
private:
	void OnButtonClicked(wxCommandEvent& event);
};

#endif // MAINFRAME_H