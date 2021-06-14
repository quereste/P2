#include <iostream>
#include <vector>
using namespace std;

class Rodent {
	public:
		virtual void jump() =0;
		virtual void walk() =0;
		
};

class Mouse: public Rodent {
	public:
	void jump() {
		cout << "mouse jumping\n";
	}
	void walk() {
		cout << "mouse walking\n";
	}
};

class Gerbil: public Rodent {
	public:
	void jump() {
		cout << "gerbil jumping\n";
	}
	void walk() {
		cout << "gerbil walking\n";
	}
};

class Hamster: public Rodent {
	public:
	void jump() {
		cout << "hamster jumping\n";
	}
	void walk() {
		cout << "hamster walking\n";
	}
};

int main() {
	Hamster hamster;
	Gerbil gerbil;
	Mouse mouse;
	{ // a
	Rodent* t [3];
		t[0] = &hamster;
		t[1] = &gerbil;
		t[2] = &mouse;
		cout << "in array\n";
		for (int i = 0; i < 3; i++) {
			t[i]->jump();
			t[i]->walk();
		}
	}
	{ // b
		vector<Rodent*> myVector;
		myVector.clear();
		myVector.push_back(&hamster);
		myVector.push_back(&gerbil);
		myVector.push_back(&mouse);
		cout << "in vector\n";
		for (int i = 0; i < 3; i++) {
			myVector[i]->jump();
			myVector[i]->walk();
		}
	}
	return 0;
}
