#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct menuItem {
  string name;
  string category;
  int price;
};

vector<menuItem> menuVector;

void loadMenu() {
  // ----- HOT DRINKS -----
  menuVector.push_back({"Espresso", "HOT", 70000});
  menuVector.push_back({"Cappuccino", "HOT", 110000});
  menuVector.push_back({"Latte", "HOT", 130000});
  menuVector.push_back({"Chai Tea", "HOT", 60000});

  // ----- COLD DRINKS -----
  menuVector.push_back({"Iced Coffee", "COLD", 130000});
  menuVector.push_back({"Cold Brew", "COLD", 140000});
  menuVector.push_back({"Orange Juice", "COLD", 90000});

  // ----- FOOD -----
  menuVector.push_back({"Croissant", "FOOD", 85000});
  menuVector.push_back({"Donut", "FOOD", 70000});
  menuVector.push_back({"Sandwich", "FOOD", 160000});
  menuVector.push_back({"Cake Slice", "FOOD", 95000});

  // ----- EXTRAS -----
  menuVector.push_back({"Extra Shot", "EXTRA", 40000});
  menuVector.push_back({"Oat Milk", "EXTRA", 25000});
  menuVector.push_back({"Vanilla Syrup", "EXTRA", 15000});
}

void displayCafeMenu() {
  system("clear");

  cout << "===============================================\n";
  cout << "\t LOS POLLOS HERMANOS CAFE MENU \t\n";
  cout << "\t     all prices in Toman\n";
  cout << "===============================================\n\n";

  for (int i = 0; i < menuVector.size(); i++) {
    cout << i + 1 << ".   " << menuVector[i].name
         << " ........................... " << menuVector[i].price << endl;
  }

  cout << "===============================================\n\n";

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
  loadMenu();

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
