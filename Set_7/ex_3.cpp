#include <iostream>
#include <vector>
using namespace std;

class Aircraft {
	public:
	Aircraft() {
		
	}
	Aircraft(int a) {
		
	}
	virtual void fly() =0;
	virtual void land() =0;
	virtual void whoAmI() =0;
};

class Chopper: public Aircraft {
	int id;
	public:
		Chopper(int arg) {
			id = arg;
		}
		void fly() {
			cout << "chopper flying\n";
		}
		void land() {
			cout << "chopper landing";	
		}
		void whoAmI() {
			cout << "ima chopper number " << id << "\n";
		}
};

class Boeing: public Aircraft {
	int id;
	public:
		Boeing(int arg) {
			id = arg;
		}
		void fly() {
			cout << "boeing flying\n";
		}
		void land() {
			cout << "boeing landing";	
		}
		void whoAmI() {
			cout << "ima boeing number " << id << "\n";
		}
};

class Eurofighter: public Aircraft {
	public:
	int id;
		Eurofighter(int arg = 1) {
			id = arg;
		}
		void fly() {
			cout << "Eurofighter flying\n";
		}
		void land() {
			cout << "Eurofighter landing";	
		}
		void whoAmI() {
			cout << "ima Eurofighter number " << id << "\n";
		}
};

class Tower {
	public:
		vector<Aircraft*> xd;
		void letGo() {
			if (!xd.empty()) {
				xd.back()->fly();
				xd.pop_back();
			}
		}
		void ask(int arg) {
			if (arg < xd.size()) {
				xd[arg]->whoAmI();
			}
		} 
		void welcome() {
			if (!xd.empty()) {
				xd.back()->land();
				xd.pop_back();
			}
		}
		void add(Aircraft* a) {
			xd.push_back(a);
		}
};
int main() {
	Tower tower;
	Eurofighter a(1), b(4), c(41), d(37);
	tower.add(&a);
	tower.add(&b);
	tower.add(&c);
	tower.add(&d);
	Chopper mB(2);
	tower.add(&mB);
	Boeing bb(132);
	tower.add(&bb);
	int counter = 0;
	while (!tower.xd.empty()) {
		if (counter % 3 == 0) {
			tower.ask(counter);
		} else if (counter % 3 == 1) {
			tower.letGo();
		} else {
			tower.welcome();
		}
		counter++;
	}
}
