#include <iostream>
#define L 16
using namespace std;

void display(unsigned short a) {
	unsigned short temp = (1 << (L - 1));
	int i = 1;
	while (i <= L) {
		if (temp & a) {
			cout << i << " ";
		}
		temp = temp >> 1;
		i++;
	}
	cout << endl;
}

unsigned short int sum(unsigned short a, unsigned short b) {
	return a | b;
}

unsigned short complement(unsigned short c) {
	return ~c;
}

unsigned short intersection(unsigned short a, unsigned short b) {
	return a & b;
}

unsigned short difference(unsigned short a, unsigned short b) {
	return intersection(a, complement(b));
}

unsigned short symDifference(unsigned short a, unsigned short b) {
	return sum(difference(a, b), difference(b, a));
}

bool belongs(unsigned short a, int place) {
	unsigned short temp = 1 << L - place;
	bool x = (a & temp);
	return x;
}

void add(unsigned short* set, int element) {
	unsigned short temp = 1 << L - element;
	*set = *set | temp;
}

void remove(unsigned short* set, int element) {
	unsigned short temp = 1 << L - element;
	temp = ~temp;
	*set = *set & temp;
}

int card(unsigned short set) {
	int i = 0;
	unsigned short temp = 1;
	int card = 0;
	while (i < L) {
		if (set & temp) {
			card++;
		}
		temp = temp << 1;
		i++;
	}
	return card;
}
int main() {
	unsigned short a = 123;
	unsigned short b = 19;
	
	display(a);
	display(b);
	
	cout << "sum: ";
	display(sum(a, b));
	
//	c = complement(c);
	
//	display(c);
	
	
	cout << "intersection: ";
	display(intersection(a, b));
	
	
	cout << "difference: ";
	display(difference(a, b));
	
	cout << "symmetric difference: ";
	display(symDifference(a, b));
	
	cout << "12 belongs to a? ";
	cout << (belongs(a, 12)) << endl;
	
	cout << "5 belongs to a? ";
	cout << (belongs(a, 5)) << endl;
	
	cout << "a is: ";
	display(a);
	add(&a, 1);
	display(a);
	remove(&a, 1);
	display(a);
	
	cout << "cardinality of a is: " << card(a);
	
}
