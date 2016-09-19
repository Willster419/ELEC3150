/////////////////////////////////
// Willard Wider               //
// 09/14/16                    //
// Lab 2                       //
// Last Modified 09/19/16      //
/////////////////////////////////
//basic start to the program
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
using namespace std;
ostringstream oss;//extra string stream to allow for other types than strings to be added to an output
//declare all requried variables for this project
int systemUserQuit;
int hour;
int day;
int amPm;
string enteredDay;
char str[256];
string middleMan;

//Typedef enumerator to simplify the comparing of days
enum dayOfWeek
{
	Sunday = 0,
	Memesday = 1,
	Tuesday = 2,
	Wendsday = 3,
	Thursday = 4,
	Friday = 5,
	Saturday = 6
};

//Typedef enumerator to simplify the comparing of am and pm
enum amPmEnum
{
	am = 1,//true
	pm = 0//false
};

//method to simplifing the procedure of printing to the console
void print(string str)
{
	cout << str << "\n";
	oss.str("");
}

//method that takes an input of wether the user or system is inputting the day,
//and it returns the day in the form of an int using the typedef above
int getCurrentDay (bool fromUser)
{
	bool waiting = true;//bool delcared inside the scope of the method, but outisde the scope of the while so it can be used
	while (waiting)
	{
		//main menu/day selection
		if (fromUser)//if user is entering the day, or the system time is
		{
			print("Please input a day, lower of upper case, sunday-saturday. Yes, you have to spell it right");
			cin >> enteredDay;
		}
		else
		{
			//get system day
			time_t urmom;
			time(&urmom);//gets the number of seconds from 1/1/2000 into a time type
			struct tm * timeInfo;
			char buffer [69];//a character array of sufficient size
			timeInfo = localtime(&urmom);//converts the large number of seconds to a date and converts it to the computers local time into a tm structure variable
			strftime(buffer,69,"%A",timeInfo);//extracts the day name out of the timeInfo and puts it into a character array
			enteredDay = buffer;//dumps the character array into a string for easier comparison
		}
		if (enteredDay == "monday" || enteredDay == "Monday")
		{
			day = Memesday;
			waiting = false;
		}
		else if (enteredDay == "tuesday" || enteredDay == "Tuesday")
		{
			day = Tuesday;
			waiting = false;
		}
		else if (enteredDay == "wendsday" || enteredDay == "Wendsday")
		{
			day = Wendsday;
			waiting = false;
		}
		else if (enteredDay == "thursday" || enteredDay == "Thursday")
		{
			day = Thursday;
			waiting = false;
		}
		else if (enteredDay == "friday" || enteredDay == "Friday")
		{
			day = Friday;
			waiting = false;
		}
		else if (enteredDay == "saturday" || enteredDay == "Saturday")
		{
			day = Saturday;
			waiting = false;
		}
		else if (enteredDay == "sunday" || enteredDay == "Sunday")
		{
			day = Sunday;
			waiting = false;
		}
		//default case
		else
		{
			print("Invalid date");
		}
	}
	return day;
}

//method that gets the system of user setting the hour of the day, and returns the hour as an int
int getCurrentHour(bool fromUser)
{
	if (fromUser)
	{
		bool waiting = true;
		while (waiting)
		{
			char str[420];
			//hour selection
			print("Enter the hour as a number i.e. 4 for 4:00");
			cin >> str;
			sscanf(str,"%d",&hour);
			if (0 < hour && hour < 13)
			{
				return hour;
			}
			else
			{
				//invalid state
				print("invalid hour");
			}
		}
	}
	else
	{
		time_t urmom;
		time(&urmom);
		struct tm * timeInfo;
		char buffer [69];
		timeInfo = localtime(&urmom);
		strftime(buffer,69,"%I",timeInfo);
		sscanf(buffer,"%d",&hour);
		return hour;
	}
	return -1;
}

//like getHour and getDay, returns an int using typedefs
int getAmPm(bool fromUser)
{
	if (fromUser)
	{
		bool waiting = true;
		while (waiting)
		{
			//am pm selection
			print("Enter the am/pm modifier as am or pm");
			cin >> middleMan;
			if(middleMan == "am" || middleMan == "AM")
			{
				return am;
			}
			else if (middleMan == "pm" || middleMan == "PM")
			{
				return pm;
			}
			else
			{
				print("invalid am/pm");
			}
		}
	}
	else
	{
		time_t urmom;
		time(&urmom);
		struct tm * timeInfo;
		char buffer [69];
		timeInfo = localtime(&urmom);
		strftime(buffer,69,"%p",timeInfo);
		string temp = buffer;
		if(temp == "PM")
		{return pm;
		}
		else 
		{return am;
		}
	}
	return -1;
}

//returns an int of the inputted charactor, 0 is the "invalid int" returned
int userSystemExit()
{
	int result;
	char directInput[420];
	cin >> directInput;
	sscanf(directInput,"%d",&result);
	return result;
}

