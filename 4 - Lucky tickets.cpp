#include <iostream>
#include <limits>

bool isLucky(unsigned int input) {
  if (input >= 100'000 && input <= 999'999) {
    unsigned int argument = input;

    unsigned int sum1 = 0;
    for (unsigned int i = 0; i < 3; i++) {
      sum1 += argument % 10;
      argument /= 10;
    }

    unsigned int sum2 = 0;
    for (unsigned int i = 0; i < 3; i++) {
      sum2 += argument % 10;
      argument /= 10;
    }
    return sum2 == sum1;
  } else {
    std::cout << "Incorrect input!" << std::endl;
    return false;
  }
}

int main(int argc, char const *argv[]) {
  std::cout << "Please enter the number of your 6-digit ticket to find your luck: ";
  unsigned int input;
  std::cin >> input;
  bool res = isLucky(input);
  std::cout << ((res) ? ("Congrats, You have a winning ticket. You won 9999653$!") : ("Unlucky, better luck next time!"));
  return 0;
}
