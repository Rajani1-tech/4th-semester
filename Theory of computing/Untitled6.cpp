// C# Program to DFA that accepts
// string if it starts and end with
// same character
using System;
using System.Collections;
class GFG{
	
// vector to store state transition
static ArrayList state_transition =
				new ArrayList();
	
// end position is checked using
// string length value.
// q0 is the starting state.
// q2 and q4 are intermediate
// states. q1 and q3 are final
// states.	
static bool q1(string s, int i)
{
state_transition.Add("q1");
if (i == s.Length)
{
	return false;
}

// state transitions
// a takes to q1, b
// takes to q2
if (s[i] == 'a')
	return q1(s, i + 1);
else
	return q2(s, i + 1);
}

static bool q2(string s, int i)
{
state_transition.Add("q2");
if (i == s.Length)
{
	return true;
}

// state transitions
// a takes to q1, b takes to q2
if (s[i] == 'a')
	return q1(s, i + 1);
else
	return q2(s, i + 1);
}
	
static bool q3(string s, int i)
{
state_transition.Add("q3");
if (i == s.Length)
{
	return false;
}

// state transitions
// a takes to q4, 1
// takes to q3
if (s[i] == 'a')
	return q4(s, i + 1);
else
	return q3(s, i + 1);
}
	
static bool q4(string s, int i)
{
state_transition.Add("q4");
if (i == s.Length)
{
	return true;
}

// state transitions
// a takes to q4, b
// takes to q3
if (s[i] == 'a')
	return q4(s, i + 1);
else
	return q3(s, i + 1);
}
	
static bool q0(string s, int i)
{
state_transition.Add("q0");
if (i == s.Length)
{
	return false;
}

// state transitions
// a takes to q1, b
// takes to q3
if (s[i] == 'a')
	return q1(s, i + 1);
else
	return q3(s, i + 1);
}
	
// Driver code
public static void Main (string[] args)
{
string s = "ababab";

// all state transitions are
// printed. If string is
// acceptable, print YES.
// else NO is printed
bool ans = q0(s, 0);

if (ans == true)
{
	Console.Write("YES\n");

	// print transition state
	// of given string str
	for(int index = 0;
			index < state_transition.Count;
			index++)
	{
	//(auto& it : ) {
	Console.Write(
	(string)state_transition[index] + ' ');
	}
}
else
	Console.Write("NO");
}
}

// This code is contributed bt rutvik_56

