#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Welcome! This is the program to help you calculate sum of odd "
               "elements in any row!\n"
            << "Please enter number of elements in your sequence: ";

  int quantity_of_elmnts;
  std::cin >> quantity_of_elmnts;

  std::cout << "\nPlease initialise the sequence of numbers to calculate the sum "
               "of odd numbers! \n"
            << "Numbers must be in the [-60; 90] radius: ";

  int *sequence = new int[quantity_of_elmnts];
  int sum = 0;
  if (quantity_of_elmnts < 50) {
    for (int i = 0; i < quantity_of_elmnts; i++) {
      std:: cout << "[" << i << "]: ";
      std::cin >> sequence[i];
      if ((sequence[i]) % 2 == 1) {
        sum += sequence[i];
      }
    }

    std::cout << "Sum of your odd elements is: " << sum << std::endl;

  } else {
    std::cout << "Sorry, your array is too big!" << std::endl;
  }

  return 0;
}
