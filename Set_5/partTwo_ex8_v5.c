#include <stdio.h>

int main(int argc, char* argv []) {
	FILE* x;
	char ware [20];
	double sum = 0;
	if (argc != 3) {
		printf("default\n");
		x = fopen("settlement.txt", "r");
	} else {
		x = fopen(argv[1] , "r");
	}
	fscanf(x, "%s", ware);
	while (!feof(x)) {
		double mb = 0;
		fscanf(x, "%lf", &mb);
		sum += mb;
		fscanf(x, "%s", ware);
	}
	fclose(x);
	if (argc != 3) {
		x = fopen("bills.txt", "a");
	} else {
		x = fopen(argv[2], "a");
	}
	fprintf(x, "%.2lf\n", sum);
	fclose(x);
	return 0;
}
