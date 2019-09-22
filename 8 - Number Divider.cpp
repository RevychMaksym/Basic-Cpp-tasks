#include <iostream>
#include <limits>

// typedef unsigned int uint;

void printDivisors(unsigned int input) {
  for (unsigned int i = 1; i <= input; i++) {
    if (input % i == 0) {
      printf("%d ", i);
    }
  }
}

unsigned int BestDivider(unsigned int input) {

  unsigned int best_sum_divider = 0;
  unsigned int best_divider = 0;
  for (unsigned int i = 1; i <= input; i++) {
    if (input % i == 0) {

      unsigned int temp = i;
      unsigned int sum_divider = 0;
      while (temp != 0) {
        sum_divider += temp % 10;
        temp /= 10;
      }
      if (sum_divider >= best_sum_divider) {
        best_divider = i;
        best_sum_divider = sum_divider;
      }
    }
  }
  return best_divider;
}

int main() {
  constexpr unsigned int MIN = std::numeric_limits<unsigned int>::min();
  constexpr unsigned int MAX = std::numeric_limits<unsigned int>::max();
  printf("Please enter a number to calculate all divisors and its best divisor "
         "within a range of [%u;%u]",
         MIN, MAX);
  unsigned int input;
  std::cin >> input;
  if ((MIN > input) || (MAX < input)) {
    std::cout << "Incorrect input, mortal! Try again!" << std::endl;
  }

  printf("The divisors of %u are: ", input);
  printDivisors(input);
  const auto best_divider = BestDivider(input);
  std::cout << "\nThe BEST divider is: " << best_divider << std::endl;
  return 0;
}