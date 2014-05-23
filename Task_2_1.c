#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define ORDIE	else\
		return false;\
		break;

#define DEBUG 	false

int lex() {
	int state = 0;
	char ch;

	while (true) {
		ch = getchar();
		if (DEBUG)
			printf("%d: got %c\n", state, ch);
		switch (state) {
			case 0:
				if isdigit(ch)
					state = 1;
				ORDIE
			case 1:
				if isdigit(ch)
					state = 1;
				else if (ch == 'E')
					state = 4;
				else if (ch == '.')
					state = 2;
				else if (ch == '\n')
					return true;
				ORDIE
			case 2:
				if isdigit(ch)
					state = 3;
				ORDIE
			case 3:
				if isdigit(ch)
					state = 3;
				else if (ch == 'E')
					state = 4;
				else if (ch == '\n')
					return true;
				ORDIE
			case 4:
				if isdigit(ch)
					state = 6;
				else if (ch == '+' || ch == '-')
					state = 5;
				ORDIE
			case 5:
				if isdigit(ch)
					state = 6;
				ORDIE
			case 6:
				if isdigit(ch)
					state = 6;
				else if (ch == '\n')
					return true;
				ORDIE
		}
	}
}


int main() {
	if (lex()) {
		puts("Accepted.");
		return 0;
	} else {
		puts("Discarded.");
		return 1;
	}

	return 0;
}
