/***************************************************************
 * Name:      QRCode_GeneratorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alex K ()
 * Created:   2022-04-26
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#ifndef QRCODE_GENERATORMAIN_H
#define QRCODE_GENERATORMAIN_H

//(*Headers(QRCode_GeneratorFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class QRCode_GeneratorFrame: public wxFrame
{
    public:

        QRCode_GeneratorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~QRCode_GeneratorFrame();

    private:

        //(*Handlers(QRCode_GeneratorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(QRCode_GeneratorFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(QRCode_GeneratorFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // QRCODE_GENERATORMAIN_H
