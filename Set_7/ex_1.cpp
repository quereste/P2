#include <iostream>

using namespace std;

class Shape {
	public:
	virtual void draw() = 0;
	Shape() {
		cout << "Shape constructor\n";
	}
	~Shape() {
		cout << "Shape destructor\n";
	}
};

class Rectangle: public Shape {
	public:
	void draw() {
		cout << "Drawing a rectangle\n";
	}
	Rectangle() {
		cout << "Rectangle constructor\n";
	}
	~Rectangle() {
		cout << "Rectangle destructor\n";
	}
};

class Square: public Shape {
	public:
	void draw() {
		cout << "Drawing a square\n";
	}
	Square() {
		cout << "Square constructor\n";
	}
	~Square() {
		cout << "Square destructor\n";
	}
};

class Circle: public Shape {
	public:
	void draw() {
		cout << "Drawing a circle\n";
	}
	Circle() {
		cout << "Circle constructor\n";
	}
	~Circle() {
		cout << "Circle destructor\n";
	}
};

int main() {
	Circle a;
	a.draw();
	Rectangle b;
	b.draw();
	{
		Square c;
		c.draw();
	}
	return 0;
}
