#include <iostream>

constexpr size_t input_line_SIZE = 512;
constexpr size_t COPY_SIZE = 128;
constexpr size_t BUFFER_SIZE = 256;

enum {
	HELP = 1,
	PRINT,
	SELECT,
	COPY,
	PASTE,
	MOVE,
	CUT,
	SHOW,
	END,
	CLEAR,
};

void clear(char *begin) {
	if (begin == nullptr || *begin == '\0')
		return;

	while (*begin != '\0') {
		*begin = '\0';
		++begin;
	}
}

void show(const char *buffer) {
	while (*buffer != '\0') {
		std::cout << *buffer++;
	}
	std::cout << "\n";
}

unsigned int Get_Length(const char *begin) {
	if (begin == nullptr || *begin == '\0')
		return 0;

	unsigned int length = 0;
	while (*begin != '\0') {
		++length;
		++begin;
	}
	return length;
}

bool Compare_Strings(const char *first_input_line,
	const char *second_input_line) {
	if (first_input_line == nullptr || *first_input_line == '\0' ||
		second_input_line == nullptr || *second_input_line == '\0' ||
		(Get_Length(first_input_line) < Get_Length(second_input_line)))
		return false;

	bool is_equal = true;
	while (*first_input_line != '\0' && *second_input_line != '\0') {
		if (*first_input_line != *second_input_line) {
			is_equal = false;
			break;
		}
		++first_input_line;
		++second_input_line;
	}
	return is_equal;
}

int Get_Command(const char *input_line) {
	if (Compare_Strings(input_line, "end")) {
		return END;
	}
	else if (Compare_Strings(input_line, "print")) {
		return PRINT;
	}
	else if (Compare_Strings(input_line, "select")) {
		return SELECT;
	}
	else if (Compare_Strings(input_line, "copy")) {
		return COPY;
	}
	else if (Compare_Strings(input_line, "paste")) {
		return PASTE;
	}
	else if (Compare_Strings(input_line, "cut")) {
		return CUT;
	}
	else if (Compare_Strings(input_line, "move")) {
		return MOVE;
	}
	else if (Compare_Strings(input_line, "help")) {
		return HELP;
	}
	else if (Compare_Strings(input_line, "show")) {
		return SHOW;
	}
	else if (Compare_Strings(input_line, "clear")) {
		return CLEAR;
	}
	else
		return 0;
}

unsigned int print(char *buffer, const char *input_line) {
	unsigned int counter = 0;

	if (*buffer == '\0') {
		while (*input_line != '\0') {
			*buffer = *input_line;
			++buffer;
			++input_line;
			++counter;
		}
	}
	else {
		unsigned int input_line_len = Get_Length(input_line);
		unsigned int buff_len = Get_Length(buffer);

		while (buff_len > input_line_len) {
			--buff_len;
			*(buffer + input_line_len + buff_len) = *(buffer + buff_len);
		}

		while (*input_line != '\0') {
			*(buffer + input_line_len) = *buffer;
			*buffer = *input_line;
			++buffer;
			++input_line;
			++counter;
		}
	}

	return counter;
}
void select(const char *buffer, unsigned int &cursor, unsigned int &length) {
	bool cursor_is_not_setted = true;
	while (*buffer != '\0') {
		if ((*buffer >= '0') && (*buffer <= '9')) {
			if (cursor_is_not_setted) {
				cursor = (*buffer) - '0';
				cursor_is_not_setted = false;
			}
			else {
				length = (*buffer) - '0';
				break;
			}
		}
		++buffer;
	}
}

void copy(const char *buffer, char *copy_buffer, const unsigned int length) {
	unsigned int counter = 0;
	while (counter < length) {
		*copy_buffer = *buffer;
		++buffer;
		++copy_buffer;
		++counter;
	}
}

