/***************************************************************
 * Name:      TimerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alex K ()
 * Created:   2022-04-27
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#ifndef TIMERMAIN_H
#define TIMERMAIN_H

//(*Headers(TimerFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/timer.h>
//*)

class TimerFrame: public wxFrame
{
    public:

        TimerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~TimerFrame();

    private:

        //(*Handlers(TimerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        //*)

        //(*Identifiers(TimerFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(TimerFrame)
        wxStatusBar* StatusBar1;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TIMERMAIN_H
