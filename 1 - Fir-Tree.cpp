#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Please enter your base number for your fir-tree: ";
  unsigned int input;
  std::cin >> input;

  if (input % 2 == 0) {
    input++;
  }

  unsigned int stars = 1;
  unsigned int spaces = 1;
  while (stars <= input) {
    for (int k = input; k >= spaces; --k) {
      std::cout << " ";
    }
    spaces++;

    for (int i = 1; i <= stars; ++i) {
      std::cout << "*";
    }
    stars += 2;
    std::cout << "\n";
  }
  return 0;
}
