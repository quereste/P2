#include <stdio.h>
#define SIZE 5


struct matrix {
	int t [SIZE] [SIZE];
}; 

void init(struct matrix* v){
		int i = 0;
		while (i < SIZE) {
			int j = 0;
			while (j < SIZE) {
				scanf("%d", &(v->t [i] [j]));
				j++;
			}
			i++;
		}
	}
		
struct matrix sum(struct matrix* a, struct matrix* b) {
		struct matrix c;
		int i = 0;
		while (i < SIZE) {
			int j = 0;
			while (j < SIZE) {
				c.t [i] [j] = a->t [i] [j] + b->t [i] [j];
				j++;
			}
			i++;
		}
		return c;
	}

struct matrix sub(struct matrix* a, struct matrix* b) {
		struct matrix c;
		int i = 0;
		while (i < SIZE) {
			int j = 0;
			while (j < SIZE) {
				c.t [i] [j] = a->t [i] [j] - b->t [i] [j];
				j++;
			}
			i++;
		}
		return c;
	}
	
struct matrix multByConstant(struct matrix* a, int e) {
		struct matrix c;
		int i = 0;
		while (i < SIZE) {
			int j = 0;
			while (j < SIZE) {
				c.t [i] [j] = e * a->t [i] [j];
				j++;
			}
			i++;
		}
		return c;
	}

struct matrix mult(struct matrix a, struct matrix b) {
		struct matrix c;
		int i = 0;
		while (i < SIZE) {
			int j = 0;
			while (j < SIZE) {
				int k = 0;
				int res = 0;
				while (k < SIZE) {
					res += a.t [i] [k] * b.t [k] [j];
					k++;
				}
				c.t [i] [j] = res;
				j++;
			}
			i++;
		}
		return c;
}

int determinant(struct matrix x, int mode) {
	if (mode == 1) {
		return x.t [0] [0];
	} else if (mode == 2) {
		return x.t [0] [0] * x.t [1] [1] - x.t [0] [1] - x.t [1] [0];
	} else if (mode == 3) {
		return x.t [0] [0] * x.t [1] [1] * x.t [2] [2] + x.t [0] [1] * x.t [1] [2] * x.t [2] [0] + x.t [0] [2] * x.t [1] [0] * x.t [2] [1]
				- x.t [2] [0] * x.t [1] [1] * x.t [0] [2] - x.t [2] [1] * x.t [1] [2] * x.t [0] [0] - x.t [2] [2] * x.t [1] [0] * x.t [0] [1];
	} else {
		printf("programmer was to lazy to write function handling such a case\n");
	}
}
int areTheyEqual(struct matrix a, struct matrix b) { // 1 <=> are equal
	int i = 0;
	int r = 1;
	while (i < SIZE && r) {
		int j = 0;
		while (j < SIZE && r) {
			if (a.t[i][j] != b.t[i][j]) {
				r = 0;
			}
			j++;
		}
		i++;
	}
	return r;
}

int upperTriangular(struct matrix a) {
	int r = 1;
	int i = 1;
	while (i < SIZE && r) {
		int j = 0;
		while (j < i && r) {
			if (a.t [i] [j]) {
				r = 0;
			}
			j++;
		}
		i++;
	}
	return r;
}

int lowerTriangular(struct matrix a) {
	int r = 1;
	int i = 1;
	while (i < SIZE && r) {
		int j = i + 1;
		while (j < SIZE && r) {
			if (a.t [i] [j]) {
				r = 0;
			}
			j++;
		}
		i++;
	}
	return r;
}

int isSymmetric(struct matrix a) {
	int r = 1;
	int i = 1;
	while (i < SIZE && r) {
		int j = i + 1;
		while (j < SIZE && r) {
			if (a.t [i] [j] != a.t [j] [i]) {
				r = 0;
			}
			j++;
		}
		i++;
	}
	return r;
}

struct matrix transpose(struct matrix a) {
	int i = 0;
	struct matrix c;
	while (i < SIZE) {
		int j = 0;
		while (j < SIZE) {
			c.t [i] [j] = a.t [j] [i];
			j++;
		}
		i++;
	}
	return c;
}

void display(struct matrix a) {
		int i = 0;
		while (i < SIZE) {
			int j = 0;
			while (j < SIZE) {
				printf("%d ", a.t [i] [j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}

int trace(struct matrix a) {
	int i = 0;
	int sum = 0;
	while (i < SIZE) {
		sum += a.t [i] [i];
		i++;
	}
	return sum;
}

int sparseMatrix(struct matrix a) {
	int bound = SIZE * SIZE / 2;
	int counter = 0;
	int i = 0;
	int r = 1;
	while (i < SIZE && r) {
		int j = 0;
		while (j < SIZE && r) {
			if (a.t [i] [j] == 0) {
				counter++;
				if (counter > bound) {
					r = 0;
				}
			}
			j++;
		}
		i++;
	}
	return !r;
}

int isIdentity(struct matrix a) {
	int i = 0;
	int r = 1;
	while (i < SIZE && r) {
		if (a.t [i] [i] != 1) {
			r = 0;
		}
		i++;
	}
	return r && upperTriangular(a) && lowerTriangular(a);
}
int main() {
	struct matrix c;
	struct matrix d;
	init(&c);
	printf("matrix c:\n");
	display(c);
	printf("---\n");
	init(&d);
	printf("matrix d:\n");
	display(d);
	printf("---\n");
	struct matrix e;
	e = sum(&c, &d);
	printf("sum:\n");
	display(e);
	e = sub(&c, &d);
	printf("substraction:\n");
	display(e);
	e = multByConstant(&c, 4);
	printf("by const:\n");
	display(e);
	e = mult(c, d);
	printf("multiplication itself:\n");
	display(e);
	int eq = areTheyEqual(c, d);
	printf("are those equal? (1 for success)\n");
	printf("%d\n", eq);
	printf("c once again\n");
	display(c);
	e = transpose(c);
	printf("transposition of c:\n");
	display(e);
	int tr = trace(c);
	printf("trace is:\n");
	printf("%d\n", tr);
	printf("is upper-Traingular (c)?\n%d\n", upperTriangular(c));
	printf("is lower-Traingular (c)?\n%d\n", lowerTriangular(c));
	printf("is symmetric (c)?\n%d\n", isSymmetric(c));
	struct matrix f;
	init(&f);
	printf("is upper-Traingular (f)?\n%d\n", upperTriangular(f));
	printf("is lower-Traingular (f)?\n%d\n", lowerTriangular(f));
	printf("is symmetric (f)?\n%d\n", isSymmetric(f));
	printf("sparse matrix (f)\n%d\n", sparseMatrix(f));
	printf("sparse matrix (d)\n%d\n", sparseMatrix(d));
	printf("identity (f)?\n%d\n", isIdentity(f));
}

/* test.txt
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

1 4 3 2 1
4 2 1 4 2
1 3 2 1 2
5 2 1 4 3
1 0 4 2 1

1 0 0 0 0
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
*/
