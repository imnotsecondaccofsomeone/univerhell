#include <iostream>
using namespace std;

class Complex {
  public:
    Complex() {
      re = 0;
      im = 0;
    }

    Complex(double r, double i) {
      re = r;
      im = i;
    }

    void read() {
      cout << "  real part      : ";
      cin >> re;
      cout << "  imaginary part : ";
      cin >> im;
    }

    void display() {
      if (im < 0)
        cout << re << " - " << -im << "i";
      else
        cout << re << " + " << im << "i";
    }

    Complex add(Complex other) {
      return Complex(re + other.re, im + other.im);
    }

    Complex subtract(Complex other) {
      return Complex(re - other.re, im - other.im);
    }

    Complex multiply(Complex other) {
      double newRe = re * other.re - im * other.im;
      double newIm = re * other.im + im * other.re;
      return Complex(newRe, newIm);
    }

    Complex divide(Complex other) {
      double denom = other.re * other.re + other.im * other.im;
      if (denom == 0) {
        cout << "Error: division by zero!\n";
        return Complex(0, 0);
      }
      double newRe = (re * other.re + im * other.im) / denom;
      double newIm = (im * other.re - re * other.im) / denom;
      return Complex(newRe, newIm);
    }

  private:
    double re;
    double im;
};

int menu() {
  system("clear");           
  int userChoice;

  cout << "==========================\n";
  cout << "\t COMPLEX NUMBERS \t\n";
  cout << "==========================\n";
  cout << "1. Add" << endl;
  cout << "2. Subtract" << endl;
  cout << "3. Multiply" << endl;
  cout << "4. Divide" << endl;
  cout << "5. Enter new numbers" << endl;
  cout << "6. Exit" << endl;
  cout << "----------------------------\n";
  cout << "Your choice: ";
  cin >> userChoice;

  return userChoice;
}

int main() {
  Complex a, b;

  system("clear");
  cout << "First complex number:\n";
  a.read();
  cout << "\nSecond complex number:\n";
  b.read();

  int z;
  while (true) {
    z = menu();

    if (z == 1) {
      system("clear");
      Complex result = a.add(b);
      a.display();  cout << "  +  ";  b.display();  cout << "  =  ";
      result.display();
      cout << "\n\npress enter to continue...";
      cin.get(); cin.get();
    }
    else if (z == 2) {
      system("clear");
      Complex result = a.subtract(b);
      a.display();  cout << "  -  ";  b.display();  cout << "  =  ";
      result.display();
      cout << "\n\npress enter to continue...";
      cin.get(); cin.get();
    }
    else if (z == 3) {
      system("clear");
      Complex result = a.multiply(b);
      a.display();  cout << "  *  ";  b.display();  cout << "  =  ";
      result.display();
      cout << "\n\npress enter to continue...";
      cin.get(); cin.get();
    }
    else if (z == 4) {
      system("clear");
      Complex result = a.divide(b);
      a.display();  cout << "  /  ";  b.display();  cout << "  =  ";
      result.display();
      cout << "\n\npress enter to continue...";
      cin.get(); cin.get();
    }
    else if (z == 5) {
      system("clear");
      cout << "First complex number:\n";
      a.read();
      cout << "\nSecond complex number:\n";
      b.read();
    }
    else if (z == 6) {
      return 0;
    }
    else {
      system("clear");
      cout << "try 1-6 again";
      cin.get(); cin.get();
    }
  }

  return 0;
}
