#ifndef ADDGUESTDIAG_H
#define ADDGUESTDIAG_H

//(*Headers(AddGuestDiag)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
//*)

class AddGuestDiag: public wxDialog
{
	public:

		AddGuestDiag(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AddGuestDiag();

		//(*Declarations(AddGuestDiag)
		wxButton* BackToMainMenuButton;
		wxButton* OkAddButton;
		wxListBox* GuestTitleListBox;
		wxTextCtrl* FirstNameTextC;
		wxTextCtrl* LastNAmeTextC;
		wxTextCtrl* PhoneNumTextCntrl;
		//*)

	protected:

		//(*Identifiers(AddGuestDiag)
		static const long ID_GUESTTITLELISTBOX1;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(AddGuestDiag)
		void OnRadioBox1Select(wxCommandEvent& event);
		void OnBackToMainMenuButtonClick(wxCommandEvent& event);
		void OnOkAddButtonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
