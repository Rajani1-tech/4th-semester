// C code to implement the above approach
#include <stdio.h>
#include <string.h>

// Driver code
int main()
{

	// Input string
	char str[20] = { 'c', 'a', 'b', 'c' };
	int q = 0, prev_q;
	for (int i = 0; i < strlen(str); i++) {

		// To check if the string is
		// valid or not
		if (str[i] != 'a' && str[i] != 'b'
			&& str[i] != 'c') {
			printf("Given string is invalid.\n");
			return 0;
		}

		// Store the previous state before
		// updating it
		prev_q = q;

		// Update the state based on the
		// transition function
		switch (q) {
		// At state q0, if character
		// is 'a' then move to q1
		case 0:
			q = (str[i] == 'a') ? 1 : 0;
			break;

		// At state q1, if character
		// is 'b' then move to q2 else
		// if the character is 'a' then
		// remain in same state else
		// move to q0
		case 1:
			q = (str[i] == 'b') ? 2
								: (str[i] == 'a') ? 1 : 0;
			break;

		// At state q2, if character
		// is 'c' then move to q3 else
		// if the character is 'a' then
		// move to q1 state else
		// move to q0
		case 2:
			q = (str[i] == 'c') ? 3
								: (str[i] == 'a') ? 1 : 0;
			break;

		// At state q3, if character
		// is 'a' then move to q1 else
		// move to q0
		case 3:
			q = (str[i] == 'a') ? 1 : 0;
			break;
		}
	}

	// Check if the dfa machine reached
	// the final state
	if (q == 3)
		printf("ACCEPTED\n");
	else
		printf("NOT ACCEPTED\n");
	return 0;
}

