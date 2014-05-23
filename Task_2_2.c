#include <stdbool.h>
#include <stdio.h>

#define DEBUG true

typedef int state;

state move(state s, char c);

int main(int argc, char *argv[])
{
	char *fname;
	FILE *f;
	char c;
	state s = 0;

	if (argc > 1) {
		if (NULL == (f = fopen(argv[1], "r"))) {
			printf("Error opening file\n");
			return 2;
		}
	} else {
		printf("Specify a filename\n");
		return 2;
	}

	while ((c = getc(f)) != EOF) {
		s = move(s, c);
	}

	/* if (s in F) */
		/* return true; */
	/* else */
		/* return false; */
}

state move(state s, char c)
{
	switch (s) {
		case 0:
			if (c == '/')
				s = 1;
			break;
		case 1:
			if (c == '*') {
				printf("/");
				printf("*");
				s = 2;
			} else
				s = 0;
			break;
		case 2:
			if (c == '*')
				s = 3;
			else
				putchar(c);
			break;
		case 3:
			if (c == '/') {
				printf("*");
				printf("/\n");
				s = 0;
			} else {
				s = 2;
				putchar(c);
			}
			break;
	}

	return s;
}
