// MyButtonEventHandler.cpp
#include "MyButtonEventHandler.h"

BEGIN_EVENT_TABLE(MyButtonEventHandler, wxEvtHandler)
EVT_LEFT_DOWN(MyButtonEventHandler::OnMouseDown)
EVT_LEFT_UP(MyButtonEventHandler::OnMouseUp)
END_EVENT_TABLE()

MyButtonEventHandler::MyButtonEventHandler(wxButton* m_btn, const wxColour& defaultColor, const wxColour& clickColor)
    : m_btn(m_btn), defaultColor(defaultColor), clickColor(clickColor) {
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
