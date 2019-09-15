#include <cmath>
#include <iostream>
#include <limits>

int main(int argc, char const *argv[]) {
  constexpr int MAX = std::numeric_limits<short>::max();
  constexpr int MIN = std::numeric_limits<short>::min();
  double a;
  std::cout << "Please enter your A, B, C considering the range [" << MIN << ","
            << MAX << "]:\nA:";
  std::cin >> a;
  if (a != 0 && a >= MIN && a <= MAX) {
    std::cout << "B:";
    double b;
    std::cin >> b;
    if (b >= MIN && b <= MAX) {
      std::cout << "C:";
      double c;
      std::cin >> c;
      if (c >= MIN && c <= MAX) {
        auto discriminant = std::pow(b, 2) - (4 * a * c);
        if (discriminant > 0) {
          std::cout << "Discriminant > 0, your example has 2 solutions.\n";
          auto sqrt_discriminant = sqrt(discriminant);
          auto x1 = (-b - sqrt_discriminant) / (2 * a);
          auto x2 = (-b + sqrt_discriminant) / (2 * a);
          std::cout << "x1: " << x1 << "\nx2: " << x2;
        } else if (discriminant == 0) {
          std::cout << "Discriminant = 0, your example has 1 solution.\n";
          auto x = (-b) / (2 * a);
          std::cout << "x: " << x;
        } else if (discriminant < 0) {
          std::cout
              << "Discriminant is negative, your example has no real solutions";
        }
      } else {
        std::cout << "Number C is out of range, please try again\n";
      }
    } else {
      std::cout << "Number B is out of range, please try again\n";
    }
  } else {
    std::cout << "Number A is out of range or equals 0, please try again\n";
  }
  return 0;
}
