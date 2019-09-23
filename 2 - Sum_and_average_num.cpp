#include <cmath>
#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Please enter number to calculate it's sum and average: ";
  int input;
  std::cin >> input;

  unsigned int input_length = 1;
  int tmp = input;

  while (tmp /= 10) {
    input_length++;
  }

  std::cout << "Your input contains " << input_length << " numbers"
            << std::endl;

  int Sum = 0;
  for (unsigned int i = 0; i < input_length; ++i) {
    Sum += ((input) / static_cast<int>(pow(10, i))) % 10;
  }
  const auto average = static_cast<double>(Sum) / input_length;

  std::cout << "Sum of your number is: " << Sum << std::endl;
  std::cout << "Average of your number is: " << average << std::endl;

  return 0;
}
