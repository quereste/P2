#include <iostream>

using namespace std;

class ComplexNumber {
	public:
	double re;
	double im;
	ComplexNumber() {
		re = 0;
		im = 0;
	}
	ComplexNumber(double a, double b) {
		re = a;
		im = b;
	}
	friend ostream& operator<<(ostream& os, const& ComplexNumber);
	friend istream& operator>>(istream& is, ComplexNumber& c);
	friend bool operator==(const ComplexNumber& a, const ComplexNumber& b) {
		return (a.re == b.re && a.im && b.im);
	}
	friend bool operator!=(const ComplexNumber& a, const ComplexNumber& b) {
		return (a.re != b.re || a.im != b.im);
	}
	ComplexNumber& operator=(const ComplexNumber& a) {
		re = a.re;
		im = a.im;
		return *this;
	}
	ComplexNumber& operator+=(const ComplexNumber& a) {
		re += a.re;
		im += a.im;
		return *this;
	}
	ComplexNumber& operator*=(const ComplexNumber& a) {
		double tempOne = re * a.re - im * a.im;
		double tempTwo = re * a.im + im * a.re;
		re = tempOne;
		im = tempTwo;
		return *this;
	}
	ComplexNumber& operator/=(const ComplexNumber& a) {
		double tempOne = (re * a.re + im * a.im) / (a.im * a.im + a.re * a.re);
		double tempTwo = (re * a.im - im * a.re) / (a.im * a.im + a.re * a.re);
		re = tempOne;
		im = tempTwo;
		return *this;
	} 
	ComplexNumber operator-() {
		double tempOne = -re;
		double tempTwo = -im;
		return ComplexNumber(tempOne, tempTwo);
	}
	ComplexNumber operator!() {
		return ComplexNumber(re, -im);
	}
	ComplexNumber operator++() {
		ComplexNumber a(re, im);
		re += 1;
		return a;
	} 
	ComplexNumber operator++(int) {
		ComplexNumber a(re, im);
		im += 1;
		return a;
	}
	ComplexNumber operator--(int) {
		ComplexNumber a(re, im);
		im -= 1;
		return a;
	}
	ComplexNumber operator--() {
		ComplexNumber a(re, im);
		re -= 1;
		return a;
	}
};

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
		return ComplexNumber(a.re + b.re, a.im + b.im);
}

ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b) {
		return ComplexNumber(a.re - b.re, a.im - b.im);
}

ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b) {
		return ComplexNumber(a.re * b.re - a.im * b.im, a.im * b.re + a.re * b.im);
}

ComplexNumber operator/(const ComplexNumber& a, const ComplexNumber& b) {
		return ComplexNumber((a.re + b.re + a.im * b.im) / (b.re * b.re + b.im * b.im), (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im));
}

ostream& operator<<(ostream& os, const ComplexNumber& cplx) {
	os << "(" << cplx.re << ", " << cplx.im << ")" << "\n";
	return os;
}

istream& operator>>(istream& is, ComplexNumber& cmplx) {
	is >> cmplx.re >> cmplx.im;
	return is;
}
int main() {
	ComplexNumber a(1,2);
	ComplexNumber b(2, 3);
	ComplexNumber c(1, 2);
	cout << -a << a << -(-a);
	cout << !a << !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!a;
	cout << ++a << a;
	cout << a++ << a;
	cout << --a << a;
	cout << a-- << a;
	cout << a << b;
	cout << a + b;
	cout << a - b;
	cout << a * b;
	cout << a / b;
	cout << (a == b) << endl;
	cout << (a == c) << endl;
	cout << (a != b) << endl;
	cout << (a != c) << endl;
	ComplexNumber d;
	cin >> d;
	cout << d;
	a = b;
	cout << a;
	a += a;
	cout << a;
	a = -b;
	cout << a;
	cout << b;
	a = !b;
	cout << b;
	cout << a;
}
