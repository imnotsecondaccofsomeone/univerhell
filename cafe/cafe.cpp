#include <iostream>
using namespace std;

int menu() {
  system("clear");
  int customerChoice;
  cout << "================================\n";
  cout << "Hello and welcome to the Los Pollos Hermanos cafe. My name is "
          "Gustavo, but you can call me Gus. \n";
  cout << "================================\n";

  cout << "1. Your card info..." << endl;
  cout << "2. Menu... " << endl;
  cout << "3. Order..." << endl;
  cout << "4. Wait list..." << endl;
  cout << "5. Employee only..." << endl;
  cout << "6. Exit..." << endl;

  cout << "\n please enter number between 1-6: ";
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
      cout << "press enter to continue and choose between 1-6";
      cin.get();
      break;
    }
  }
  return 0;
}
