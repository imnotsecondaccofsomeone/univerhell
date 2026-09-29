#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct contact {
  string firstName;
  string lastName;
  int phone = 0;
} tell;

int menu() {
  system("clear");
  int userChoice;

  cout << "==========================\n";
  cout << "\t PHONEBOOK \t\n";
  cout << "==========================\n";
  cout << "1. Add new contact..." << endl;
  cout << "2. Search contact..." << endl;
  cout << "3. Display all contact..." << endl;
  cout << "4. Delete contact..." << endl;
  cout << "5. Edit contact..." << endl;
  cout << "6. Exit..." << endl;
  cout << "----------------------------\n";
  cout << "Your choice: ";
  cin >> userChoice;

  return userChoice;
}

void addContact() {
  system("clear");
  ofstream writeContact("contacts.txt", ios::app);

  cout << "NEW CONTAT UWU \n";
  cout << "6767676767676767676767676767676767676767 \n";

  cin.get();

  cout << "first name: ";
  getline(cin, tell.firstName);
  writeContact << tell.firstName << endl;

  cout << "last name: ";
  getline(cin, tell.lastName);
  writeContact << tell.lastName << endl;

  cout << "phone number: ";
  cin >> tell.phone;
  writeContact << tell.phone << endl;

  cout << "Added Successfuly \n";

  writeContact.close();

  cin.get();
}

void displayContacts() {
  ifstream readContacts("contacts.txt");
  system("clear");
  cout << left << setw(20) << "first name" << setw(20) << "last name"
       << setw(20) << "phone" << endl;
  cout << "==========================================================\n";

  while (!readContacts.eof()) {
    getline(readContacts, tell.firstName);
    getline(readContacts, tell.lastName);
    readContacts >> tell.phone;

    if (readContacts.eof()) {
      break;
    }

    cout << left << setw(20) << tell.firstName << setw(20) << tell.lastName
         << setw(20) << tell.phone << endl;

    readContacts.get();
  }

  cout << "press enter to continue...";

  cin.get();
  cin.get();
}

void searchContacts() {
  system("clear");
  int userSearchChoice;

  cout << "search via what? \n";
  cout << "1. first name... \n";
  cout << "2. last name... \n";
  cout << "3. phone number... \n";
  cout << "4. quit... \n";
  cin >> userSearchChoice;

  while (userSearchChoice < 1 || userSearchChoice > 4) {
    system("clear");
    cout << "you need to enter number 1-4\n";
    cout << "try again 1 to 4\n";
    cin >> userSearchChoice;
  }

  if (userSearchChoice == 4) {
    return;
  }

  ifstream readContacts("contacts.txt");
  string firstNameInput;
  string lastNameInput;
  int phoneInput;

  switch (userSearchChoice) {
  case 1: {
    system("clear");
    cout << "enter first name...";
    cin >> firstNameInput;

    while (!readContacts.eof()) {
      getline(readContacts, tell.firstName);
      getline(readContacts, tell.lastName);
      readContacts >> tell.phone;

      if (readContacts.eof()) {
        break;
      }

      if (tell.firstName == firstNameInput) {
        cout << left << setw(20) << tell.firstName << setw(20) << tell.lastName
             << setw(20) << tell.phone << endl;
      }

      readContacts.get();
    }

    readContacts.close();
    cout << "\npress enter to continue...";
    cin.get();
    cin.get();
    break;
  }

  case 2: {
    system("clear");
    cout << "enter last name...";
    cin >> lastNameInput;

    while (!readContacts.eof()) {
      getline(readContacts, tell.firstName);
      getline(readContacts, tell.lastName);
      readContacts >> tell.phone;

      if (readContacts.eof()) {
        break;
      }

      if (tell.lastName == lastNameInput) {
        cout << left << setw(20) << tell.firstName << setw(20) << tell.lastName
             << setw(20) << tell.phone << endl;
      }

      readContacts.get();
    }

    readContacts.close();
    cout << "\npress enter to continue...";
    cin.get();
    cin.get();
    break;
  }

  case 3: {
    system("clear");
    cout << "enter phone number...";
    cin >> phoneInput;

    while (!readContacts.eof()) {
      getline(readContacts, tell.firstName);
      getline(readContacts, tell.lastName);
      readContacts >> tell.phone;

      if (readContacts.eof()) {
        break;
      }

      if (tell.phone == phoneInput) {
        cout << left << setw(20) << tell.firstName << setw(20) << tell.lastName
             << setw(20) << tell.phone << endl;
      }

      readContacts.get();
    }

    readContacts.close();
    cout << "\npress enter to continue...";
    cin.get();
    cin.get();
    break;
  }
  }
}

void deleteContact() {
  system("clear");
  ifstream readContacts("contacts.txt");

  cout << left << setw(20) << "first name" << setw(20) << "last name"
       << setw(20) << "phone" << endl;
  cout << "==========================================================\n";

  while (!readContacts.eof()) {
    getline(readContacts, tell.firstName);
    getline(readContacts, tell.lastName);
    readContacts >> tell.phone;

    if (readContacts.eof()) {
      break;
    }

    cout << left << setw(20) << tell.firstName << setw(20) << tell.lastName
         << setw(20) << tell.phone << endl;

    readContacts.get();
  }

  string firstNameInputForDelete;
  cout << "===========================\n";
  cout << "enter first name you want to delete... \n";
  cout << "===========================\n";
  cin >> firstNameInputForDelete;

  ofstream createTempDataBase("temp.txt");

  readContacts.close();
  readContacts.open("contacts.txt");

  while (!readContacts.eof()) {
    getline(readContacts, tell.firstName);
    getline(readContacts, tell.lastName);
    readContacts >> tell.phone;

    if (readContacts.eof()) {
      break;
    }

    if (tell.firstName != firstNameInputForDelete) {
      createTempDataBase << tell.firstName << endl;
      createTempDataBase << tell.lastName << endl;
      createTempDataBase << tell.phone << endl;
    }

    readContacts.get();
  }

  readContacts.close();
  createTempDataBase.close();

  remove("contacts.txt");

  rename("temp.txt", "contacts.txt");

  cout << "\nContact deleted!\n";
  cout << "press enter to continue...";
  cin.get();
  cin.get();
}

int main() {
  int z;
  while (true) {
    z = menu();

    switch (z) {
    case 1:
      addContact();
      break;
    case 2:
      searchContacts();
      break;
    case 3:
      displayContacts();
      break;
    case 4:
      deleteContact();
      break;
    case 5:
      break;
    case 6:
      return 0;
      break;
    default:
      system("clear");
      cout << "try 1-6 again";
      break;
    }
  }
}
