/***************************************************************
 * Name:      HotelGuestBookingGuiMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dylan Matheson (dmathsdev@gmail.com)
 * Created:   2023-11-26
 * Copyright: Dylan Matheson ()
 * License:
 **************************************************************/
using namespace std;

#include "HotelGuestBookingGuiMain.h"
#include <wx/msgdlg.h>
#include "AddGuestDiag.h"
#include <fstream>
//(*InternalHeaders(HotelGuestBookingGuiDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)



//helper functions
enum wxbuildinfoformat {
    short_f, long_f };


wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(HotelGuestBookingGuiDialog)
const long HotelGuestBookingGuiDialog::ID_SPLITTERWINDOW1 = wxNewId();
const long HotelGuestBookingGuiDialog::ID_BUTTON1 = wxNewId();
const long HotelGuestBookingGuiDialog::ID_BUTTON2 = wxNewId();
const long HotelGuestBookingGuiDialog::ID_BUTTON3 = wxNewId();
const long HotelGuestBookingGuiDialog::ID_LISTBOX1 = wxNewId();
//*)

class ClientData_c {

  public: string objectName = "client data container object";

  string firstName {};
  string lastName {};
  string phoneNumber {};
  string roomNumber {};
  int guestIdNumber {};
};
wxVector < ClientData_c > ClientData_v; //Top level to cut down on complexity

ClientData_c CreateGuest(bool createFromFile) {
  ClientData_c ClientData_i;

  cout << "\n-------------------------------------------------------------------------------------\n";

  cout << "\nPlease Enter First Name:\n" << endl;
  cin >> ClientData_i.firstName;
  cout << "\nPlease Enter Last Name:\n" << endl;
  cin >> ClientData_i.lastName;
  cout << "\nGenerateing Guest ID...." << endl;
  cout << "\nPlease Enter Phone Number:\n" << endl;
  cin >> ClientData_i.phoneNumber;
  cout << "\n-------------------------------------------------------------------------------------\n";
  ClientData_i.guestIdNumber = rand();
  cout << ClientData_i.firstName << ClientData_i.lastName << ClientData_i.guestIdNumber << ClientData_i.phoneNumber << endl;

  return (ClientData_i);
}


BEGIN_EVENT_TABLE(HotelGuestBookingGuiDialog,wxDialog)
    //(*EventTable(HotelGuestBookingGuiDialog)
    //*)
END_EVENT_TABLE()

HotelGuestBookingGuiDialog::HotelGuestBookingGuiDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(HotelGuestBookingGuiDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxGridSizer* buttonHolderGridSizer;

    Create(parent, wxID_ANY, _("Hotel Guest Booking"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    buttonPadderSplitterWindow = new wxSplitterWindow(this, ID_SPLITTERWINDOW1, wxDefaultPosition, wxDefaultSize, wxSP_3D, _T("ID_SPLITTERWINDOW1"));
    buttonPadderSplitterWindow->SetMinimumPaneSize(10);
    buttonPadderSplitterWindow->SetSashGravity(0.5);
    FlexGridSizer1->Add(buttonPadderSplitterWindow, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    buttonHolderGridSizer = new wxGridSizer(3, 1, 0, 0);
    viewGuestsButton = new wxButton(this, ID_BUTTON1, _("View Guests"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    buttonHolderGridSizer->Add(viewGuestsButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    addGuestsButton = new wxButton(this, ID_BUTTON2, _("Add Guest"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    buttonHolderGridSizer->Add(addGuestsButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    quitButton = new wxButton(this, ID_BUTTON3, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    buttonHolderGridSizer->Add(quitButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(buttonHolderGridSizer, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    outputGuestListBox = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(465,386), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    outputGuestListBox->Append(_("test"));
    FlexGridSizer1->Add(outputGuestListBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HotelGuestBookingGuiDialog::OnviewGuestsButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HotelGuestBookingGuiDialog::OnaddGuestsButtonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HotelGuestBookingGuiDialog::OnQuit);
    //*)
}

HotelGuestBookingGuiDialog::~HotelGuestBookingGuiDialog()
{
    //(*Destroy(HotelGuestBookingGuiDialog)
    //*)
}

void HotelGuestBookingGuiDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void HotelGuestBookingGuiDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void HotelGuestBookingGuiDialog::OnviewGuestsButtonClick(wxCommandEvent& event)
{

ifstream readGuestbook;



readGuestbook.open("guestBook.csv", ios::in);
string GuestDataOutputString;
string firstName;
string lastName;
string phoneNumber;
string passerString;
char seperator = ',';
std::string stringFromStream;
string stringForOutput;
int numLines;
outputGuestListBox->Clear();
while (getline(readGuestbook, stringForOutput, ';') )

{


        GuestDataOutputString = stringForOutput;

        outputGuestListBox->Append(_(GuestDataOutputString));
}
stringForOutput = "";


}

void HotelGuestBookingGuiDialog::OnaddGuestsButtonClick(wxCommandEvent& event)
{
    AddGuestDiag* dlg = new AddGuestDiag(this);

    if (dlg->ShowModal() == wxID_OK)
    {
//do your stuff here
    }

  dlg->Destroy();
}
