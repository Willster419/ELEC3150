/////////////////////////////////
// Willard Wider               //
// LabAPI.h                    //
// 09/21/16                    //
// General Lab Assistance File //
// Last Modified 11/09/16      //
/////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//header guard
#ifndef LAB_API_H
#define LAB_API_H

//other definitions
using namespace std;


//method/class prototypes

//method to simplifing the procedure of printing to the console
void print(string str);

//method to simplifing the procedure of printing to the console
//void print(unsigned char c);

//method to provide a blank space
void print();

void print(string text, char value);

void print(string text, int value);

void print(string text, float value);

void printPointer(char *refChar);

void printPointer(int *refInt);

void printPointer(float *refFloat);

void printPointer(double *refDub);

//returns the size of the character array of characters that are in use
int size(char temp[]);

//returns the size of the character array of characters that are in use
int size(int temp[]);

//returns the size of the character array of characters that are in use
int size(unsigned char temp[]);

//swapps all the items of a given array from top and bottom
//same logic as lab 1
string swapString (string stringToSwap);

void run_complete( string message);

void printArray (int arrayToPrint[],int size);

void printArray (char arrayToPrint[],int size);

//returns the index of where the the specified item of search is
int binarySearch(int theArray[],int size,int search);

//sorts an array using ubble sort
void bubbleSort(int theArray[],int size);

//puts an item in stack of an array
//1 = was put in, 0 = array was full
int push(char (&stack)[5], char value, int size);

//takes an item out of stack of an array
char pop(char (&stack)[5], int size);

//puts an item in queue of an array
//1 = was put in, 0 = array was full
int enqueue(char (&Q)[5], char value, int size);

//takes an item out of queue of an array
char dequeue(char (&Q)[5], int size);

string int2String (int intToConvert);

//create the log file
void createLogFile();

//appends to a log file
void appendLog(string text);

//creates a blank vector of type string


#endif