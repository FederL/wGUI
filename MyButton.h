#pragma once
#include <wx/wx.h>

class MyButton : public wxButton {
public:
    MyButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size,
        const wxColour& bgCol, const wxColour& fgCol, const wxFont& font)
        : wxButton(parent, id, label, pos, size, wxBORDER_NONE) {
        SetBackgroundColour(bgCol);
        SetForegroundColour(fgCol);
        SetFont(font);
    }

    void OnPaint(wxPaintEvent& event) {
        wxPaintDC dc(this);
        Render(dc);
    }

    void OnSize(wxSizeEvent& event) {
        Refresh();
        event.Skip();
    }

private:
    void Render(wxDC& dc) {
        wxSize size = GetClientSize();
        wxRect rect(wxPoint(0, 0), size);

        dc.SetBrush(wxBrush(GetBackgroundColour()));
        dc.SetPen(*wxTRANSPARENT_PEN);

        dc.DrawRoundedRectangle(rect, 5); // Adjust the radius as needed for the desired smoothness
        dc.DrawLabel(GetLabel(), rect, wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL);
    }

    wxDECLARE_EVENT_TABLE();
};
