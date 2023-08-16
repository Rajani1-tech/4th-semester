// C# implementation of the approach

using System;

public class GFG {

	// Function that returns the index of next occurrence
	// of the character c in string str starting from index start
	static int nextIndex(string str, int start, char c)
	{

		// Starting from start
		for (int i = start; i < str.Length; i++) {

			// If current character = c
			if (str[i] == c)
				return i;
		}

		// Not found
		return -1;
	}

	// Function to return the count of required sub-strings
	static int countSubStrings(string str)
	{
		int i, n = str.Length ;

		// Stores running count of 'x' starting from the end
		int []countX = new int[n];

		int count = 0;
		for (i = n - 1; i >= 0; i--) {
			if (str[i] == 'x')
				count++;
			countX[i] = count;
		}

		// Next index of 'x' starting from index 0
		int nextIndexX = nextIndex(str, 0, 'x');

		// Next index of 'y' starting from index 0
		int nextIndexY = nextIndex(str, 0, 'y');

		// To store the count of required sub-strings
		count = 0;
		while (nextIndexX != -1 && nextIndexY != -1) {

			// If 'y' appears before 'x'
			// it won't contribute to a valid sub-string
			if (nextIndexX > nextIndexY) {

				// Find next occurrence of 'y'
				nextIndexY = nextIndex(str, nextIndexY + 1, 'y');
				continue;
			}

			// If 'y' appears after 'x'
			// every sub-string ending at an 'x' appearing after this 'y'
			// and starting with the current 'x' is a valid sub-string
			else {
				count += countX[nextIndexY];

				// Find next occurrence of 'x'
				nextIndexX = nextIndex(str, nextIndexX + 1, 'x');
			}
		}

		// Return the count
		return count;
	}

	// Driver code
	public static void Main()
	{

		string s = "xyyxx";

		Console.WriteLine(countSubStrings(s));
	}
	// This code is contributed by Ryuga
}

