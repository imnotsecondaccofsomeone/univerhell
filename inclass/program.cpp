#include <climits>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define FileName "Bank.txt"
using namespace std;

class Account {
  public:
    Account(string, string, int, int);
    bool credit(long long);
    bool debit(long long);
    int getbalance() const { return balance; }
    string getfirstname() const { return firstname; }
    string getlastname() const { return lastname; }
    int getAccount() const { return AccountNumber; }

  private:
    string firstname;
    string lastname;
    int AccountNumber;
    long long balance;
};

Account::Account(string f, string l, int ac, int amount=0) {
  firstname = f;
  lastname = l;
  AccountNumber = ac;

  if(amount < 0) {
    balance = 0;
    cout << "Invalid amount......." << endl;
    cin.get();
  } else {
    balance = amount;
  }
}

bool Account::credit(long long amount) {
  if (amount <= 0 || amount > LLONG_MAX - balance) {
    cout << "Invalid amount!" << endl;
    return false;
  }

  balance += amount;
  cout << "Deposit successful!" << endl;
  return true;
}

bool Account::debit(long long amount) {
  if (amount <= 0 || amount > balance) {
    cout << "Invalid amount!" << endl;
    return false;
  }

  balance -= amount;
  cout << "Withdraw successful!" << endl;
  return true;
}

void header() {
  cout << left << setw(20) << "AccountNumber" << setw(20) << "First Name"
    << setw(20) << "Last Name" << setw(20) << "Balance" << "\n";

  cout << string(70, '-') << "\n";
}

int menu() {
  int choice;
  system("clear");
  cout << "\n\n";
  cout << string(45, ' ') << "+----------------------------------+\n";
  cout << string(45, ' ') << "|               Bank               |\n";
  cout << string(45, ' ') << "+----------------------------------+\n";
  cout << string(45, ' ') << "| 1. create account                |\n";
  cout << string(45, ' ') << "| 2. show account                  |\n";
  cout << string(45, ' ') << "| 3. list accounts                 |\n";
  cout << string(45, ' ') << "| 4. deposit                       |\n";
  cout << string(45, ' ') << "| 5. withdraw                      |\n";
  cout << string(45, ' ') << "| 6. exit                          |\n";
  cout << string(45, ' ') << "+----------------------------------+\n";

  cout << string(45, ' ') << "choose: ";
  cin >> choice;
  return choice;
}

void readFile(vector<Account>& Accounts) {
  ifstream r(FileName);
  if (!r.is_open()) {
    cout << "Error opening file!" << endl;
    return;
  }

  Accounts.clear();
  string firstname, lastname;
  int AccountNumber, balance;

  while (getline(r >> ws, firstname) && getline(r, lastname) &&
      (r >> AccountNumber) && (r >> balance)) {
    Accounts.emplace_back(firstname, lastname, AccountNumber, balance);
    r.get();
  }

  r.close();
}

void writeFile(const vector<Account>& Accounts) {
  ofstream w(FileName);

  if (!w.is_open()) {
    cout << "Error opening file!\n";
    cin.get();
    return;
  }

  for (const auto& cc : Accounts) {
    w << cc.getfirstname() << "\n";
    w << cc.getlastname() << "\n";
    w << cc.getAccount() << "\n";
    w << cc.getbalance() << "\n";
  }

  cout << "\n\nThe information was written to the file correctly\n";
  // system("pause");
  cin.get();
  w.close();
}

int FindAccount(const vector<Account>& Accounts, int number) {
  for (int i = 0; i < (int)Accounts.size(); i++){
    if(Accounts[i].getAccount() == number){
      return 1;
    }
  }

  return -1;
}

void CreateAccount(vector<Account>& Accounts) {
  string firstname, lastname;
  int AccountNumber;

  cin.get();
  system("clear");

  cout << "Enter First Name: ";
  getline(cin >> ws, firstname);

  cout << "Enter last name: ";
  getline(cin, lastname);

  cout << "Enter account number: ";
  cin >> AccountNumber;

  if (FindAccount(Accounts, AccountNumber) != -1) {
    cout << "This Account Number already exists!" << endl;
    cin.get();
    cin.get();
    return;
  }

  Accounts.emplace_back(firstname, lastname, AccountNumber, 0);
  writeFile(Accounts);
  cout << "Account created successfuly!" << endl;
  cin.get();
}

int main() { 
  vector<Account> Accounts;
  readFile(Accounts);

  int z;
  while(true) {
    z = menu();
    switch (z) {
      case 1: 
        CreateAccount(Accounts);
        break;
      case 2: 
        // ShowAccount(Accounts);
        break;
      case 3: 
        // listAccounts(Accounts);
        break;
      case 4: 
        // Deposit(Accounts);
        break;
      case 5: 
        // Withdraw(Accounts);
        break;
      case 6: 
        exit(0);
        break;
      default:
        system("clear");
        cout << "Invalid choice, please choose between 1-6, now press enter to continue...";
        cin.get();
        cin.get();
        break;
    }
  }

  return 0;
}
