#include <iostream>
using namespace std; 

class Date {
  public:
    Date(int m = 1, int d = 1, int y = 2000) {
      setYear(y);
      setMonth(m);
      setDay(d);
    }

    void setYear(int y){
      if (y >= 1 && y <= 9999) {
        year = y;
      } else {
        cout << "Invalid year, we set year the default 2000, press enter to continue...";
        cin.get();
        year = 2000;
      }
    }

    void setMonth(int m){
      if (m >= 1 && m <= 12) {
        month = m;
      } else {
        cout << "Invalid month, we set month the default 1, press enter to continue...";
        cin.get();
        month = 1;
      }
    }

    void setDay(int d){
      if (d >= 1 && d <= 30) {
        day = d;
      } else {
        cout << "Invalid day, we set day the default 1, press enter to continue...";
        cin.get();
        day = 1;
      }
    }

    void printDate(){
      cout << year << "/" << month << "/" << day;
    }

  private:
    int year;
    int month;
    int day;
};

int menu(){
  system("clear");
  //  printDate();
  cout << "enter your option.\n";
  cout << "1. print date\n";
  cout << "2. change day\n";
  cout << "3. change month\n";
  cout << "4. change year\n";
  cout << "5. exit\n";

  int userChoice;

  cout << "your option is: ";
  cin >> userChoice;
  return userChoice;
}

int main (){
  int z;
  Date d;
  while (true) {
    z = menu();
    switch (z) {
      case 1:
        system("clear");
        cin.get();
        d.printDate();
        cin.get();
        break;
      case 2:
        system("clear");
        cout << "change day to: ";
        int dayInput;
        cin >> dayInput;
        cin.get();
        d.setDay(dayInput);
        break;
      case 3:
        system("clear");
        cout << "change month to: ";
        int monthInput;
        cin >> monthInput;
        cin.get();
        d.setMonth(monthInput);
        break;
      case 4:
        system("clear");
        cout << "change year to: ";
        int yearInput;
        cin >> yearInput;
        cin.get();
        d.setYear(yearInput);
        break;
      case 5:
        exit(0);
        break;
      default:
        system("clear");
        cout << "you need to put number between 1-5.\n enter to continue... ";
        cin.get();
        cin.get();

        break;
    }

  }
  return 0;
}
