#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <random>

void swap(int& right, int& left) {
	int temp = right;
	right = left;
	left = temp;
}
void print(int *a, int *b) {
	std::cout << a << " " << b << std::endl;
}

void print(const int * a, const int *b) { //этот код скомпилируется, тк указатель указывает уже на другой тип; константность типа, на который указывает указатель имеет роль
	std::cout << a << " " << b << std::endl;
}

bool func_more(int a, int b) {
	return a > b;
}

bool func_less(int a, int b) {
	return a < b;
}

typedef bool(*Compare)(int, int);

void bubble_sort(int* begin, int* end, Compare cmp) {
	for (auto it = begin; it != end; ++it) {
		for (auto it_next = (it + 1); it_next != end; ++it_next) {
			if (cmp(*it, *it_next)) { 
				swap(*it, *it_next);
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
		array[index] = rand() % 30;
		std::cout << array[index] << " ";
	}

	std::cout << '\n';

	std::cout << "1 - Bubble sort" << std::endl;
	std::cout << "2 - Quick sort" << std::endl;
	unsigned choice;
	std::cin >> choice;

	switch (choice) {
	case 1:
		std::cout << "1 - Ascending" << std::endl;
		std::cout << "2 - Descending" << std::endl;
		unsigned switch_choice_case1;
		std::cin >> switch_choice_case1;

		switch (switch_choice_case1) {
		case 1:
			bubble_sort(array, array + (sizeof(array) / sizeof(array[0])),
				[](int a, int b) { return a > b; });
			break;
		case 2:
			bubble_sort(array, array + (sizeof(array) / sizeof(array[0])),
				[](int a, int b) { return a < b; });
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
			//quick_sort(array, array + (sizeof(array) / sizeof(array[0])),
			//           [](int a, int b) { return a > b; });
			break;
		case 2:
			//quick_sort(array, array + (sizeof(array) / sizeof(array[0])),
			//           [](int a, int b) { return a < b; });
			break;
		default:
			std::cout << "Wrong input" << std::endl;
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
