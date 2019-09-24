#include <iostream>

int main(int argc, char const *argv[]) {
  constexpr size_t SIZE = 50;
  std::cout << "Please enter a string to see if there are any numbers in it "
               "(max - 50 elmnts): ";
  char mass_char[SIZE]{};
  std::cin >> mass_char;
  std::cout << "Your string: " << mass_char << std::endl;
  for (size_t i = 0; i < SIZE - 1; ++i) {
    if ((mass_char[i] <= '9') && (mass_char[i] >= '0')) {
      std::cout << "Is digit - " << mass_char[i] << "; ";
    }
  }
  return 0;
}
