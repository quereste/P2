#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
	FILE* x;
	char ware [100];
	char name [16];
	if (argc != 3) {
		printf("default\n");
		x = fopen("input.txt", "r");
	} else {
		x = fopen(argv[1], "r");
	}
	fscanf(x, "%s", name);
	fclose(x);
	int sum = 0;
	int number = 0;
	int min = 0;
	int max = 0;
	x = fopen(name, "r");
	fscanf(x, "%s", ware);
	if (!feof(x)) {
		min = strlen(ware);
		max = min;
		sum = min;
		number = 1;
	}
	fscanf(x, "%s", ware);
	while (!feof(x)) {
		int mL = strlen(ware);
		if (mL > max) {
			max = mL;
		} else if (mL < min) {
			min = mL;
		}
		sum += mL;
		number++;
		fscanf(x, "%s", ware);
	}
	fclose(x);
	if (argc != 3) {
		x = fopen("statistics.dat", "w");
	} else {
		x = fopen(argv[2], "w");
	}
	fprintf(x, "avg: %.2f\nmin: %d\nmax: %d\n", sum * 1.0 / number, min, max);
	fclose(x);
	return 0;
}
