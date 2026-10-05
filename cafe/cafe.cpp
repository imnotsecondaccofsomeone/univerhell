#include <iostream>
using namespace std;
int menu() {
  system("clear");
  int customerChoice;
  cout << "================================\n";
  cout << "Hello and welcome to the Los Pollos Hermanos cafe. My name is "
          "Gustavo, but you can call me Gus. \n";
  cout << "================================\n";

  cout << "1. Add new contact..." << endl;
  cout << "2. Search contact..." << endl;
  cout << "3. Display all contact..." << endl;
  cout << "4. Delete contact..." << endl;
  cout << "5. Edit contact..." << endl;
  cout << "6. Exit..." << endl;

  cout << "\n==============================\n";
  cout << "please enter number between 1-6...";
  cin >> customerChoice;
  cin.get();

  return customerChoice;
}

int main() {
  int z;
  while (true) {
    z = menu();

    switch (z) {
    case 1:
      menu();
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
      return 0;
      break;
    default:
      system("clear");
      cout << "please try again between 1-6...";
      cin.get();
      break;
    }
  }
  return 0;
}
