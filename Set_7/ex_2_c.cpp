#include <iostream>
#include <vector>
using namespace std;

class Rodent {
	public:
		void jump() {
			cout << "jumping\n";
		}
		void walk() {
			cout << "walking\n";
		}
		
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

class BlueHamster: public Hamster {
	public:
	void jump() {
		cout << "blue hamster jumping\n";
	}
	void walk() {
		cout << "blue hamster walking\n";
	}
};

int main() {
	Hamster hamster;
	Gerbil gerbil;
	Mouse mouse;
	BlueHamster blueHamster;
	{ // a
	Rodent* t [4];
		t[0] = &hamster;
		t[1] = &gerbil;
		t[2] = &mouse;
		t[3] = &blueHamster;
		cout << "in array\n";
		for (int i = 0; i < 4; i++) {
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
		myVector.push_back(&blueHamster);
		cout << "in vector\n";
		for (int i = 0; i < 4; i++) {
			myVector[i]->jump();
			myVector[i]->walk();
		}
	}
	return 0;
}
