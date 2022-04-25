#include <iostream>
using namespace std;

int funcB(int);

int funcA(int n) {
	// cout << "A called w/ n " << n << endl;
	if (n <= 1)
		return 217;
	else
		return n + funcB(n - 2);
}

int funcB(int n) {
	// cout << "B called w/ n " << n << endl;
	if (n <= 2) {
		return 3;
	}
	else {
		if (n > 4) {
			return n * funcA(n - 5);
		}
		else
		{
			return n - funcB(n - 1);
		}
	}
}

int main() {
	cout << funcA(13);
	return 0;
}

/*
123 
*/

/*
A called w/ n 13
B called w/ n 11
A called w/ n 6
B called w/ n 4
B called w/ n 3
B called w/ n 2
123
*/
