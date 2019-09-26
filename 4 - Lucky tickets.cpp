#include <iostream>
#include <limits>

bool isLucky(unsigned int input) {
	unsigned int argument = input;

	unsigned int counter = 0;
	while (input) {
		counter++;
		input /= 10;
	}

	if (counter % 2 != 0) {
		std::cout << "Your number is odd, please try again!" << std::endl;
		return false;
	}

	unsigned int sum1 = 0;
	for (unsigned int i = 0; i < counter / 2; i++) {
		sum1 += argument % 10;
		argument /= 10;
	}

	unsigned int sum2 = 0;
	for (unsigned int i = 0; i < counter / 2; i++) {
		sum2 += argument % 10;
		argument /= 10;
	}
	return sum2 == sum1;
}

int main(int argc, char const *argv[]) {
	std::cout << "Please enter the number of your ticket to find your luck: ";
	unsigned int input;
	std::cin >> input;
	bool res = isLucky(input);
	std::cout << ((res) ? ("Congrats, You have a winning ticket. You won 9999653$!") : ("Unlucky, better luck next time!"));
	return 0;
}
