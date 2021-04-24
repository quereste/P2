#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 50
int main(int argc, char* argv []) {
	FILE* x;
	x = fopen(argv[1], "r");
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
	char** xd = (char**) malloc(sizeof(char*) * sum);
	i = 0;
	while (i < sum) {
		*(xd + i) = (char*) malloc(sizeof(char) * SIZE);
		i++;
	}
	i = 0;
	fgets(*(xd + i), SIZE, x);
	i++;
	while (!feof(x)) {	
		fgets(*(xd + i), SIZE, x);
		i = (i + 1) % sum;
	}
	fclose(x);
	int j = i;
	while (j < sum) {
		printf("%s", *(xd + j));
		j++;
	}
	j = 0;
	while (j < i) {
		printf("%s", *(xd + j));
		j++;
	}
	j = 0;
	while (j < sum) {
		free(*(xd + j));
		j++;
	}
	free (xd);
	return 0;
}
