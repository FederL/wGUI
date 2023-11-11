#pragma once

#include <wx/wx.h>

class MyButtonEventHandler : public wxEvtHandler {
public:
    MyButtonEventHandler(wxButton* m_btn, const wxColour& defaultColor, const wxColour& clickColor);

    void OnMouseDown(wxMouseEvent& event);
    void OnMouseUp(wxMouseEvent& event);

private:
    wxButton* m_btn;
    wxColour defaultColor;
    wxColour clickColor;
};
