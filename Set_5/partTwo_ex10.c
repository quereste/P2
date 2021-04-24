#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 400
int main(int argc, char* argv []) {
	FILE* x;
	x = fopen(argv[1], "r");
	char w [400];
	int sum = 0;
	int limit = strlen(argv[2]);
	int i = limit - 1;
	int ten = 1;
	while (i >= 0) {
		int n = argv[2][i] - 48;
		sum += n * ten;
		ten *= 10;
		i--;
	}
	fgets(w, 400, x);
	i = 0;
	while (1) {
		while (i < sum && !feof(x)) {
			printf("%s", w);
			fgets(w, 400, x);
			i++;
		}
		if (feof(x)) {
			break;
		} else {
			char c = getchar();
			if (c == '\n') {
				c = getchar();
			}
			if (c == 'q' || c == 27) {
				break;
			} else {
				i = 0;
			}
		}
	}
	
	return 0;
}
