#include <iostream>
using namespace std;
	
class A {
	public :
	virtual void print() {
		cout << "Base class\n";
	}
};

class B :  A {
	public :
	void print() {
		cout << "Derived class\n";
	}
};

int main() {
	A *obj1;
	obj1->print();
	B *obj2;
	obj2->print();
	return 0;
}