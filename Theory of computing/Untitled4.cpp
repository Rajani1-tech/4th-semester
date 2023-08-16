// C# program to check if
// a string either starts
// or ends with 01
using System;
using System.Collections;
using System.Collections.Generic;
class GFG{
	
// Function for transition
// state A
static void checkstateA(string n)
{
// State transition to
// B if the character is
// 0
if(n[0] == '0')
	stateB(n.Substring(1));

// State transition to
// D if the character is
// 1
else
	stateD(n.Substring(1));
}

// Function for transition
// state B		
static void stateB(string n)
{	
// Check if the string has
// ended
if (n.Length == 0)
{
	Console.Write("string not accepted");
}
else
{
	// State transition to C
	// if the character is 1
	if(n[0] == '1')
	stateC(n.Substring(1));

	// State transition to D
	// if the character is 0
	else
	stateD(n.Substring(1));
}	
}

// Function for transition
// state C
static void stateC(string n)
{
Console.Write("string accepted");
}

// Function for transition
// state D
static void stateD(string n)
{
if (n.Length == 0)
	Console.Write("string not accepted");
else
{

	// State transition to D
	// if the character is 1
	if (n[0] == '1')
	stateD(n.Substring(1));

	// State transition to E
	// if the character is 0
	else
	stateE(n.Substring(1));
}
}

// Function for transition
// state E
static void stateE(string n)
{
if (n.Length == 0)
	Console.Write("string not accepted");
else
{

	// State transition to E
	// if the character is 0
	if(n[0] == '0')
	stateE(n.Substring(1));

	// State transition to F
	// if the character is 1
	else
	stateF(n.Substring(1));
}
}

// Function for transition
// state F
static void stateF(string n)
{
if(n.Length == 0)
	Console.Write("string accepted");
else
{
	// State transition to D
	// if the character is 1
	if(n[0] == '1')
	stateD(n.Substring(1));

	// State transition to E
	// if the character is 0
	else
	stateE(n.Substring(1));
}
}

// Driver code
public static void Main(string []args)
{
string n = "0100101";
checkstateA(n);
}
}

// This code is contributed by rutvik_56

