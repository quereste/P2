#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* x;
	char ware;
	double sum = 0;
	if (argc != 3) {
		printf("default\n");
		x = fopen("settlement.txt", "r");
	} else {
		x = fopen(argv[1], "r");
	}
	ware = fgetc(x);
	while (ware != EOF) {
		double mb = 0;
		while (ware != ':') {
			ware = fgetc(x);
		}
		fscanf(x, "%lf", &mb);
		sum += mb;
		ware = fgetc(x);
		printf(".%c.\n", ware);
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
