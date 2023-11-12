// MyButtonEventHandler.h
#pragma once
#include <wx/wx.h>

class MyButtonEventHandler : public wxEvtHandler {
public:
    MyButtonEventHandler(wxButton* m_btn, const wxColour& defaultColor, const wxColour& clickColor);

private:
    void OnMouseDown(wxMouseEvent& event);
    void OnMouseUp(wxMouseEvent& event);

    wxButton* m_btn;
    wxColour defaultColor;
    wxColour clickColor;

    wxDECLARE_EVENT_TABLE();
};
