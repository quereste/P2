#include <stdio.h>

int main() {
	FILE* x;
	char ware [20];
	double sum = 0;
	x = fopen("settlement.txt", "r");
	fscanf(x, "%s", ware);
	while (!feof(x)) {
		double mb = 0;
		fscanf(x, "%lf", &mb);
		sum += mb;
		fscanf(x, "%s", ware);
	}
	fclose(x);
	x = fopen("bills.txt", "a");
	fprintf(x, "%.2lf\n", sum);
	fclose(x);
	return 0;
}
