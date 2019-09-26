#include <iostream>
#include <limits>

int main(int argc, char const *argv[]) {
  std::cout << "Please enter your x32 number to check if any bit is set in it: ";
  uint64_t input;
  std::cin >> input;
  constexpr uint32_t MAX = std::numeric_limits<uint32_t>::max();
  if (MAX >= (input) && 0 <= (input)) {
    std::cout << "Enter the bit you want to check: ";
    uint32_t check_bit;
    std::cin >> check_bit;
    constexpr unsigned int MIN_EL = 1;
    constexpr unsigned int MAX_EL = 32;
    if (MIN_EL > check_bit || MAX_EL < check_bit ) {
      std::cout << "Sorry you have entered incorrect number of 32th bit value. "
                   "Please try again!";
      return 1;
    }
    std::cout << "Bit is" << (input &(1 << (check_bit - 1)) ? " set  \n" : " not set \n");
  } else {
    std::cout << "Number overflow!" << std::endl;
  }
  return 0;
}
