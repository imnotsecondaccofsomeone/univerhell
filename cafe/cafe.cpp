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

void displayCafeMenu() {
  system("clear");
  cout << "===============================================\n";
  cout << "\t LOS POLLOS HERMANOS CAFE MENU \t\n";
  cout << "\t     all prices in Toman\n";
  cout << "===============================================\n";

  cout << "\n-- HOT DRINKS --\n";
  cout << "1.  Espresso ............. 70,000\n";
  cout << "2.  Cappuccino ........... 110,000\n";
  cout << "3.  Latte ................ 120,000\n";
  cout << "4.  Chai Tea ............. 60,000\n";

  cout << "\n-- COLD DRINKS --\n";
  cout << "5.  Iced Coffee .......... 130,000\n";
  cout << "6.  Cold Brew ............ 140,000\n";
  cout << "7.  Orange Juice.......... 90,000\n";

  cout << "\n-- FOOD --\n";
  cout << "8.  Croissant ............ 85,000\n";
  cout << "9.  Donut ................ 70,000\n";
  cout << "10. Sandwich ............. 160,000\n";
  cout << "11. Cake Slice ........... 95,000\n";

  cout << "\n-- EXTRAS --\n";
  cout << "12. Extra Shot ........... 40,000\n";
  cout << "13. Oat Milk ............. 25,000\n";
  cout << "14. Vanilla Syrup ........ 15,000\n";

  cout << "\n==============================\n";

  cout << "\nPress enter to continue...";
  cin.get();
}

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
      displayCafeMenu();
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
