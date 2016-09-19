/////////////////////////////////
// Willard Wider               //
// 09/16/16                    //
// Mini Lab 2                  //
/////////////////////////////////
//basic start to the program
#include <iostream>
#include <string>
using namespace std;
string input;
//method to simplifing the procedure of printing to the console
void print(string str)
{
	cout << str << "\n";
}
void part1A()
{
	print("Part 1A: Grade with if else loop");
	bool done = false;
	while (!done)
	{
		print("Input a grade, A-F");
		cin >> input;//stores the input to be tested below
		if (input == "A")
		{
			print("Your grade of " + input + " is awesome. Number representation is 100-90");
			done = true;//sets the while loop to end
		}
		else if (input == "B")
		{
			print("Your grade of " + input + " is good. Number representation is 89-80");
			done = true;
		}
		else if (input == "C")
		{
			print("Your grade of " + input + " is average. Number representation is 79-70");
			done = true;
		}
		else if (input == "D")
		{
			print("Your grade of " + input + " is poor. Number representation is 69-60");
			done = true;
		}
		else if (input == "F")
		{
			print("Your grade of " + input + " is unacceptable. Comon bro, get good. Number representation is below 59");
			done = true;
		}
		else
		{
			print("not a valid grade");//inform the user that the entered value is not a grade, and try again
		}
	}
}
void part1B()
{
	print("");
	print("Part 1B: Grade with if case loop");
	bool done = false;
	while (!done)
	{
		print("Input a grade, A-F");
		char c;
		cin >> c;
		input = c;
		switch (c)//stores the input to be tested below
		{
		case 'A':
			print("Your grade of " + input + " is awesome. Number representation is 100-90");
			done = true;
			break;
		case 'B':
			print("Your grade of " + input + " is good. Number representation is 89-80");
			done = true;
			break;
		case 'C':
			print("Your grade of " + input + " is average. Number representation is 79-70");
			done = true;
			break;
		case 'D':
			print("Your grade of " + input + " is poor. Number representation is 69-60");
			done = true;
			break;
		case 'F':
			print("Your grade of " + input + " is unacceptable. Number representation is below 59");
			done = true;
			break;
		default:
			print("not a valid grade");
		}
	}
}
void part2()
{
	print("");
	print("Part 2: answer is commented in the method part2()");
	print("long story short it's about = vs. ==");
	//<---
	/*
	#include <iostream>
	using namespace std;
	int main(){
		int number;
		cout << "Enter a number ";
		cin >> number;
		if(number = 10)<-------------------------------- This needs to be "==". = is assignment, == is comparison
			cout << "?!?!?!" << endl;
		if(number < 10)
			cout << "!!!!!!" << endl;
		if(number > 10)
			cout << "??????" << endl;
	}*/
}
void part3()
{
	print("");
	print("Part 3: code outcome of ++x vs x++");
	/*int x = 5;
	if(x++ > 5)
		cout << "Greater!";
	else
		cout << "Not!";*/
	print("it will print 'not' because x++ means use x as it is for that line of code, and then increment if by 1. therefore x(5)>5 is false");
	
}
void part4()
{
	print("");
	print("Part 4:");
	print("If '++x' were used it would print 'greater' because it +1's x, then uses it for comparison, where 6 > 5");
}
void part5()
{
	print("");
	print("Part 5: Rank the loop types");
	print("1. For loop because it is easy to traverse arrays, and can be used as a puerly conditional statement");
	print("2. While loop because if can do the same thing as a for loop, but the condition needs to be delcared outside the scope");
	print("3. Do-While loop because it is basicly a while loop that will run at least once and i have neved needed to use one ever");
}
int main()
{
	print("Mini Lab 2");
	print("");
	part1A();
	part1B();
	part2();
	part3();
	part4();
	part5();
	print("");
	print("Press enter to continue...");
	cin.get();
	cin.get();
	return 0;
}