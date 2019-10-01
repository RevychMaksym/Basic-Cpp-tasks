#include <iostream>
#include <limits>

int main() {

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
  
  constexpr unsigned int MIN = std::numeric_limits<unsigned int>::min();
  constexpr unsigned int MAX = std::numeric_limits<unsigned int>::max();
  printf("Initialise your sequence of numbers within a range [%u;%u]: ", MIN,
         MAX);
  unsigned int sum = 0;
  for (unsigned int i = 0; i < quantity; ++i) {
    unsigned long input = 0;
    if ((MIN > input) && (MAX < input)) {
      std::cout << "Incorrect input, mortal! Try again!" << std::endl;
      return 1;
    }
    std::cout << "[" << i << "]: ";
    std::cin >> input;
    unsigned int temp = input;
    while (temp != 0) {
      sum += temp % 10;
      temp /= 10;
    }
  }
  std::cout << "Your number is: " << sum << std::endl;
  std::cout << ((sum % 3 == 0) ? "Yes! Your number can be divided by 3" : "No! Your number can not be divided by 3");
  return 0;
}
