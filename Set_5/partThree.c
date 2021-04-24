#include <stdlib.h>
#include <stdio.h>

#define SIZE 15
void vOne() {
	int* xd = (int*) malloc(sizeof(int) * SIZE);
	int i = 0;
	while (i < SIZE) {
		*(xd + i) = rand() % 5;
		i++;
	}
	i = 0;
	while (i < SIZE) {
		if (*(xd + i) != -1) {
			printf("%d ", *(xd + i));
			int j = i + 1;
			while (j < SIZE) {
				if (*(xd + i) == *(xd + j)) {
					*(xd + j) = -1;
				}
				j++;
			}
		}
		i++;
	}
	printf("\n");
	free(xd);
}

void vTwo(int a, int b) {
	int** x = (int**) malloc (sizeof(int*) * a);
	int i = 0;
	int bPlus = b + 1;
	while (i < a) {
		*(x + i) = (int*) malloc (sizeof(int) * b);
		i++;
	}
	double* bs = (double*) malloc (sizeof(double) * a);
	i = 0;
	while (i < a) {
		int j = 0;
		while (j < b) {
			*(*(x + i) + j) = rand();
			j++;
		}
		int k = 0;
		while (k < b) {
			int l = k + 1;
			while (l < b) {
				if (*(*(x + i) + l) < *(*(x + i) + l - 1)) {
					int temp = *(*(x + i) + l);
					*(*(x + i) + l) = *(*(x + i) + l - 1);
					*(*(x + i) + l - 1) = temp;
				}
				l++;
			}
			k++;
		}
		k = 0;
		double sum = 0;
		while (k < b) {
			sum += *(*(x + i) + k);
			k++;
		}
		double avg = sum / b * 1.0;
		sum = 0;
		k = 0;
		while (k < b) {
			sum += (*(*(x + i) + k) - avg) * (*(*(x + i) + k) - avg);
			k++;
		}
		*(bs + i) = sum / b;
		i++;
	}
	i = 0;
	while (i < a) {
		int p = i + 1;
		while (p < a) {
			if (*(bs + p) < *(bs + p - 1)) {
				int temp = *(bs + p);
				*(bs + p) = *(bs + p - 1);
				*(bs + p - 1) = temp;
				int* xd = *(x + p);
				*(x + p) = *(x + p - 1);
				*(x + p - 1) = xd;
			}
			p++;
		}
		i++;
	}
}
void vThree(int a, int b) {
	int** x = (int**) malloc (sizeof(int*) * a);
	int i = 0;
	while (i < a) {
		*(x + i) = (int*) malloc (sizeof(int) * b);
		i++;
	}
	i = 0;
	while (i < a) {
		int j = 0;
		while (j < b) {
			*(*(x + i) + j) = rand();
			j++;
		}
		i++;
	}
	i = 0;
	while (i < a) {
		free(*(x + i));
		i++;
	}
	free(x);
} 
int main() {
	vOne();
	vTwo(10, 10);
	vThree(10, 10);
	return 0;
}
