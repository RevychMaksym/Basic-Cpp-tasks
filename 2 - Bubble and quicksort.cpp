#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <random>
#include <algorithm>	

void swap(int &right, int &left) {
	int temp = right;
	right = left;
	left = temp;
}

typedef bool(*Compare)(int, int);

void bubble_sort(int *begin, int *end, Compare cmp) {
	for (auto it = begin; it != end; ++it) {
		for (auto it_next = (it + 1); it_next != end; ++it_next) {
			if (cmp(*it, *it_next)) {
				swap(*it, *it_next);
			}
		}
	}
}
/*
int *partition(int *begin, int *end, Compare cmp) {
	if ((begin != nullptr) && (end != nullptr) && (begin != end)) {
		auto pivot = (end - 1);
		auto pivot_location = end;
		for (auto it = begin; it != end; ++it) {
			if (cmp(*it, *pivot)) { // it > pivot
				swap(*pivot, *it);
				pivot_location--;
			}
		}
		return pivot_location;
	} else {
		std::cout << "Null pointer exception" << std::endl;
		return nullptr;
	}
}

void quick_sort(int *begin, int *end, Compare cmp) {
	if ((begin != nullptr) && (end != nullptr) && (begin != end)) {
		if (begin < end) {
			auto pivot_location = partition(begin, end, cmp);
			if ((begin != nullptr) && (end != nullptr) && (begin != end)) {
				quick_sort(begin, pivot_location, cmp);
				quick_sort(pivot_location + 1, end, cmp);
			}
		}
	}

	else {
		std::cout << "Null pointer exception" << std::endl;
	}
}
*/
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
			//quick_sort(begin_, end_, [](int a, int b) { return a > b; });
			std::sort(begin_, end_, [](int a, int b) { return a > b; });
			break;
		case 2:
			//quick_sort(begin_, end_, [](int a, int b) { return a < b; });
			std::sort(begin_, end_, [](int a, int b) { return a < b; });
			break;
		default:
			std::cout << "Wrong input!" << std::endl;
			break;
		}
		break;
	}
	std::sort(begin_, end_, [](int a, int b) { return a > b; });
	std::cout << "After sorting...." << std::endl;
	for (size_t index = 0; index < size; ++index) {
		std::cout << array[index] << " ";
	}
	std::cout << '\n';

	return 0;
}
