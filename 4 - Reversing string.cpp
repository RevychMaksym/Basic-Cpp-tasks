#include <iostream>

int main(int argc, char const *argv[]) {
  constexpr size_t MAX_SIZE = 50;
  std::cout << "Please enter a string to reverse it:  "
               "(max - 100 elmnts): ";
  char mass_char[MAX_SIZE]{};

  std::cin >> mass_char;

  std::cout << "Your string: " << mass_char << std::endl;

  char *begin_ = mass_char;
  char *end_ = (mass_char + MAX_SIZE);
  if ((begin_ != nullptr) && (end_ != nullptr) && (begin_ != end_)) {
    while (begin_ != end_ && end_ > begin_) {
      *end_--;
      std::swap(*begin_, *end_);
      *begin_++;
    }
    std::cout << "Reversed string: ";
    for (size_t i = 0; i < MAX_SIZE; ++i) {
      if (mass_char[i] == '\0') {
        continue;
      }
      std::cout << mass_char[i];
    }
    return 0;
  }
}
