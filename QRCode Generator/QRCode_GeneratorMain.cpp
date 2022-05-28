/***************************************************************
 * Name:      QRCode_GeneratorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Alex K ()
 * Created:   2022-04-26
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#include "QRCode_GeneratorMain.h"
#include <wx/msgdlg.h>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "qrcodegen.hpp"



using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

//(*InternalHeaders(QRCode_GeneratorFrame)
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

//(*IdInit(QRCode_GeneratorFrame)
const long QRCode_GeneratorFrame::ID_STATICTEXT1 = wxNewId();
const long QRCode_GeneratorFrame::ID_TEXTCTRL1 = wxNewId();
const long QRCode_GeneratorFrame::ID_STATICBITMAP1 = wxNewId();
const long QRCode_GeneratorFrame::ID_BUTTON1 = wxNewId();
const long QRCode_GeneratorFrame::ID_TEXTCTRL2 = wxNewId();
const long QRCode_GeneratorFrame::idMenuQuit = wxNewId();
const long QRCode_GeneratorFrame::idMenuAbout = wxNewId();
const long QRCode_GeneratorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(QRCode_GeneratorFrame,wxFrame)
    //(*EventTable(QRCode_GeneratorFrame)
    //*)
END_EVENT_TABLE()

QRCode_GeneratorFrame::QRCode_GeneratorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(QRCode_GeneratorFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(400,248));
    SetBackgroundColour(wxColour(200,178,140));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("save file name:"), wxPoint(40,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    txtSavedfilename = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(40,24), wxSize(320,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxPoint(232,64), wxSize(128,128), 0, _T("ID_STATICBITMAP1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("generate"), wxPoint(160,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    txtData = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(40,64), wxSize(128,128), wxTE_MULTILINE|wxTE_WORDWRAP, wxDefaultValidator, _T("ID_TEXTCTRL2"));
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&QRCode_GeneratorFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&QRCode_GeneratorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&QRCode_GeneratorFrame::OnAbout);
    //*)
}

QRCode_GeneratorFrame::~QRCode_GeneratorFrame()
{
    //(*Destroy(QRCode_GeneratorFrame)
    //*)
}

void QRCode_GeneratorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void QRCode_GeneratorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void QRCode_GeneratorFrame::OnButton1Click(wxCommandEvent& event)
{
    const char *text = txtData->GetValue();
    const QrCode::Ecc errCorLvl = QrCode::Ecc::LOW;
    const QrCode qr = QrCode::encodeText(text, errCorLvl);
    const int scale = 10;
    const int size = qr.getSize() * scale;
    const int byteWidth = (size + 7) / 8;
    char bitsChar[size * byteWidth];
    for(int y=0; y<size;y++){
        for(int xByte=0;xByte<byteWidth;xByte++){
            char bitChar = 0x00;
            if(!txtData->IsEmpty()) {
                for(int xBit=0;xBit<8;xBit++){
                    int x = xByte * 8 + xBit;
                    int xModule = x / scale;
                    int yModule = y / scale;
                    bool black = qr.getModule(xModule, yModule);
                    bitChar += black << (xBit % 8);
                }
            }
            bitsChar[y * byteWidth + xByte] = bitChar;
        }
    }
    wxBitmap *bitmap = new wxBitmap(bitsChar, size, size, 1);
    bitmap->SaveFile(txtSavedfilename->GetValue() + ".png", wxBITMAP_TYPE_PNG, NULL);

    wxImage img = bitmap->ConvertToImage();
    wxBitmap bm = wxBitmap(img.Scale(120, 120, wxIMAGE_QUALITY_NORMAL));
    StaticBitmap1->SetBitmap(bm);
}