int paste(char *buffer, const char *copy_buffer) {
	unsigned int counter = 0;

	while (*copy_buffer != '\0' && counter < COPY_SIZE) {
		*buffer = *copy_buffer;
		++buffer;
		++copy_buffer;
		++counter;
	}
	return counter;
}

int move(const char *input_line) {
	int diff = 0;

	if (Compare_Strings(input_line, "left ")) {
		diff = -1;
	}
	else if (Compare_Strings(input_line, "right ")) {
		diff = 1;
	}
	else {
		return 0;
	}
	while (*input_line != '\0') {
		if ((*input_line >= '0') && (*input_line <= '9')) {
			return diff *= *input_line - '0';
		}
		++input_line;
	}
}

void cut(char *buffer, char *copy_buffer, const unsigned int length) {
	copy(buffer, copy_buffer, length);
	buffer += length;
	while (*buffer != '\0') {
		*(buffer - length) = *buffer;
		*buffer = 0;
		++buffer;
	}
}

int main(int argc, char const *argv[]) {

	std::cout << "Hello, welcome to the text editor. Enter 'help' to see all "
		"possible commands:";

	char input_line[input_line_SIZE]{};
	char copy_buffer[COPY_SIZE]{};
	char buffer[BUFFER_SIZE]{};

	unsigned int cursor = 0;
	unsigned int selectcursor = 0;
	unsigned int length = 0;

	bool IS_EXECUTING = true;

	while (IS_EXECUTING) {
		std::cout << "\n@$- ";
		std::cin >> input_line;
		const char COMMAND = Get_Command(input_line);
        clear(input_line);
		std::cin.getline(input_line, input_line_SIZE);
		switch (COMMAND) {
		case HELP:
			std::cout << "print 'text' - gets 'text' to your buffer." << std::endl;
			std::cout << "select 'buffer_position', 'quantity_of_characters' - "
				"selects characters from buffer"
				<< std::endl;
			std::cout << "copy - copies selected text." << std::endl;
			std::cout << "paste - pastes selected text." << std::endl;
			std::cout << "move 'direction', 'amount_of_characters' - moves your cursor."
				<< std::endl;
			std::cout << "cut - cuts selected elements from buffer." << std::endl;
			std::cout << "show - shows your buffer." << std::endl;
			std::cout << "clear - clears your buffer." << std::endl;
			std::cout << "end - ends your program" << std::endl;
			break;
		case PRINT:
			if (Get_Length(buffer) + Get_Length(input_line) <= BUFFER_SIZE) {
				cursor += print((buffer + cursor), (input_line + 1));
			}
			break;
		case SELECT:
			select(input_line, selectcursor, length);
			if (selectcursor >= BUFFER_SIZE) {
				selectcursor = BUFFER_SIZE - 1;
			}
			if ((selectcursor + length) >= BUFFER_SIZE) {
				length = length + (BUFFER_SIZE - (selectcursor + length));
			}
			if (length > COPY_SIZE) {
				length = COPY_SIZE;
			}
			break;
		case COPY:
			clear(copy_buffer);
			copy((buffer + selectcursor), copy_buffer, length);
			break;
		case PASTE:
			if (Get_Length(copy_buffer) + Get_Length(buffer) < BUFFER_SIZE) {
				cursor += paste((buffer + cursor), copy_buffer);
			}
			break;
		case MOVE: {
			int diff = move((input_line + 1));
			if ((cursor + diff) >= 0)
				cursor += diff;
			else
				cursor = 0;
		} break;
		case CUT: {
			clear(copy_buffer);
			cut((buffer + selectcursor), copy_buffer, length);
			if ((cursor - length) >= 0) {
				cursor -= length;
			}
			else {
				cursor = 0;
			}
		} break;
		case SHOW:
			show(buffer);
			break;
		case CLEAR:
			clear(buffer);
			break;
		case END:
			IS_EXECUTING = false;
			std::cout << "Program succesfully executed!" << std::endl;
			break;
		}
	}

	return 0;
}
