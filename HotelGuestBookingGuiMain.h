/***************************************************************
 * Name:      HotelGuestBookingGuiMain.h
 * Purpose:   Defines Application Frame
 * Author:    Dylan Matheson (dmathsdev@gmail.com)
 * Created:   2023-11-26
 * Copyright: Dylan Matheson ()
 * License:
 **************************************************************/

#ifndef HOTELGUESTBOOKINGGUIMAIN_H
#define HOTELGUESTBOOKINGGUIMAIN_H


//(*Headers(HotelGuestBookingGuiDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
//*)

class HotelGuestBookingGuiDialog: public wxDialog
{
    public:

        HotelGuestBookingGuiDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~HotelGuestBookingGuiDialog();

    private:

        //(*Handlers(HotelGuestBookingGuiDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnviewGuestsButtonClick(wxCommandEvent& event);
        void OnaddGuestsButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(HotelGuestBookingGuiDialog)
        static const long ID_SPLITTERWINDOW1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_LISTBOX1;
        //*)

        //(*Declarations(HotelGuestBookingGuiDialog)
        wxButton* addGuestsButton;
        wxButton* quitButton;
        wxButton* viewGuestsButton;
        wxListBox* outputGuestListBox;
        wxSplitterWindow* buttonPadderSplitterWindow;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HOTELGUESTBOOKINGGUIMAIN_H
