#include <iostream>

int main(int argc, char const *argv[]) {
  constexpr size_t SIZE = 50;
  std::cout << "Please enter a string to make any lowercase letters into uppercase letters "
               "(max - 50 elmnts): ";
  char mass_char[SIZE]{};
  std::cin >> mass_char;
  std::cout << "Your string: " << mass_char << std::endl;
  const unsigned short ASCII_COUNTER = 32;
  for (size_t i = 0; i < SIZE; ++i) {
    if ((mass_char[i] >= 'A') && (mass_char[i] <= 'Z')) {
      mass_char[i] += ASCII_COUNTER;
    }
  }
  std::cout << "Your string after: " << mass_char << std::endl;
  return 0;
}
