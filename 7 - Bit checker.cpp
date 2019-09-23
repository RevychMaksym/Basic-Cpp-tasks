#include <iostream>
#include <limits>

int main(int argc, char const *argv[]) {
  std::cout << "Please enter your number to check if any bit is set in it: ";
  uint32_t input;
  std::cin >> input;
  constexpr uint32_t MAX = std::numeric_limits<uint32_t>::max();
  if (MAX >= (input) && 0 <= (input)) {

    uint32_t check_bit;
    std::cin >> check_bit;

    if (check_bit < 1 || check_bit > 32) {
      std::cout << "Sorry you have entered incorrect number of 32th bit value. "
                   "Please try again!";
      return 1;
    }
    std::cout << "Bit is";
    input &(1 << (check_bit - 1)) ? std::cout << " set  \n"
                                  : std::cout << " not set \n";
  } else {
    std::cout << "Number overflow!" << std::endl;
  }
  return 0;
}
