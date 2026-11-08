#include <iostream>
using namespace std;

class Triangle {
  private:
    double base;
    double height;
    double area;

  public:
    Triangle(double b = 1, double h = 1) {
      base   = b;
      height = h;
      area   = 0;
    }

    void input() {
      cout << "Enter base: ";
      cin >> base;
      cout << "Enter height: ";
      cin >> height;
    }

    void calculator() {
      area = (base * height) / 2.0;
    }

    void print() {
      cout << "Area = " << area << endl;
    }
};

int main() {
  Triangle t;
  system("clear");
  t.input();
  t.calculator();
  t.print();

  return 0;
}
