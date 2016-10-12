#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct entry_t{
    string name;    
    time_t time;    
    entry_t *next;
};

int main(){

    string name;
    int done = 0;

    entry_t First;
    First.name = "First";
    First.time = time(0);
	First.next = 0;
    entry_t *ptr = &First;

    do {
        cout << "Type a word to add to the list: " ;
        cin >> name;    
        cout << endl;
		
		ptr->next = new entry_t;
		ptr->next->name = name;
		ptr->next->time = time(0);
		ptr->next->next = 0;
		
		for(entry_t *temp = &First; temp != 0; temp = temp->next){
			cout << temp->name << " at " << asctime(localtime(&(temp->time))) << endl; 	
		}
		ptr = ptr->next;
        cout << "Type 1 to add another or 0 to quit: ";
        cin >> done;
        cout << endl;
    } while(done);

	entry_t *tempDelete = First.next;
	entry_t *tempHolder = tempDelete->next;
	while(tempDelete != 0){
		delete tempDelete;
		tempDelete = tempHolder;
		if(tempHolder)
			tempHolder = tempHolder->next;
	}
	//delete tempDelete;
	
}