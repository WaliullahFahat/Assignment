#include <iostream>
#include <string>

using namespace std;

class Fraction {
  private:
    int numerator, denominator;

  public:
    Fraction(int num, int denom) {
      if (denom == 0) {
        cout << "Error: Denominator cannot be zero" << endl;
        exit(1);
      }
      numerator = num;
      denominator = denom;
    }

    void reduce() {
      int gcd = findGCD(numerator, denominator);
      numerator /= gcd;
      denominator /= gcd;
    }

    string str() const {
      string s = to_string(numerator) + "/" + to_string(denominator);
      return s;
    }

    string repr() const {
      string s = "Fraction(" + to_string(numerator) + ", " + to_string(denominator) + ")";
      return s;
    }

    Fraction operator+(const Fraction& other) const {
      int num = numerator * other.denominator + other.numerator * denominator;
      int denom = denominator * other.denominator;
      Fraction result(num, denom);
      result.reduce();
      return result;
    }

  private:
    int findGCD(int a, int b) const {
      if (b == 0) {
        return a;
      }
      return findGCD(b, a % b);
    }
};

int main() {
  Fraction f1(3, 4);
  Fraction f2(1, 2);
  Fraction f3 = f1 + f2;
  cout << f1.str() << " + " << f2.str() << " = " << f3.str() << endl;
  cout << f3.repr() << endl;
  return 0;
}
