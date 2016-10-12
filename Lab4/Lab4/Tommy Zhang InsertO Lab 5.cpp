/******************************************
*   Template by Aaron Carpenter
*   ELEC 3150 - OOPs
*   EET Dept., WIT
*   Tic-Tac-Toe Lab (#6)
*	Prepared by Tommy Zhang on 10/3/2016
******************************************/

//#include <iostream>
//using namespace std;
/*
void printTTT(char (&TTTarray)[3][3]) {

	cout << TTTarray[0][0] << TTTarray[0][1] << TTTarray[0][2] << endl;
	cout << TTTarray[1][0] << TTTarray[1][1] <<	TTTarray[1][2] << endl;
	cout << TTTarray[2][0] << TTTarray[2][1] << TTTarray[2][2] << endl;
}	//ends PrintTTT function
	
void insertO (char (&TTTarray)[3][3]) {			//makes an optimized move in response to X
	//these first if and else if's are in case there are two X's and we want to prevent a win.
	if (TTTarray[0][0] == 'X' && TTTarray[0][2] == 'X' && TTTarray[0][1] == '-'){	//horizontal row 1
		TTTarray[0][1] = 'O';		//place a O if between X's
		}	//ends if statement
	
	else if (TTTarray[0][0] == 'X' && TTTarray[2][0] == 'X' && TTTarray[1][0] == '-') {	//vertical column 1
		TTTarray[1][0] = 'O';
	}//ends else if statement

	else if (TTTarray[0][2] == 'X' && TTTarray[2][2] == 'X' && TTTarray[1][2] == '-') {	//vertical column 3
		TTTarray[1][2] = 'O';
	}//ends else if statement
	
	else if (TTTarray[2][0] == 'X' && TTTarray[2][2] == 'X' && TTTarray[2][1] == '-') {	//horizontal row 3
		TTTarray[2][1] = 'O';
	}//ends else if statement

	else if (TTTarray[0][1] == 'X' && TTTarray[2][1] == 'X' && TTTarray[1][1] == '-') {	//vertical column 2
		TTTarray[1][1] = 'O';
	}//ends else if statement
	
	else if (TTTarray[1][0] == 'X' && TTTarray[1][2] == 'X' && TTTarray[1][1] == '-') {	//horizontal row 2
		TTTarray[1][1] = 'O';
	}//ends else if statement
	
	//*************************************************************
	
	// if defense not needed, place an X somewhere empty :D
	else if (TTTarray[0][0] == '-') {
		TTTarray[0][0] = 'O';
	}//ends else if statement
		
		else if (TTTarray[0][1] == '-') {
		TTTarray[0][1] = 'O';
	}//ends else if statement
	
		else if (TTTarray[0][2] == '-') {
		TTTarray[0][2] = 'O';
	}//ends else if statement
		
		else if (TTTarray[1][0] == '-') {
		TTTarray[1][0] = 'O';
	}//ends else if statement
		
		else if (TTTarray[1][1] == '-') {
		TTTarray[1][1] = 'O';
	}//ends else if statement
		
		else if (TTTarray[1][2] == '-') {
		TTTarray[1][2] = 'O';
	}//ends else if statement
		
		else if (TTTarray[2][0] == '-') {
		TTTarray[2][0] = 'O';
	}//ends else if statement
		
		else if (TTTarray[2][1] == '-') {
		TTTarray[2][1] = 'O';
	}//ends else if statement
		
		else if (TTTarray[2][2] == '-') {
		TTTarray[2][2] = 'O';
	}//ends else if statement
	
	//*************************************************************	
	//else {
	//	return 0;	//if no available places to place X, then return to main and end program
	//}//ends else statement
}	//ends insertO function
	
	*/

/*
void insertX(char (&TTTarray)[3][3]) {
	
	int r=0;		//row
	int c=0;		//column
/*	//erased algorithm for blocking
	if (TTTarray[0][0] == 'X' && TTTarray[0][2] == 'X' && TTTarray[0][1] == '-'){	//horizontal row 1
		TTTarray[0][1] = 'O';		//place a O if between X's
		}	//ends if statement
	
	else if (TTTarray[0][0] == 'X' && TTTarray[2][0] == 'X' && TTTarray[1][0] == '-') {	//vertical column 1
		TTTarray[1][0] = 'O';
	}//ends else if statement

	else if (TTTarray[0][2] == 'X' && TTTarray[2][2] == 'X' && TTTarray[1][2] == '-') {	//vertical column 3
		TTTarray[1][2] = 'O';
	}//ends else if statement
	
	else if (TTTarray[2][0] == 'X' && TTTarray[2][2] == 'X' && TTTarray[2][1] == '-') {	//horizontal row 3
		TTTarray[2][1] = 'O';
	}//ends else if statement

	else if (TTTarray[0][1] == 'X' && TTTarray[2][1] == 'X' && TTTarray[1][1] == '-') {	//vertical column 2
		TTTarray[1][1] = 'O';
	}//ends else if statement
	
	else if (TTTarray[1][0] == 'X' && TTTarray[1][2] == 'X' && TTTarray[1][1] == '-') {	//horizontal row 2
		TTTarray[1][1] = 'O';
	}//ends else if statement
	
	cout << "This is the current Tic-Tac-Toe table. You are X's." << endl << "The format of the rows and columns go 0 1 2 not 1 2 3." << endl << "Please enter the row you want to place your X in: \n";
	cin >> r;
	cout << "Now enter which column you want to put your X in: " << endl;
	cin >> c;
	cout << endl;
	
	TTTarray[r][c] = 'X';
	
	insertO(TTTarray);	//this goes to insertO function that will make an optimized move in response to X
	
	cout << "Opponent O has made a move and this is how the board looks like now: " << endl;
	
	printTTT(TTTarray);
	
	insertX(TTTarray);
	}	//ends insertO
	*/

//void checkForWin(/*PASS BY REFERENCE*/); // IGNORE THIS FOR NOW
/*
int main( ){
	
    char TTTarray[3][3] = {  {'-','-','-'},
							 {'-','-','-'},
							 {'-','-','-'}};

    //char TTTarray[3][3] = { {'-','X','-'},
    //                        {'-','X','-'},
    //                        {'-','-','O'}};

    //char TTTarray[3][3] = { {'-','-','-'},
    //                        {'-','X','-'},
    //                        {'-','O','-'}};

    //char TTTarray[3][3] = { {'X','-','X'},
    //                       {'-','-','-'},
    //                        {'O','-','-'}};
							
    //char TTTarray[3][3] = { {'X','-','X'},
    //                        {'O','X','-'},
    //                        {'O','-','O'}};

	
	printTTT(TTTarray);

    insertX(TTTarray);


    /*****************
    I have included the declaration of the TTTarray, initialized to - for each spot.
    The '-' represents an empty position.  You should fill it with either a 
    capital 'O' or a capital 'X'. I have also included a number of initialized TTTarrays 
    to test; just comment out the ones you don't want for that moment
    ****************
    return 0;   
}
*/


//check for win, aka while not win put O
