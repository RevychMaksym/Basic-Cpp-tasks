#include <iostream> 
#include <limits>

int main(int argc, char const *argv[]) {
  std::cout << "Please enter your number to check if any bit is set in it: ";
  uint32_t input;
  std::cin >> input;
  constexpr uint32_t MAX = std::numeric_limits<uint32_t>::max();
  if (MAX >= (input)) {
    struct BitChecker {
      uint8_t bit;
    };
    unsigned int is_set;
    BitChecker bit_number;
    std::cout << "Enter the bit you want to check (0-31): ";
    std::cin >> is_set;
    bit_number.bit = is_set;
    if (is_set < 32 && is_set >= 0) {
      const bool res = input & (1 << (bit_number.bit));
      if (res == true) {
        std::cout << "Yes" << std::endl;
      } else {
        std::cout << "No" << std::endl;
      }
    } else {
      std::cout << "Incorrect input!" << std::endl;
    }
  } else {
    std::cout << "Number overflow!" << std::endl;
  }
  return 0;
}
