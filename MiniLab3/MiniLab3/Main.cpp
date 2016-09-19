/////////////////////////////////
// Willard Wider               //
// 09/19/16                    //
// Mini Lab 3                  //
// Last Modified 09/19/16      //
/////////////////////////////////
//first start, declare all dependancies
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
ostringstream oss;//extra string stream to allow for other types than strings to be added to an output
//method to simplifing the procedure of printing to the console
void print(string str)
{
	cout << str << "\n";
	oss.str("");
}
//main entry point of the application
int main() {
	print("Part 1: Explaining the algorithem in comments");
	print("See the comments in this code");
	/*cout << "5 numbers";			//prints out five numbers
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;	//takes in 5 values for input
	int x;
	x = a + b + c + d + e;			//adds all the numbers together
	int f;
	f = x/5;						//divids all the numbers by the number of inputed values
									//this appears to be an averaging algorithem using integer math*/
}