#include <cmath>
#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Please enter number to calculate it's sum and average: ";
  int input;
  std::cin >> input;

  unsigned int input_length = 0;
  int Sum = 0;
  while (input != 0) {
    Sum += input % 10;
    input /= 10;
    input_length++;
  }

  const auto average = static_cast<float>(Sum) / input_length;

  std::cout << "Sum of your number is: " << Sum << std::endl;
  std::cout << "Average of your number is: " << average << std::endl;

  return 0;
}
