#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Contact {
  string f_name;
  string l_name;
  string phone;
};

vector<Contact> contacts;

void readFile(vector<Contact>& contacts, const string& filename){
  ifstream r(filename);

  if(!r.is_open()){
    return;
  }

  Contact temp;
  while(getline(r, temp.f_name)){
    getline(r, temp.l_name);
    getline(r, temp.phone);
    contacts.push_back(temp); 
  }

  r.close();
}

void writeFile(const vector<Contact>& contacts, const string& filename){
  ofstream w(filename);

  if(!w.is_open()){
    cout << "Error: could not open file for writing!\n";
    return;
  }

  for(int i = 0; i < contacts.size(); i++){
    w << contacts[i].f_name << endl;
    w << contacts[i].l_name << endl;
    w << contacts[i].phone  << endl;
  }

  w.close();
}

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

void addPhone(vector<Contact>& contacts){
  system("clear");
  Contact newContact;

  cout << "first name: ";
  cin >> newContact.f_name;
  
  cout << "last name: ";
  cin >> newContact.l_name;

  cout << "phone number: ";
  cin >> newContact.phone;

  contacts.push_back(newContact);

  writeFile(contacts, "phonebook.txt");
  cout << "New contact added!\n";
  cin.get();
  cin.get();
}

int main(){
  int z;
  const string filename = "phonebook.txt";
  readFile(contacts, filename);

  while(true){
    z = menu();
    switch(z){
      case 1:
        addPhone(contacts);
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        system("clear");
        cout << "Good Bye\n";
        cout << "Press enter to exit...";
        cin.get();
        cin.get();
        exit(0);
        break;
      default:
        system("clear");
        cout << "press enter to get back to menu and choose number between 1-6...";
        cin.get();
        cin.get();
    }
  }

  return 0;
}
