#include <iostream>

int main(int argc, char const *argv[]) {
  constexpr size_t MAX_SIZE = 50;
  std::cout << "Please enter a string to reverse it:  "
               "(max - 100 elmnts): ";
  char mass_char[MAX_SIZE]{};

  std::cin >> mass_char;

  std::cout << "Your string: " << mass_char << std::endl;
  size_t length = 0;
  while (mass_char[length++] != 0) {
    ;
  }

  char *begin_ = mass_char;
  char *end_ = (mass_char + length - 1);
  if ((begin_ != nullptr) && (end_ != nullptr) && (begin_ != end_)) {
    while (begin_ < end_) {
      std::swap(*begin_++, *--end_);
    }
    std::cout << "Reversed string: ";

    std::cout << mass_char << std::endl;
    return 0;
  } else {
    return 1;
  }
}
