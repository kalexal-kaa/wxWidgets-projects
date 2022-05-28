/***************************************************************
 * Name:      Color_PickerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Alex K ()
 * Created:   2022-04-26
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#include "Color_PickerMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Color_PickerFrame)
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

//(*IdInit(Color_PickerFrame)
const long Color_PickerFrame::ID_SLIDER1 = wxNewId();
const long Color_PickerFrame::ID_SLIDER2 = wxNewId();
const long Color_PickerFrame::ID_SLIDER3 = wxNewId();
const long Color_PickerFrame::ID_PANEL1 = wxNewId();
const long Color_PickerFrame::ID_STATICTEXT1 = wxNewId();
const long Color_PickerFrame::ID_STATICTEXT2 = wxNewId();
const long Color_PickerFrame::ID_STATICTEXT3 = wxNewId();
const long Color_PickerFrame::ID_TEXTCTRL1 = wxNewId();
const long Color_PickerFrame::ID_TEXTCTRL2 = wxNewId();
const long Color_PickerFrame::ID_TEXTCTRL3 = wxNewId();
const long Color_PickerFrame::ID_TEXTCTRL4 = wxNewId();
const long Color_PickerFrame::ID_STATICTEXT4 = wxNewId();
const long Color_PickerFrame::ID_STATICTEXT5 = wxNewId();
const long Color_PickerFrame::ID_STATICTEXT6 = wxNewId();
const long Color_PickerFrame::ID_STATICTEXT7 = wxNewId();
const long Color_PickerFrame::idMenuQuit = wxNewId();
const long Color_PickerFrame::idMenuAbout = wxNewId();
const long Color_PickerFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Color_PickerFrame,wxFrame)
    //(*EventTable(Color_PickerFrame)
    //*)
END_EVENT_TABLE()

Color_PickerFrame::Color_PickerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Color_PickerFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(416,252));
    Slider1 = new wxSlider(this, ID_SLIDER1, 0, 0, 100, wxPoint(48,48), wxSize(136,18), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    Slider2 = new wxSlider(this, ID_SLIDER2, 0, 0, 100, wxPoint(48,88), wxSize(136,18), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    Slider3 = new wxSlider(this, ID_SLIDER3, 0, 0, 100, wxPoint(48,128), wxSize(136,18), 0, wxDefaultValidator, _T("ID_SLIDER3"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(232,24), wxSize(144,136), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(0,0,0));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("R"), wxPoint(32,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(227,21,21));
    wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("G"), wxPoint(32,88), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText2->SetForegroundColour(wxColour(22,232,27));
    wxFont StaticText2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("B"), wxPoint(32,128), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText3->SetForegroundColour(wxColour(20,41,239));
    wxFont StaticText3Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(16,216), wxSize(88,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(120,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(216,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(312,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("R value:"), wxPoint(16,200), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("G value:"), wxPoint(120,200), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("B value:"), wxPoint(216,200), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Hex value:"), wxPoint(312,200), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
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

    Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Color_PickerFrame::OnSlider1CmdScrollChanged);
    Connect(ID_SLIDER2,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Color_PickerFrame::OnSlider2CmdScrollChanged);
    Connect(ID_SLIDER3,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Color_PickerFrame::OnSlider3CmdScrollChanged);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Color_PickerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Color_PickerFrame::OnAbout);
    //*)
}

Color_PickerFrame::~Color_PickerFrame()
{
    //(*Destroy(Color_PickerFrame)
    //*)
}

void Color_PickerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Color_PickerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

int Rpos, Gpos, Bpos;
wxColor *color;

void Color_PickerFrame::OnSlider1CmdScrollChanged(wxScrollEvent& event)
{
    Rpos = Slider1->GetValue();
    TextCtrl1->Refresh();
    TextCtrl1->SetValue(wxString::Format("%d",Rpos));
    Panel1->SetBackgroundColour(wxColor(Rpos,Gpos,Bpos));
    Refresh();
    TextCtrl4->Refresh();
    TextCtrl4->SetValue(wxString::Format("%X %X %X",Rpos,Gpos,Bpos));
}

void Color_PickerFrame::OnSlider2CmdScrollChanged(wxScrollEvent& event)
{
    Gpos = Slider2->GetValue();
    TextCtrl2->Refresh();
    TextCtrl2->SetValue(wxString::Format("%d",Gpos));
    Panel1->SetBackgroundColour(wxColor(Rpos,Gpos,Bpos));
    Refresh();
    TextCtrl4->Refresh();
    TextCtrl4->SetValue(wxString::Format("%X %X %X",Rpos,Gpos,Bpos));
}

void Color_PickerFrame::OnSlider3CmdScrollChanged(wxScrollEvent& event)
{
    Bpos = Slider3->GetValue();
    TextCtrl3->Refresh();
    TextCtrl3->SetValue(wxString::Format("%d",Bpos));
    Panel1->SetBackgroundColour(wxColor(Rpos,Gpos,Bpos));
    Refresh();
    TextCtrl4->Refresh();
    TextCtrl4->SetValue(wxString::Format("%X %X %X",Rpos,Gpos,Bpos));
}
