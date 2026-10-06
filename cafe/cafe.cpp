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

struct cartItems {
  int itemNumber;
  int quantity;
};

vector<menuItem> menuVector;
vector<cartItems> cart;

void loadMenu() {
  // ----- HOT DRINKS -----
  menuVector.push_back({"Espresso", "HOT", 3});
  menuVector.push_back({"Cappuccino", "HOT", 4});
  menuVector.push_back({"Latte", "HOT", 5});
  menuVector.push_back({"Chai Tea", "HOT", 3});

  // ----- COLD DRINKS -----
  menuVector.push_back({"Iced Coffee", "COLD", 5});
  menuVector.push_back({"Cold Brew", "COLD", 5});
  menuVector.push_back({"Orange Juice", "COLD", 4});

  // ----- FOOD -----
  menuVector.push_back({"Croissant", "FOOD", 3});
  menuVector.push_back({"Donut", "FOOD", 3});
  menuVector.push_back({"Sandwich", "FOOD", 7});
  menuVector.push_back({"Cake Slice", "FOOD", 4});

  // ----- EXTRAS -----
  menuVector.push_back({"Extra Shot", "EXTRA", 2});
  menuVector.push_back({"Oat Milk", "EXTRA", 1});
  menuVector.push_back({"Vanilla Syrup", "EXTRA", 1});
}

void displayCafeMenu() {
  system("clear");

  cout << "===============================================\n";
  cout << "\t LOS POLLOS HERMANOS CAFE MENU \t\n";
  cout << "===============================================\n\n";

  for (int i = 0; i < menuVector.size(); i++) {
    cout << i + 1 << ".   " << menuVector[i].name
         << " ........................... " << menuVector[i].price << "$"
         << endl;
  }

  cout << "===============================================\n\n";

  cout << "\nPress enter to continue...";
  cin.get();
}

int chooseOrder() {
  system("clear");

  cout << "===============================================\n";
  cout << "\t LOS POLLOS HERMANOS CAFE MENU \t\n";
  cout << "===============================================\n\n";

  for (int i = 0; i < menuVector.size(); i++) {
    cout << i + 1 << ".   " << menuVector[i].name
         << " ........................... " << menuVector[i].price << "$"
         << endl;
  }

  cout << "===============================================\n\n";

  int indexNumber;
  cout << "choose your number to want add into cart: ";
  cin >> indexNumber;

  if (indexNumber < 1 || indexNumber > menuVector.size()) {
    system("clear");
    cin.get();
    cout << "no suck item! \nPress enter to continue...";
    cin.get();
    return 0;
  }

  int quantity;
  cout << "how many? ";
  cin >> quantity;
  cin.get();

  cart.push_back({indexNumber - 1, quantity});

  int total = 0;
  cout << "\n+---------------------------------+\n";
  cout << "|              Cart               |\n";
  cout << "+---------------------------------+\n";

  for (int i = 0; i < cart.size(); i++) {
    int n = cart[i].itemNumber;
    int lineTotal = menuVector[n].price * cart[i].quantity;
    cout << cart[i].quantity << " x " << menuVector[n].name << " ............ "
         << lineTotal << "$" << endl;

    total = total + lineTotal;
  }

  cout << "Total ................... " << total << "$" << endl;

  cout << "press enter to continue...";
  cin.get();

  return 0;
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
      chooseOrder();
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
