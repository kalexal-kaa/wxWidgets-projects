/***************************************************************
 * Name:      TimerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Alex K ()
 * Created:   2022-04-27
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#include "TimerMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(TimerFrame)
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

//(*IdInit(TimerFrame)
const long TimerFrame::ID_STATICTEXT1 = wxNewId();
const long TimerFrame::ID_STATICTEXT2 = wxNewId();
const long TimerFrame::ID_STATICTEXT3 = wxNewId();
const long TimerFrame::ID_BUTTON1 = wxNewId();
const long TimerFrame::ID_BUTTON2 = wxNewId();
const long TimerFrame::ID_BUTTON3 = wxNewId();
const long TimerFrame::idMenuQuit = wxNewId();
const long TimerFrame::idMenuAbout = wxNewId();
const long TimerFrame::ID_STATUSBAR1 = wxNewId();
const long TimerFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TimerFrame,wxFrame)
    //(*EventTable(TimerFrame)
    //*)
END_EVENT_TABLE()

TimerFrame::TimerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(TimerFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,251));
    SetBackgroundColour(wxColour(123,213,132));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("00"), wxPoint(88,104), wxSize(33,40), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(22,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("00"), wxPoint(184,104), wxSize(32,48), 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(22,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("00"), wxPoint(280,104), wxSize(15,48), 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(22,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    Button1 = new wxButton(this, ID_BUTTON1, _("start"), wxPoint(56,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("stop"), wxPoint(160,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("reset"), wxPoint(272,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
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
    Timer1.SetOwner(this, ID_TIMER1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TimerFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TimerFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TimerFrame::OnButton3Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TimerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TimerFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&TimerFrame::OnTimer1Trigger);
    //*)
}

TimerFrame::~TimerFrame()
{
    //(*Destroy(TimerFrame)
    //*)
}

void TimerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void TimerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void TimerFrame::OnButton1Click(wxCommandEvent& event)
{
    Timer1.Start();
}

void TimerFrame::OnButton2Click(wxCommandEvent& event)
{
    Timer1.Stop();
}

void TimerFrame::OnButton3Click(wxCommandEvent& event)
{
    Timer1.Stop();
    StaticText1->SetLabel("00");
    StaticText2->SetLabel("00");
    StaticText3->SetLabel("00");
}

void TimerFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    long milli = 0;
    long sec = 0;
    long minute = 0;
    wxString milliString = StaticText1->GetLabel();
    milliString.ToLong(&milli);
    wxString secString = StaticText2->GetLabel();
    secString.ToLong(&sec);
    wxString minuteString = StaticText3->GetLabel();
    minuteString.ToLong(&minute);

    milli++;
    if(milli>=100){
        milli = 0;
        sec+1;
        sec++;
    }
    if(sec>59){
        sec = 0;
        minute+1;
        minute++;
    }

    wxString Output1 = wxString::Format(wxT("%ld"),milli);
    wxString Output2 = wxString::Format(wxT("%ld"),sec);
    wxString Output3 = wxString::Format(wxT("%ld"),minute);

    StaticText1->SetLabel(Output1);
    StaticText2->SetLabel(Output2);
    StaticText3->SetLabel(Output3);
}
