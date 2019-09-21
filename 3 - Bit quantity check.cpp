#include <bitset>
#include <iostream>
#include <limits>

int main(int argc, char const *argv[]) {
  std::cout << "Please enter number to learn its binary representation and "
               "quantity of 1 in it: ";
  int input;
  std::cin >> input;

  std::cout << "The binary represantation of your number - "
            << std::bitset<16>(input) << std::endl;
  std::bitset<std::numeric_limits<int>::digits> bitset(input);
  std::cout << "Your input has " << bitset.count() << " ones." << std::endl;
  return 0;
}
