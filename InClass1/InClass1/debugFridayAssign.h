/* 	For ELEC 3150 - Object Oriented Programming
	Wentworth Institute of Technology
	Prof. Aaron Carpenter
*/

#ifndef _DEBUG_EXAMPLE_H
#define _DEBUG_EXAMPLE_H

#include <iostream>  
#include <time.h>
#include <cmath>
#include <cstdlib>
#define ARRAY_SIZE 4

const double a = 2;

double array1[ARRAY_SIZE][ARRAY_SIZE] = {0};
double array2[ARRAY_SIZE][ARRAY_SIZE] = {0};
double resultArray[ARRAY_SIZE][ARRAY_SIZE] = {0};

using namespace std; 

double daxpy(double x, double y){
	int result = a*x+y;
	return result;
} 

void initializeArrays(int seed){
	//cout << "seed is " << seed << "\n";
	for(int i = 0; i < ARRAY_SIZE; i++) 
	{
		for(int j = 0; j < ARRAY_SIZE; j++) 
		{
			array1[i][j] = i*seed/(j+1.5);
			array2[i][j] = j*seed-2*i;
		}
	}

}

void printArrays(){

	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		for(int j = 0; j < ARRAY_SIZE; j++)
		{
			cout.precision(2);
			cout << a << "*" << array1[i][j] << "+" << array2[i][j] << " = " << resultArray[i][j];			
			cout << "\t";
		}
		cout << endl;
	}

}

#endif