//takes the day, hour and am/pm given and prints out what I am doing that day via the decision tree.
//decisions are made via case statements in the order of day, then hour.
void timeStuff(int day, int hours, int amPmm)
{
	string thingImDoing;//string to be used later as the activity
	int realHours=hours;//creating seperate int to be converted to a easier military time style compariable format
	if(amPmm==pm)//if it's the pm time, add 12 hours to make it military time.
	{
		realHours = realHours + 12;
	}
	if(realHours == 24 && amPmm == pm)//fix to set the hours back to 12 if it is 12 pm
	{
		realHours = 12;
	}
	else if (realHours == 12 && amPmm == am)//patch to set 12 am to 0 so it's easier to compare
	{
		realHours = 0;
	}
	//DEBUG: used for giving the formatted output for direct comparison
	//oss << "day " << day << ", hour " << realHours << ", am/pm " << amPmm;
	//print(oss.str());
	switch(day)
	{//am=true, pm=false
		//using typedefs for the days as ints allows us to use case statements with values easier to read
	case Sunday:
		//determine time
		if(0 <= realHours && realHours < 2)//each comparison is set like a timeline for each hour, and is set so that
			//the beggining time of something takes precedance over the end of something at that specific hour
			//example: at 9am on sunday I am going from sleeping to church, if the user were to ask what
			//i am doign at 9am, it would give church the precedance, being the beggining of something and say "church"
		{
			thingImDoing = "laughing at drunk people";
		}
		else if(2 <= realHours && realHours < 9)
		{
			thingImDoing = "sleepping";
		}
		else if (9 <= realHours && realHours < 10)
		{
			thingImDoing = "at church";
		}
		else if (10 <= realHours && realHours < 22)
		{
			thingImDoing = " completing homework";
		}
		else if (22 <= realHours && realHours <= 24)
		{
			thingImDoing = "watching the youtubes";
		}
		else
		{
			thingImDoing = "null";
		}
		break;

	case Memesday:
		//determine time
		if(1 <= realHours && realHours < 8)
		{
			thingImDoing = "sleepping";
		}
		else if (8 <= realHours && realHours < 12)
		{
			thingImDoing = "at class";
		}
		else if (12 <= realHours && realHours < 20)
		{
			thingImDoing = "making schedules";
		}
		else if (20 <= realHours && realHours < 24)
		{
			thingImDoing = "videogames";
		}
		else
		{
			thingImDoing = "null";
		}
		break;

	case Tuesday:
		//determine time
		if(0 <= realHours && realHours < 1)
		{
			thingImDoing = "videogames";
		}
		else if (1 <= realHours && realHours < 13)
		{
			thingImDoing = "sleeping";
		}
		else if (13 <= realHours && realHours < 20)
		{
			thingImDoing = "browsing dank memes";
		}
		else if (20 <= realHours && realHours < 24)
		{
			thingImDoing = "videogames";
		}
		else
		{
			thingImDoing = "null";
		}
		break;

	case Wendsday:
		//determine time
		if(0 <= realHours && realHours < 9)
		{
			thingImDoing = "sleepping";
		}
		else if(9 <= realHours && realHours < 18)
		{
			thingImDoing = "programming";
		}
		else if(18 <= realHours && realHours < 24)
		{
			thingImDoing = "watching TV";
		}
		else
		{
			thingImDoing = "null";
		}
		break;

	case Thursday:
		//determine time
		if(0 <= realHours && realHours < 2)
		{
			thingImDoing = "going for a midnight walk";
		}
		else if(2 <= realHours && realHours < 12)
		{
			thingImDoing = "sleepping";
		}
		else if(12 <= realHours && realHours < 20)
		{
			thingImDoing = "playing videogames";
		}
		else if(20 <= realHours && realHours < 24)
		{
			thingImDoing = "eating tacos";
		}
		else
		{
			thingImDoing = "null";
		}
		break;

	case Friday:
		//determine time
		if(0 <= realHours && realHours < 1)
		{
			thingImDoing = "eating tacos";
		}
		else if(1 <= realHours && realHours < 9)
		{
			thingImDoing = "sleepping";
		}
		else if(9 <= realHours && realHours < 16)
		{
			thingImDoing = "editing wikipedia";
		}
		else if(16 <= realHours && realHours < 21)
		{
			thingImDoing = "longboarding";
		}
		else if(21 <= realHours && realHours < 24)
		{
			thingImDoing = "programming";
		}
		else
		{
			thingImDoing = "null";
		}
		break;

	case Saturday:
		//determine time
		if(0 <= realHours && realHours < 1)
		{
			thingImDoing = "programming";
		}
		else if(1 <= realHours && realHours < 10)
		{
			thingImDoing = "sleepping";
		}
		else if(10 <= realHours && realHours < 22)
		{
			thingImDoing = "playing videogames";
		}
		else if(22 <= realHours && realHours < 24)
		{
			thingImDoing = "laughing at drunk people";
		}
		else
		{
			thingImDoing = "null";
		}
		break;

	default:
		print("fatal program error");
		break;
	}
	oss << "on " << enteredDay << " at " << hours << " " << middleMan << ", I am " << thingImDoing;
	print (oss.str());
}

//just a method for setting the time
void partOne()
{
	print("see the attached scan of my thought process");
}

//the entry method for the entire code of part 2
int partTwo()
{
	//system or user or quit here
	//menu presented to the user as user input, system input, or quit the application
	print("Type 1 for user input date, 2 for system input date, 3 for quit");
	switch (userSystemExit())//the method returns an int, so that can be used as the item used for switch determination
	{
		//user input
	case 1:
		day = getCurrentDay(true);
		hour = getCurrentHour(true);
		amPm = getAmPm(true);
		timeStuff(day,hour,amPm);
		return 1;
		break;

		//system input
	case 2:
		day = getCurrentDay(false);
		hour = getCurrentHour(false);
		amPm = getAmPm(false);
		timeStuff(day,hour,amPm);
		return 1;
		break;

		//quit
	case 3:
		return 0;
		break;

		//invalid
	default:
		print("invalid request");
		break;
	}
	return -1;
}

//main entry point of the application
int main()
{
	//am=true, pm=false
	print("Lab 2: Creating a schedule");
	print("Part 1: Creating the methodology");
	partOne();
	print("Part 2: The actual code");
	while (partTwo());//will keep running the method part2 untill it returns cleanly (with a '0')
	print("run complete");
	return 0;
}