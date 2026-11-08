#include <iostream>
using namespace std;

class Rational {
  private:
    int num;
    int den;

  public:
    Rational(int n = 0, int d = 1) {
      if (d == 0) {
        cout << "Denominator can't be 0, using 1 instead.\n";
        d = 1;
      }
      num = n;
      den = d;
    }

    // ---- read from user ----
    void input() {
      cout << "soorat (numerator):   ";
      cin >> num;
      cout << "makhraj (denominator): ";
      cin >> den;
      if (den == 0) {
        cout << "Denominator can't be 0, using 1 instead.\n";
        den = 1;
      }
    }

    // ---- arithmetic ----
    Rational add(const Rational& o) const {
      return Rational(num * o.den + o.num * den, den * o.den);
    }
    Rational subtract(const Rational& o) const {
      return Rational(num * o.den - o.num * den, den * o.den);
    }
    Rational multiply(const Rational& o) const {
      return Rational(num * o.num, den * o.den);
    }
    Rational divide(const Rational& o) const {
      return Rational(num * o.den, den * o.num);
    }

    // ---- printing ----
    void printFraction() const { cout << num << "/" << den << endl; }
    void printDecimal()  const { cout << (double)num / den << endl; }
};

int menu() {
  system("clear");   // Windows: system("cls")
  cout << "===== Rational Calculator =====\n";
  cout << "1. enter first fraction  (a)\n";
  cout << "2. enter second fraction (b)\n";
  cout << "3. a + b\n";
  cout << "4. a - b\n";
  cout << "5. a * b\n";
  cout << "6. a / b\n";
  cout << "7. print a and b as fractions\n";
  cout << "8. print a and b as decimals\n";
  cout << "9. exit\n";
  cout << "your option is: ";

  int c;
  cin >> c;
  return c;
}

int main() {
  Rational a, b;          // both default to 0/1
  int choice;

  while (true) {
    choice = menu();
    switch (choice) {

      case 1:
        system("clear");
        cout << "--- first fraction (a) ---\n";
        a.input();
        cout << "press enter to continue...";
        cin.get(); cin.get();
        break;

      case 2:
        system("clear");
        cout << "--- second fraction (b) ---\n";
        b.input();
        cout << "press enter to continue...";
        cin.get(); cin.get();
        break;

      case 3: {
                system("clear");
                cout << "a + b = ";
                a.add(b).printFraction();
                cout << "      = ";
                a.add(b).printDecimal();
                cout << "press enter to continue...";
                cin.get(); cin.get();
                break;
              }

      case 4: {
                system("clear");
                cout << "a - b = ";
                a.subtract(b).printFraction();
                cout << "      = ";
                a.subtract(b).printDecimal();
                cout << "press enter to continue...";
                cin.get(); cin.get();
                break;
              }

      case 5: {
                system("clear");
                cout << "a * b = ";
                a.multiply(b).printFraction();
                cout << "      = ";
                a.multiply(b).printDecimal();
                cout << "press enter to continue...";
                cin.get(); cin.get();
                break;
              }

      case 6: {
                system("clear");
                cout << "a / b = ";
                a.divide(b).printFraction();
                cout << "      = ";
                a.divide(b).printDecimal();
                cout << "press enter to continue...";
                cin.get(); cin.get();
                break;
              }

      case 7:
              system("clear");
              cout << "a = "; a.printFraction();
              cout << "b = "; b.printFraction();
              cout << "press enter to continue...";
              cin.get(); cin.get();
              break;

      case 8:
              system("clear");
              cout << "a = "; a.printDecimal();
              cout << "b = "; b.printDecimal();
              cout << "press enter to continue...";
              cin.get(); cin.get();
              break;

      case 9:
              return 0;

      default:
              system("clear");
              cout << "you need to put number between 1-9.\n";
              cout << "press enter to continue...";
              cin.get(); cin.get();
              break;
    }
  }
  return 0;
}
