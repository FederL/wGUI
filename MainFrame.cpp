#include "MainFrame.h"
#include "MyButtonEventHandler.h"
#include "MyButton.h"
#include <wx/wx.h>

wxBEGIN_EVENT_TABLE(MyButton, wxButton)
EVT_PAINT(MyButton::OnPaint)
EVT_SIZE(MyButton::OnSize)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition) {
    /* main frame */
    wxPanel* panel = new wxPanel(this);

    /* button */
    wxFont font(10, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    MyButton* m_btn = new MyButton(panel, wxID_ANY, "cmd", wxPoint(18, 20), wxDefaultSize,
        wxColour(136, 77, 255), wxColour(255, 255, 255), font);

    /* events */
    MyButtonEventHandler* buttonEventHandler = new MyButtonEventHandler(m_btn, wxColour(136, 77, 255), wxColour(156, 97, 255));
    m_btn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

    /* sizer for the main frame */
    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);

    /* left frame */
    wxPanel* leftPanel = new wxPanel(panel, wxID_ANY);
    leftPanel->SetBackgroundColour(wxColour(140, 140, 140));
    mainSizer->Add(leftPanel, 1, wxEXPAND);

    /* right frame */
    wxPanel* rightPanel = new wxPanel(panel, wxID_ANY);
    rightPanel->SetBackgroundColour(wxColour(180, 180, 180));
    mainSizer->Add(rightPanel, 6, wxEXPAND);

    panel->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);
    Show(true);
}

void MainFrame::OnButtonClicked(wxCommandEvent& event) {
    wxString cmd = wxT("cmd /K cd C:\\Users\\baran");
    wxExecute(cmd, wxEXEC_ASYNC);
    event.Skip();

}