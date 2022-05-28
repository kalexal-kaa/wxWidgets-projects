/***************************************************************
 * Name:      QRCode_GeneratorApp.h
 * Purpose:   Defines Application Class
 * Author:    Alex K ()
 * Created:   2022-04-26
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#ifndef QRCODE_GENERATORAPP_H
#define QRCODE_GENERATORAPP_H

#include <wx/app.h>

class QRCode_GeneratorApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // QRCODE_GENERATORAPP_H
