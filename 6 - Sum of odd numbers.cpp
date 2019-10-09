#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Welcome! This is the program to help you calculate sum of odd "
            "elements in any row!\n"
            << "Please enter number of elements in your sequence (max number - 50): ";

  unsigned int quantity_of_elmnts;
  std::cin >> quantity_of_elmnts;
  constexpr unsigned int MAX = 50;
  if ((MAX >= quantity_of_elmnts) && (0 < quantity_of_elmnts)) {

    std::cout << "\nPlease initialise the sequence of numbers to calculate the sum "
              "of odd numbers! \n"
              << "Numbers must be in the [-60; 90] radius: ";

    long long sum = 0;
    const int MIN_ELEMENT = -60;
    const int MAX_ELEMENT = 90;

    while (0 < quantity_of_elmnts) {
      int input;
      std::cin >> input;
      if (MIN_ELEMENT <= input && MAX_ELEMENT >= input) {
        if ((input) % 2 == 1) {
          sum += input;
        }
        quantity_of_elmnts--;
      } else {
        std::cout << "Incorrect input! assigned, try again\n";
      }
    }

    std::cout << "Sum of your odd elements is: " << sum << std::endl;

  } else {
    std::cout << "Incorrect input, try again!" << std::endl;
  }

  return 0;
}
