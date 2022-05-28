/***************************************************************
 * Name:      Color_PickerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Alex K ()
 * Created:   2022-04-26
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#include "Color_PickerApp.h"

//(*AppHeaders
#include "Color_PickerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Color_PickerApp);

bool Color_PickerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Color_PickerFrame* Frame = new Color_PickerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
