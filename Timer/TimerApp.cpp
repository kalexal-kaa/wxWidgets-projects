/***************************************************************
 * Name:      TimerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Alex K ()
 * Created:   2022-04-27
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#include "TimerApp.h"

//(*AppHeaders
#include "TimerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(TimerApp);

bool TimerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	TimerFrame* Frame = new TimerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
