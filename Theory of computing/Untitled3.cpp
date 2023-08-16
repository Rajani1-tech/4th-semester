// C++ Program to DFA that accept strings
// which starts and end with 'a' over input(a, b)
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	// for producing different random
	// numbers every time.
	srand(time(0));

	// random length of string from 1 - 16
	// we are taking input from input stream,
	// we can take delimiter to end the string
	int max = 1 + rand() % 15;

	// generating random string and processing it
	int i = 0;
	while (i < max) {

		// producing random character over
		// input alphabet (a, b)
		char c = 'a' + rand() % 2;
		cout << c << " ";
		i++;

		// first character is 'a'
		if (c == 'a') {

			// if there is only 1 character
			// i.e. 'a'
			if (i == max)
				cout << "YES\n";

			while (i < max) {
				c = 'a' + rand() % 2;
				cout << c << " ";
				i++;

				// if character is 'a' and it
				// is the last character
				if (c == 'a' && i == max) {
					cout << "\nYES\n";
				}

				// if character is 'b' and it
				// is the last character
				else if (i == max) {
					cout << "\nNO\n";
				}
			}
		}

		// first character is 'b' so no matter
		// what the string is, it is not going
		// to be accepted
		else {
			while (i < max) {
				c = 'a' + rand() % 2;
				cout << c << " ";
				i++;
			}
			cout << "\nNO\n";
		}
	}

	return 0;
}

