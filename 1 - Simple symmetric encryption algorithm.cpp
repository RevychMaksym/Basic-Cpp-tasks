#include <iostream>

int main() {
  std::cout << "Enter your matrix dimension [m x n]!\n";
  std::cout << "Rows: ";
  unsigned rows;
  std::cin >> rows;

  std::cout << "\nColumns: ";
  unsigned columns;
  std::cin >> columns;

  char **str = new char *[rows];
  for (unsigned i = 0; i < rows; ++i) {
    str[i] = new char[columns];
  }

  std::cout << "Enter your string max [" << rows << " x " << columns << "] - "
            << rows * columns << " elements: ";
  for (unsigned i = 0; i < rows; ++i) {
    for (unsigned j = 0; j < columns; ++j) {
      std::cin >> str[j][i];
    }
  }
  unsigned int users_choice;
  std::cout << "\nPlease choose following options:\n";
  std::cout << "1 = Encrypt the string.\n";
  std::cout << "2 = Decrypt the string.\n";
  std::cin >> users_choice;

  switch (users_choice) {
  case 1:
    std::cout << "\nEncrypted string: ";

    for (unsigned i = 0; i < rows; ++i) {
      for (unsigned j = 0; j < columns; ++j) {
        std::cout << str[i][j];
      }
    }
    break;
  case 2:
    std::cout << "\nDecrypted string: ";
    for (unsigned i = 0; i < rows; ++i) {
      for (unsigned j = 0; j < columns; ++j) {
        std::cout << str[j][i];
      }
    }
    break;
  default:
    std::cout << "\nInvalid Input !!!\n";
  }
  return 0;
}