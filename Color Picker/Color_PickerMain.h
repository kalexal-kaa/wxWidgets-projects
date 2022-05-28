/***************************************************************
 * Name:      Color_PickerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alex K ()
 * Created:   2022-04-26
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#ifndef COLOR_PICKERMAIN_H
#define COLOR_PICKERMAIN_H

//(*Headers(Color_PickerFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class Color_PickerFrame: public wxFrame
{
    public:

        Color_PickerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Color_PickerFrame();

    private:

        //(*Handlers(Color_PickerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSlider1CmdScrollChanged(wxScrollEvent& event);
        void OnSlider2CmdScrollChanged(wxScrollEvent& event);
        void OnSlider3CmdScrollChanged(wxScrollEvent& event);
        //*)

        //(*Identifiers(Color_PickerFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Color_PickerFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // COLOR_PICKERMAIN_H
