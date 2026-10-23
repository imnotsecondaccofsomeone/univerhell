# include <iostream>
# include <fstream>
# include <vector>
# include <string>
using namespace std;

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

int main(){
  int z;

  while(true){
    z = menu();
    switch(z){
      case 1:
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
        cout << "Good Bye...";
        cin.get();
        cin.get();
        exit(0);
        break;
      default:
        system("clear");
        cout << "please enter 1-6...";
        cin.get();
        cin.get();
    }
  }

  return 0;
}
