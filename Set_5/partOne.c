#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define T 48
void rv() {
	char t [20];
	scanf("%s", &t);
	int size = strlen(t);
	int i = size - 1;
	for ( ; i >= 0; i--) {
		printf("%c", toupper(t[i]));
	}
	printf("\n");
}

void mp() {
	char sOne [] = "abcdefghijklmnopqrstuvwxyz";
	char sTwo [] = "zyxwvutsrqponmlkjihgfedcba";
	char sThree [20];
	int i = 0;
	scanf("%s", &sThree);
	int limit = strlen(sThree);
	while (i < limit) {
		char * x = strchr(sOne, sThree [i]);
		if (x != NULL) 
			sThree [i] = *(sTwo + (x - sOne));
		printf("%c", sThree [i]);
		i++;
	}
	printf("\n");
}

void tellMe() {
	char s [20];
	char t [][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	scanf("%s", &s);
	int limit = strlen(s);
	int i = 0;
	while (i < limit) {
		printf("%s ", t[s[i] - T]);
		i++;
	}
	printf("\n");
}

void count_zeros(long number) {
	int limit = sizeof(long) * 8;
	
	long c = 1 << (limit - 2);
	int sem = 32;
	if (number >= 0) {
		while (sem) {
			if (c & number) {
				break;
			} else {
				c = c >> 1;
			}
			if (c == 0) {
				break;
			}
		}
	}
	int counter = 0;
	while (sem--) {
		if (!(c & number)) {
			counter += 1;
		}
		c = c >> 1;
		if (c == 0) 
			break;
	}
	printf("%d\n", counter);
}

int cover(char c) {
	if (c == 'I') {
		return 1;
	} else if (c == 'V') {
		return 5;
	} else if (c == 'X') {
		return 10;
	} else if (c == 'L') {
		return 50;
	} else if (c == 'C') {
		return 100;
	} else if (c == 'D') {
		return 500;
	} else if (c == 'M') {
		return 1000;
	}
	return -1;
}
void cnv() {
	char t [20];
	scanf("%s", &t);
	int limit = strlen(t);
	if (t[0] >= '0' && t[0] <= '9') {
		int i = limit - 1;
		int sum = 0;
		int ten = 1;
		while (i >= 0) {
			sum += (t[i] - 48) * ten;
			ten *= 10;
			i--;
		}
		while (sum) {
			if (sum >= 1000) {
				printf("M");
				sum -= 1000;
			} else if (sum >= 900) {
				printf("CM");
				sum -= 900;
			} else if (sum >= 500) {
				printf("D");
				sum -= 500;
			} else if (sum >= 400) {
				printf("CD");
				sum -= 400;
			} else if (sum >= 100) {
				printf("C");
				sum -= 100;
			} else if (sum >= 90) {
				printf("XC");
				sum -= 90;
			} else if (sum >= 50) {
				printf("L");
				sum -= 50;
			} else if (sum >= 40) {
				printf("XL");
				sum -= 40;
			} else if (sum >= 10) {
				printf("X");
				sum -= 10;
			} else if (sum == 9) {
				printf ("IX");
				sum -= 9;
			} else if (sum >= 5) {
				printf("V");
				sum -= 5;
			} else if (sum == 4) {
				printf ("IV");
				sum -= 4;
			} else {
				while (sum != 0) {
					printf("I");
					sum -= 1;
				}
			}
		}
		printf("\n");
	} else {
		int sum = 0;
		int i = 0;
		int boundary = limit - 1;
		while (i < limit) {
			if (i == boundary) {
				sum += cover(t[i]);
				i++;
			} else {
				int a = cover(t[i]);
				int b = cover(t[i + 1]);
				if (a >= b) {
					sum += a;
					i++;
				} else {
					sum += b - a;
					i += 2;
				}
			}
		}
		printf("%d\n", sum);
	}
}
int main() {
	// rv();
	//mp();
	//tellMe();
//	count_zeros(-4);
//	count_zeros(15);
	cnv();
	return 0;
}
