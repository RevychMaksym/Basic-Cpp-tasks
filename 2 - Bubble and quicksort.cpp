#include "pch.h"
#include <iostream>
#include <random>

void swap(int &right, int &left) {
  int temp = right;
  right = left;
  left = temp;
}

typedef bool (*Compare)(int, int);

void bubble_sort(int *begin, int *end, Compare cmp) {
  for (auto it = begin; it != end; ++it) {
    for (auto it_next = (it + 1); it_next != end; ++it_next) {
      if (cmp(*it, *it_next)) {
        swap(*it, *it_next);
      }
    }
  }
}

void quickSort(int *data, unsigned len, Compare cmp) {
  int const lenD = len;
  int pivot = 0;
  int ind = lenD / 2;
  int i, j = 0, k = 0;
  if (lenD > 1) {
    int *L = new int[lenD];
    int *R = new int[lenD];
    pivot = data[ind];
    for (i = 0; i < lenD; i++) {
      if (i != ind) {
        if (cmp(data[i], pivot)) {
          L[j] = data[i];
          j++;
        } else {
          R[k] = data[i];
          k++;
        }
      }
    }
    quickSort(L, j, cmp);
    quickSort(R, k, cmp);
    for (int cnt = 0; cnt < lenD; cnt++) {
      if (cnt < j) {
        data[cnt] = L[cnt];
        ;
      } else if (cnt == j) {
        data[cnt] = pivot;
      } else {
        data[cnt] = R[cnt - (j + 1)];
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  std::cout << "Please enter number of elements in your array: ";
  unsigned size;
  std::cin >> size;
  int *array = new int[size];

  std::cout << "Before sorting......" << std::endl;
  for (size_t index = 0; index < size; ++index) {
    array[index] = rand() % 39;
    std::cout << array[index] << " ";
  }

  std::cout << '\n';

  std::cout << "1 - Bubble sort" << std::endl;
  std::cout << "2 - Quick sort" << std::endl;
  unsigned choice;
  std::cin >> choice;
  int *begin_ = array;
  int *end_ = (array + size);

  switch (choice) {
  case 1:
    std::cout << "1 - Ascending" << std::endl;
    std::cout << "2 - Descending" << std::endl;
    unsigned switch_choice_case1;
    std::cin >> switch_choice_case1;

    switch (switch_choice_case1) {
    case 1:
      bubble_sort(begin_, end_, [](int a, int b) { return a > b; });
      break;
    case 2:
      bubble_sort(begin_, end_, [](int a, int b) { return a < b; });
      break;
    default:
      std::cout << "Wrong input!" << std::endl;
      break;
    }
    break;

  case 2:
    std::cout << "1 - Ascending" << std::endl;
    std::cout << "2 - Descending" << std::endl;
    unsigned switch_choice_case2;
    std::cin >> switch_choice_case2;
    switch (switch_choice_case2) {
    case 1:
      quickSort(begin_, size, [](int a, int b) { return a < b; });
      break;
    case 2:
      quickSort(begin_, size, [](int a, int b) { return a > b; });
      break;
    default:
      std::cout << "Wrong input!" << std::endl;
      break;
    }
    break;
  }
  std::cout << "After sorting...." << std::endl;
  for (size_t index = 0; index < size; ++index) {
    std::cout << array[index] << " ";
  }
  std::cout << '\n';

  return 0;
}
