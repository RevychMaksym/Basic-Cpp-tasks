#include <iostream>
#include <limits>

int main() {

  constexpr unsigned int MIN = std::numeric_limits<unsigned int>::min();
  constexpr unsigned int MAX = std::numeric_limits<unsigned int>::max();

  const unsigned int MIN_EL = 1;
  const unsigned int MAX_EL = 10;
  std::cout << "Please enter number of elements in your sequence within a range ["
            << MIN_EL << "," << MAX_EL << "]: ";
  unsigned int quantity;
  std::cin >> quantity;
  if (MIN_EL > quantity || MAX_EL < quantity) {

    std::cout << "Please type a number WITHIN a given range, try again!";
    return 0;
  }
  printf("Initialise your sequence of numbers within a range [%u;%u]: ", MIN,
         MAX);
  unsigned int sum = 0;
  unsigned int input = 0;
  for (unsigned int i = 0; i < quantity; i++) {
    if ((MIN > input) || (MAX < input)) {
      std::cout << "Incorrect input, mortal! Try again!" << std::endl;
      return 1;
    }
    std::cout << "[" << i << "]: ";
    std::cin >> input;
    int argument;
    argument = input;

    unsigned int temp = argument;

    while (temp != 0) {
      sum += temp % 10;
      temp /= 10;
    }
  }
  std::cout << "Your number is: " << sum << std::endl;
  (sum % 3 == 0) ? std::cout << "Yes! Your number can be divided by 3"
                 : std::cout << "No! Your number can not be divided by 3";
  return 0;
}
