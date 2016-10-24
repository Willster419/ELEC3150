/////////////////////////////////
// Willard Wider               //
// Main.cpp                    //
// 10/24/16                    //
// Lab 7                       //
// Last Modified 10/24/16      //
/////////////////////////////////

//C library includes
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//defines
#define YEARS_ARRAY_LENGTH 4

//structs
struct qb_t;

//typedefs
typedef enum type_t;

//other definitions
using namespace std;

//method/class prototypes
class DoubleLinkedList
{
private:
	struct qb_t* master;
	struct qb_t* backup;
	void addYear(int *years, int size, int year);
	void initYearsArray(int *years, int size);

public:
	DoubleLinkedList();
	~DoubleLinkedList();
	int addQB(string fName, string lName, int year);
	int addQBFromFile(string fileName);
	int getIndex(string fN, string lN);
	void printList();
	void printList(qb_t *CustomList);
	void deleteAll(qb_t* startingPoint);
	void deleteAll();
	int deleteQB(string fN, string lN);
	int deleteQB(int index);
	int QBSize();
	int QBSize(qb_t *customList);
	string getAllWins(int *yearsWon, int size);
	qb_t* search(string fName, string lName);
	qb_t* search(int year, bool yearOrNumwinz);
	void sortList();

};