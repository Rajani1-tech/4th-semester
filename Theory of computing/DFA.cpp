// C# Program to DFA that accept Strings
// which starts and end with 'a' over i.Add(a, b)
using System;

class GFG
{

static void Main(String[] args)
{

	// random length of String from 1 - 16
	// we are taking input from input stream,
	// we can take delimiter to end the String
	int max = 1 + new Random().Next()*10 % 15;

	// generating random String and processing it
	int i = 0;
	while (i < max)
	{

		// producing random character over
		// input alphabet (a, b)
		char c = (char) ('a' + new Random().Next()*10 % 2);
		Console.Write(c + " ");
		i++;

		// first character is 'a'
		if (c == 'a')
		{

			// if there is only 1 character
			// i.e. 'a'
			if (i == max)
				Console.Write("YES\n");

			while (i < max)
			{
				c = (char) ('a' + new Random().Next()*10 % 2);
				Console.Write(c + " ");
				i++;

				// if character is 'a' and it
				// is the last character
				if (c == 'a' && i == max)
				{
					Console.Write("\nYES\n");
				}

				// if character is 'b' and it
				// is the last character
				else if (i == max)
				{
					Console.Write("\nNO\n");
				}
			}
		}

		// first character is 'b' so no matter
		// what the String is, it is not going
		// to be accepted
		else
		{
			while (i < max)
			{
				c = (char) ('a' + new Random().Next()*10 % 2);
				Console.Write(c + " ");
				i++;
			}
			Console.Write("\nNO\n");
		}
	}
}
}

// This code is contributed by 29AjayKumar

