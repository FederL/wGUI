// MyButtonEventHandler.cpp
#include "MyButtonEventHandler.h"

MyButtonEventHandler::MyButtonEventHandler(wxButton* btn, const wxColour& defaultCol, const wxColour& clickCol)
    : m_btn(btn), defaultColor(defaultCol), clickColor(clickCol) {
    m_btn->Bind(wxEVT_LEFT_DOWN, &MyButtonEventHandler::OnMouseDown, this);
    m_btn->Bind(wxEVT_LEFT_UP, &MyButtonEventHandler::OnMouseUp, this);
}

void MyButtonEventHandler::OnMouseDown(wxMouseEvent& event) {
    m_btn->SetBackgroundColour(clickColor);
    m_btn->Refresh();
    event.Skip();
}

void MyButtonEventHandler::OnMouseUp(wxMouseEvent& event) {
    m_btn->SetBackgroundColour(defaultColor);
    m_btn->Refresh();
    event.Skip();
}

wxBEGIN_EVENT_TABLE(MyButtonEventHandler, wxEvtHandler)
// Add any additional event bindings if needed
wxEND_EVENT_TABLE()
