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

    int sum = 0;
    int *sequence = new int[quantity_of_elmnts];
    const int MIN_ELEMENT = -60;
    const int MAX_ELEMENT = 90;

    for (unsigned int i = 0; i < quantity_of_elmnts; i++) {
      std::cout << "[" << i << "]: ";
      std::cin >> sequence[i];
      if (MIN_ELEMENT <= sequence[i] && MAX_ELEMENT >= sequence[i]) {
        if ((sequence[i]) % 2 == 1) {
          sum += sequence[i];
        }
      } else {
        sequence[i] = 0;
        std::cout << "Incorrect input! assigned 0.\n";
      }
    }

    std::cout << "Sum of your odd elements is: " << sum << std::endl;

  } else {
    std::cout << "Incorrect input, try again!" << std::endl;
  }

  return 0;
}
