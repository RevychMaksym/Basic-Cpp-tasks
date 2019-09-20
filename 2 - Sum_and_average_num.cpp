#include <iostream>
#include <numeric>

int charToInt(char ch) {
  return ch - '0';
}

int add(int addition, char addition_ch) {
  return addition + charToInt(addition_ch);
}

int main(int argc, char const *argv[]) {

  std::cout << "Please enter your numbers to calculate the sum and average of it: ";
  std::string input;
  std::cin >> input;
  std::cout << "Your input: " << input << std::endl;

  const int summ = std::accumulate(input.begin(), input.end(), 0, add);
  std::cout << "Sum of your numbers: " << summ << std::endl;

  const float average = static_cast<double>(summ) / input.size();
  std::cout << "Average of your numbers: " << average;
  
  return 0;
}