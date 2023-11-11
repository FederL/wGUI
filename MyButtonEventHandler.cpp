#include "MyButtonEventHandler.h"

MyButtonEventHandler::MyButtonEventHandler(wxButton* m_btn, const wxColour& defaultColor, const wxColour& clickColor)
    : m_btn(m_btn), defaultColor(defaultColor), clickColor(clickColor) {
    m_btn->Bind(wxEVT_LEFT_DOWN, &MyButtonEventHandler::OnMouseDown, this);
    m_btn->Bind(wxEVT_LEFT_UP, &MyButtonEventHandler::OnMouseUp, this);
}

void MyButtonEventHandler::OnMouseDown(wxMouseEvent& event) {
    m_btn->SetBackgroundColour(clickColor);
    m_btn->Refresh();
}

void MyButtonEventHandler::OnMouseUp(wxMouseEvent& event) {
    m_btn->SetBackgroundColour(defaultColor);
    m_btn->Refresh();
}
