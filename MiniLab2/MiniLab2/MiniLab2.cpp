/////////////////////////////////
// Willard Wider               //
// 09/11/16                    //
// Mini Lab 1                  //
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
	print(" Part 2: Find the Bug");
	int number;
	cout << "Enter a number ";
	cin >> number;
	if(number = 10)
		cout << "?!?!?!" << endl;
	if(number < 10)
		cout << "!!!!!!" << endl;
	if(number > 10)
		cout << "??????" << endl;
}
void part3()
{
	print(" Part 3: What is the outcome of the following code? Explain WHY.\nint x = 5;\nif(x++ > 5)\n\tcout << 'Greater!';\nelse\n\tcout << 'Not!';");
}
void part4()
{

}
int main()
{
	print("Mini Lab 2");
	part1A();
	part1B();
	part2();
	part3();
	part4();
	print("Press enter to continue...");
	cin.get();
	cin.get();
	return 0;
}