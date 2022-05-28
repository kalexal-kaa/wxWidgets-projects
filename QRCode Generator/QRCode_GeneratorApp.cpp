/***************************************************************
 * Name:      QRCode_GeneratorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Alex K ()
 * Created:   2022-04-26
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#include "QRCode_GeneratorApp.h"

//(*AppHeaders
#include "QRCode_GeneratorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(QRCode_GeneratorApp);

bool QRCode_GeneratorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	QRCode_GeneratorFrame* Frame = new QRCode_GeneratorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
