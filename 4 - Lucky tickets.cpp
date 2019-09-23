#include <iostream>
#include <limits>

bool isLucky(unsigned int input) {
  unsigned int input_length = 0;
  unsigned int argument = input;

  unsigned int counter = 0;
  while (input) {
    counter++;
    input_length += input % 10;
    input /= 10;
  }

  unsigned int sum1 = 0;
  if (input_length % 2 != 0) {
    std::cout << "Your number is odd, please try again!" << std::endl;
    return false;
  }

  for (unsigned int i = 0; i < counter / 2; i++) {
    sum1 += argument % 10;
    argument /= 10;
  }

  unsigned int sum2 = 0;
  for (unsigned int i = 0; i < counter / 2; i++) {
    sum2 += argument % 10;
    argument /= 10;
  }
  return sum2 == sum1 ? true : false;
}

int main(int argc, char const *argv[]) {
  std::cout << "Please enter the number of your ticket to find your luck: ";
  unsigned int input;
  std::cin >> input;
  bool res = isLucky(input);
  if (res == true) {
    std::cout << "Congrats, You have a winning ticket. You won 9999653$!"
              << std::endl;
  } else {
    std::cout << "Unlucky, better luck next time!" << std::endl;
  }
  return 0;
}
