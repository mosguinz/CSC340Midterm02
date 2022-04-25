#include <iostream>
using namespace std;

class Name {
public:
	Name() {}
	~Name() {
		cout << "~Destructor called on " << this << endl;
	}
private:
	string name{ "CS" };
};

shared_ptr<Name> func() {
	unique_ptr<Name> obj{ make_unique<Name>() };

	// #1 Insert Code
	return shared_ptr<Name>{move(obj)};
}

int main() {

	// #2 Insert Code
	weak_ptr<Name> wPtr1{ func() };
	if (!wPtr1.expired())
	{
		cout << "obj is at: " << wPtr1.lock() << endl;
	}
	else {
		cout << "obj destroyed" << endl;
	}

	// -OR-
	// #2 Insert Code
	cout << endl << endl;

	shared_ptr<Name> sPtr2{ func() };
	weak_ptr<Name> wPtr2{ sPtr2 };
	if (!wPtr2.expired())
	{
		cout << "obj is at: " << wPtr2.lock() << endl;
	}
	else {
		cout << "obj destroyed" << endl;
	}


	// -OR-
	// #2 Insert Code
	cout << endl << endl;

	shared_ptr<Name> sPtr3{ func() };

	if (!sPtr3.use_count() == 0)
	{
		cout << "obj is at: " << sPtr3.get() << endl;
	}
	else {
		cout << "obj destroyed" << endl;
	}

	// -OR-
	// Multiple correct answers accepted
	cout << endl << endl;
	
	cout << "END OF PROGRAM" << endl;

	return 0;
}
/*
~Destructor called on 00D12508
obj destroyed


obj is at: 00D12AF0


obj is at: 00D12508


END OF PROGRAM
~Destructor called on 00D12508
~Destructor called on 00D12AF0
*/