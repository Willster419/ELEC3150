#include <iostream>
using namespace std;
int main(){
	int number;
	cout << "Enter a number ";
	cin >> number;
	if(number == 10)
		cout << "?!?!?!" << endl;
	if(number < 10)
		cout << "!!!!!!" << endl;
	if(number > 10)
		cout << "??????" << endl;
}