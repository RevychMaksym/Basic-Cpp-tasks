#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Please enter number to learn its binary representation and "
               "quantity of 1 in it: ";
  int input;
  std::cin >> input;
  unsigned int quantity_1;
  for (unsigned int i = 0; i < sizeof(int) * 8; i++) {
    if (input & (1 << i)) {
      quantity_1++;
    }
  }
  std::cout << "Your input has " << quantity_1 << " ones." << std::endl;
  return 0;
}
