/////////////////////////////////
// Willard Wider               //
// 10/12/16                    //
// Mini Lab 5                  //
// Last Modified 10/12/16      //
/////////////////////////////////

//includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "LabAPI.h"
#include <cstdlib>

//defines


//constants
const int ARRAY_SIZE = 5;

//method header things
void part1();
void part2();
void part3(char (&stack)[5]);
void part4(char (&Q)[5]);

//other
using namespace std;

//part 1
void part1()
{
	print("Part 1");
	print();
	char theString[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',};
	char* pointer = theString;
	for (int i = 0; i < 8; i++)
	{
		cout << "char " << i << " is " << *pointer << "\n";
		pointer++;
	}
}

//part 2
void part2()
{
	print("part 2");
	print();
	print("changing it to a double array would change the ammount of bits required to be skipped with each ++");
	print("i.e. it would increment by the wrong index and print garbage");
}

//part 3
void part3(char (&stack)[5])
{
	char temp;
	print("part 3: LIFO (Stack)");
	print();

	print("Writing A...");
	push(stack,'A',ARRAY_SIZE);
	printArray(stack,ARRAY_SIZE);
	print();

	print("Writing B...");
	push(stack,'B',ARRAY_SIZE);
	printArray(stack,ARRAY_SIZE);
	print();

	print("Reading...");
	temp = pop(stack,ARRAY_SIZE);
	print("Dequeued element was", temp);
	print();
	printArray(stack,ARRAY_SIZE);
	print();

	print("Writing C...");
	push(stack,'C',ARRAY_SIZE);
	printArray(stack,ARRAY_SIZE);
	print();

	print("Reading...");
	temp = pop(stack,ARRAY_SIZE);
	print("Dequeued element was" , temp);
	print();
	printArray(stack,ARRAY_SIZE);
	print();

	print("Writing D...");
	push(stack,'D',ARRAY_SIZE);
	printArray(stack,ARRAY_SIZE);
	print();
}

//part 4
void part4(char (&Q)[5])
{
	char temp;
	print("part 4: FIFO (Queue)");
	print();

	print("Writing A...");
	enqueue(Q,'A',ARRAY_SIZE);
	printArray(Q,ARRAY_SIZE);
	print();

	print("Writing B...");
	enqueue(Q,'B',ARRAY_SIZE);
	printArray(Q,ARRAY_SIZE);
	print();

	print("Reading...");
	temp = dequeue(Q,ARRAY_SIZE);
	print("Dequeued element was" , temp);
	print();
	printArray(Q,ARRAY_SIZE);
	print();

	print("Writing C...");
	enqueue(Q,'C',ARRAY_SIZE);
	printArray(Q,ARRAY_SIZE);
	print();

	print("Reading...");
	temp = dequeue(Q,ARRAY_SIZE);
	print("Dequeued element was" , temp);
	print();
	printArray(Q,ARRAY_SIZE);
	print();

	print("Writing D...");
	enqueue(Q,'D',ARRAY_SIZE);
	printArray(Q,ARRAY_SIZE);
	print();
}

//the main entry point of the application
int main()
{
	char Q[5] = {0};
	char stack[5] = {0};//look at me being all cool with pass by refrence
	print("Mini Lab 6");
	print();
	part1();
	print();
	part2();
	print();
	part3(stack);
	print();
	part4(Q);
	print();
	run_complete();
	return 0;
}