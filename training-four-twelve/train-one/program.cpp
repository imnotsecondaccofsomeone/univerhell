#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Account {
  public:

    Account(int initial) {
      if(initial < 0 ) {
        balance = 0;

      } else {
        balance = initial;
      }
    } 
    void credit(int param) {
      balance = balance + param;
    }
    void debit(int param) {
      if(param >= balance) {
        cout << "you are not that reach bro."; 
        cin.get();
        return;
      }

      balance = balance - param;
    }
    int getBalance() {
      return balance;
    }

  private:
    int balance;
};

int menu() {
  int userChoice;
  system("clear");

  cout << "choose option...\n";
  cout << "1. get balance\n";
  cout << "2. add money\n";
  cout << "3. remove money\n";
  cout << "4. exit\n";
  cout << "You choice is: ";

  cin >> userChoice;
  return userChoice;
}

int main() {
  system("clear");
  int initial;
  cout << "enter you balance: ";
  cin >> initial;

  Account userAcc(initial);
  if (userAcc.getBalance() <= 0) {
    cout << "Error, your balance could not be negative, system set your balance 0.";
    cout << "\npress enter to continue..";
    cin.get();
    cin.get();
  }

  int z;
  while(true) {
    z = menu();
    switch (z) {
      case 1: 
        system("clear");
        cout << "Your balance is: " << userAcc.getBalance();
        cin.get();
        cout << "\npress enter to continue...";
        cin.get();
        break; 
      case 2: 
        system("clear");
        cin.get();

        int moneyToAdd;
        cout << "Enter money you liked to add: ";
        cin >> moneyToAdd;

        userAcc.credit(moneyToAdd);
        cin.get();
        break; 
      case 3: 
        system("clear");
        cin.get();

        int moneyToRemove;
        cout << "Enter money you liked to remove: ";
        cin >> moneyToRemove;

        userAcc.debit(moneyToRemove);
        cin.get();
        break; 
      case 4: 
        system("clear");
        exit(0);
        break; 
    }  
  }
  return 0;
}
