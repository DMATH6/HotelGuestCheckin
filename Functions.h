//Written by Dylan Matheson, 2023
//THis program is a flat file database that keeps track of guests in an hotel

/* FUNCTIONS INCLUDED ARE
-auto CreateGuest() 'Creates a row that stores guest data, uses ClientData_i which comes from ClientData_c. Outputs ClientData_i
-void ReadWriteGuestDataFile(bool writeData) 'Multi part function that can read data and write to a file'
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>



using namespace std;

class ClientData_c {

  public: string objectName = "client data container object";

  string firstName {};
  string lastName {};
  string phoneNumber {};
  string roomNumber {};
  int guestIdNumber {};
};
extern vector < ClientData_c > ClientData_v; //Top level to cut down on complexity


using namespace std;

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

inline auto ReadWriteGuestDataFile(bool writeData) {
  char separator = ',';
  fstream outGuestbook;
  outGuestbook.open("guestBook.csv", ios::app);

  if (writeData == true) {

    cout << "\n-------------------------------------------------------------------------------------\n";
    outGuestbook << ClientData_v[0].firstName << "," << ClientData_v[0].lastName << "," << ClientData_v[0].guestIdNumber << "," << ClientData_v[0].phoneNumber << "/" << endl;
    cout << "\n-------------------------------------------------------------------------------------\n";
    outGuestbook.close();

  } else {
    fstream readGuestbook;
    readGuestbook.open("guestBook.csv", ios::in);
    if (readGuestbook.is_open()) {
      string firstName = {};
      string lastName = {};
      string guestId = {};
      string phoneNumber = {};
      string dataBuffer {};
      string endOfLine {};

      int maxLineNumber {};
      cout << "Please enter the max amount of rows you want to display" << endl;
      cin >> maxLineNumber;
      for (int i {}; i < maxLineNumber; i++) {
        ClientData_c ClientData_i;

        // Read data from the file object and put it into a string.
        getline(readGuestbook, firstName, ',');
        getline(readGuestbook, lastName, ',');
        getline(readGuestbook, guestId, ',');
        getline(readGuestbook, phoneNumber, '/');
        //getline(readGuestbook, endOfLine, '/');
        endOfLine = " ";

        //put this data into an object
        ClientData_i.firstName = firstName;
        ClientData_i.lastName = lastName;
        ClientData_i.guestIdNumber = stoi(guestId);
        ClientData_i.phoneNumber = phoneNumber;

        ClientData_v.push_back(ClientData_i);

        //abort(getline(readGuestbook, dataBuffer, '/'));

      }
      readGuestbook.close();
      //prints out all data from objects client_v
      /*for (int i {}; i < ClientData_v.size(); i++) {
        cout << ClientData_v[i].firstName << "  " << ClientData_v[i].lastName << "  " << ClientData_v[i].guestIdNumber << "  " << ClientData_v[i].phoneNumber << endl;
      }*/
    }

  }
return (ClientData_v);
}

/*void MainLoop() {

  int options {};
  cout << "\n==============================================================\n";
  cout << "Welcome To Hotel Booking\n\n" << "1 To Add A Guest\n\n" << "3 To View All Guests\n\n";
  cin >> options;

  switch (options) {
  case 1:
    //ClientData_v.push_back(CreateGuest(false));
    ReadWriteGuestDataFile(true);
    ClientData_v.clear();
    MainLoop();
    break;
  case 2: //Not used
    break;
  case 3: //Not used

    ReadWriteGuestDataFile(false);
    ClientData_v.clear();
    MainLoop();
    break;

  }
}

int mainConsole() {

  MainLoop();
  return 0;
} */


