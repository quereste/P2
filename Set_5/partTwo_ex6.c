#include <stdio.h>

int main() {
	FILE* x;
	char ware;
	double sum = 0;
	x = fopen("settlement.txt", "r");
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
	x = fopen("bills.txt", "a");
	fprintf(x, "%.2lf\n", sum);
	fclose(x);
	return 0;
}
