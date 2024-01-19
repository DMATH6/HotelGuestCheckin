/***************************************************************
 * Name:      HotelGuestBookingGuiApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Dylan Matheson (dmathsdev@gmail.com)
 * Created:   2023-11-26
 * Copyright: Dylan Matheson ()
 * License:
 **************************************************************/

#include "HotelGuestBookingGuiApp.h"
//#include "Functions.h"
//(*AppHeaders
#include "HotelGuestBookingGuiMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(HotelGuestBookingGuiApp);

bool HotelGuestBookingGuiApp::OnInit()
{
    //ReadWriteGuestDataFile(true);
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	HotelGuestBookingGuiDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
