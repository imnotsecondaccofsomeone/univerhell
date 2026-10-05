#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct cardInfoStruc {
  string f_name;
  string l_name;
  int c_amount;
} card;

int menu() {
  system("clear");
  int customerChoice;
  cout << "================================\n";
  cout << "Hello and welcome to the Los Pollos Hermanos cafe. My name is "
          "Gustavo, but you can call me Gus. \n";
  cout << "================================\n";

  cout << "1. Menu... " << endl;
  cout << "2. Order..." << endl;
  cout << "3. Wait list..." << endl;
  cout << "4. Change your order..." << endl;
  cout << "5. Abort your order..." << endl;
  cout << "6. Exit..." << endl;

  cout << "\nplease choose your option between 1-6: ";
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
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
              "!!!!\n";
      cout << "                       CHOOSE BETWEEN 1-6\n";
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
              "!!!!\n";
      cout << "                    Press enter to continue...\n";
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
              "!!!!\n";
      cin.get();
      break;
    }
  }
  return 0;
}
