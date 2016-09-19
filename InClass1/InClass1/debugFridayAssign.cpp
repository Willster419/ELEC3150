/* 	For ELEC 3150 - Object Oriented Programming
	Wentworth Institute of Technology
	Prof. Aaron Carpenter
*/

#include "debugFridayAssign.h"

int main() {
	
	srand(time(0));

	int seed = rand( ) % 100;

	initializeArrays(seed);

	int i = ARRAY_SIZE-1;
	

	while(i)
	{
		int j = ARRAY_SIZE-1; 
		while(j) 
		{
			int temp = daxpy(array1[i][j], array2[i][j]);
			cout << "var assigned to result index " << i << " , " << j << " is " << temp << "\n";
			resultArray[i][j] = temp;	
			j--;
		}
		i--;
	}
	
	printArrays();


	return 0; //Nothing needed to return

}
