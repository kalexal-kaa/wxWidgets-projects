/***************************************************************
 * Name:      CalculatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Alex K ()
 * Created:   2022-04-26
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#include "CalculatorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(CalculatorFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(CalculatorFrame)
const long CalculatorFrame::ID_TEXTCTRL1 = wxNewId();
const long CalculatorFrame::ID_BUTTON1 = wxNewId();
const long CalculatorFrame::ID_BUTTON2 = wxNewId();
const long CalculatorFrame::ID_TEXTCTRL2 = wxNewId();
const long CalculatorFrame::ID_STATICTEXT1 = wxNewId();
const long CalculatorFrame::ID_MENUITEM1 = wxNewId();
const long CalculatorFrame::idMenuAbout = wxNewId();
const long CalculatorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CalculatorFrame,wxFrame)
    //(*EventTable(CalculatorFrame)
    //*)
END_EVENT_TABLE()

CalculatorFrame::CalculatorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(CalculatorFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(400,350));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(40,24), wxSize(152,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("clean"), wxPoint(32,248), wxSize(336,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont Button1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    Button2 = new wxButton(this, ID_BUTTON2, _("calculate"), wxPoint(32,208), wxSize(336,27), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont Button2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(216,24), wxSize(152,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxPoint(40,80), wxSize(320,96), 0, _T("ID_STATICTEXT1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton2Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CalculatorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CalculatorFrame::OnAbout);
    //*)
}

CalculatorFrame::~CalculatorFrame()
{
    //(*Destroy(CalculatorFrame)
    //*)
}

void CalculatorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CalculatorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

wxString fast, last, Res1, Res2, Res3, Res4;
int Operand1, Operand2;
float Answer1, Answer2, Answer3, Answer4;

void CalculatorFrame::OnButton1Click(wxCommandEvent& event)
{
   StaticText1->SetLabel("");
}

void CalculatorFrame::OnButton2Click(wxCommandEvent& event)
{
    if(TextCtrl1->IsEmpty()){
        wxMessageBox("Enter correct values in first fields","");
        TextCtrl1->SetFocus();
        return;
    }
    if(TextCtrl2->IsEmpty()){
        wxMessageBox("Enter correct values in second fields","");
        TextCtrl2->SetFocus();
        return;
    }
    fast = TextCtrl1->GetValue();
    last = TextCtrl2->GetValue();
    Operand1 = wxAtoi(fast);
    Operand2 = wxAtoi(last);
    Answer1 = float(Operand1) + float(Operand2);
    Res1 = wxString::Format(wxT("%g"),Answer1);
    Answer2 = float(Operand1) - float(Operand2);
    Res2 = wxString::Format(wxT("%g"),Answer2);
    Answer3 = float(Operand1) * float(Operand2);
    Res3 = wxString::Format(wxT("%g"),Answer3);
    Answer4 = float(Operand1) / float(Operand2);
    Res4 = wxString::Format(wxT("%g"),Answer4);
    StaticText1->SetLabel(wxT("сумма: ")+Res1+wxT("\nразность: ")+Res2+wxT("\nпроизведение: ")+Res3+wxT("\nчастное: ")+Res4);
}
