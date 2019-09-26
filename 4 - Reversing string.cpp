#include <iostream>

int main(int argc, char const *argv[]) {
  constexpr size_t MAX_SIZE = 100;
  std::cout << "Please enter a string to reverse it:  "
               "(max - 100 elmnts): ";
  char mass_char[MAX_SIZE]{};

  std::cin >> mass_char;

  std::cout << "Your string: " << mass_char << std::endl;

  char *begin_ = mass_char;
  char *end_ = (mass_char + MAX_SIZE);
  if ((begin_ != nullptr && end_ != nullptr && begin_ != end_)) {
    while (end_ != begin_) {
      if (*end_ == 0 || *end_ == -52) {
        *end_--;
      } else {
        std::cout << *end_--;
      }
    }
  }
  std::cout << begin_[0] << std::endl;

  return 0;
}
