/***************************************************************
 * Name:      TimerApp.h
 * Purpose:   Defines Application Class
 * Author:    Alex K ()
 * Created:   2022-04-27
 * Copyright: Alex K ()
 * License:
 **************************************************************/

#ifndef TIMERAPP_H
#define TIMERAPP_H

#include <wx/app.h>

class TimerApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // TIMERAPP_H
