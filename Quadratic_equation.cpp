#include <cmath>
#include <iostream>
#include <limits>

int main(int argc, char const *argv[]) {
  constexpr int MAX = std::numeric_limits<int>::max();
  constexpr int MIN = std::numeric_limits<int>::min();
  std::cout << "Program for solving quadratic equations (Ax^2 + Bx + C = 0): "
            << "\nPlease enter your A, B, C considering the range [" << MIN
            << "," << MAX << "]:\nA:";
  long a;
  std::cin >> a;
  if (a != 0 && a >= MIN && a <= MAX) {
    std::cout << "B:";
    long b;
    std::cin >> b;
    if (b >= MIN && b <= MAX) {
      std::cout << "C:";
      long c;
      std::cin >> c;
      if (c >= MIN && c <= MAX) {
        const auto FACTOR_4 = 4;
        const auto FACTOR_2 = 2;
        const auto discriminant = b * b - (FACTOR_4 * a * c);
        if (discriminant > 0) {
          std::cout << "Discriminant > 0, your example has 2 solutions.\n";
          const auto sqrt_discriminant = sqrt(discriminant);
          const auto X1 = (-b - sqrt_discriminant) / (FACTOR_2 * a);
          const auto X2 = (-b + sqrt_discriminant) / (FACTOR_2 * a);
          std::cout << "x1: " << X1 << "\nx2: " << X2;
        } else if (discriminant == 0) {
          std::cout << "Discriminant = 0, your example has 1 solution.\n";
          const auto X = (-b) / (2 * a);
          std::cout << "x: " << X;
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
