//Chapter 1. Software Engineering Principles and C++ Classes

#include<stdio.h>
#include<iostream>
using namespace std;

class clockType
{
public:

//Function Prototypes
void setTime(int hours, int minutes, int seconds);
//Function to set the time according to parameters
//Postcondition: hr = hours; min = minutes; sec = seconds
// The function checks whether the values of hours, minutes, and seconds are valid. If a value is invalid, the default value 0 is assigned.
void getTime(int& hours, int& minutes, int& seconds) const;
//Function to return the time
//Postcondition: hours = hr; minutes = min; seconds = sec
void printTime() const;
//Function to print the time
//Postcondition: Time is printed in the form hh:mm:ss.
void incrementSeconds();
//Function to increment the time by one second
//Postcondition: The time is incremented by one second.
// If the before-increment time is 23:59:59, the time is reset to 00:00:00.
void incrementMinutes();
//Function to increment the time by one minute
//Postcondition: The time is incremented by one minute.
// If the before-increment time is 23:59:53, the time is reset to 00:00:53.
void incrementHours();
//Function to increment the time by one hour
//Postcondition: The time is incremented by one hour.
// If the before-increment time is 23:45:53, the time is reset to 00:45:53.
bool equalTime(const clockType& otherClock) const;
//Function to compare the two times
//Postcondition: Returns true if this time is equal to otherClock; otherwise, returns false

private:
int hr; //stores the hours
int min; //store the minutes
int sec; //store the seconds
};
//The word const at the end of the member functions getTime, printTime, and equalTime specifies that these functions cannot modify the data members of a variable of type clockType.

clockType(int hours, int minutes, int seconds);
//Constructor with parameters. The time is set according to the parameters.
//Postconditions: hr = hours; min = minutes; sec = seconds
// The constructor checks whether the values of hours, minutes, and seconds are valid. If a value is invalid the default value 0 is assigned.
//clockType();
//Default constructor with parameters
//The time is set to 00:00:00.
//Postcondition: hr = 0; min = 0; sec = 0

int main(){
    clockType myClock;
	  myClock.setTime(5, 2, 30);
    myClock.printTime();

//clockType::clockType() default constructor{
		//hr = 0;
		//min = 0;
		//sec = 0;
}

clockType::clockType(int hours, int minutes, int seconds){
		if (0 <= hours && hours < 24)
				hr = hours;
		else
				hr = 0;
		if (0 <= minutes && minutes < 60)
				min = minutes;
		else
				min = 0;

    if (0 <= seconds && seconds < 60)
				sec = seconds;
		else
				sec = 0;
		}
}

//Function definitions
void clockType::setTime(int hours, int minutes, int seconds)
{
if (0 <= hours && hours < 24)
hr = hours;
else
hr = 0;
if (0 <= minutes && minutes < 60)
min = minutes;
else
min = 0;
if (0 <= seconds && seconds < 60)
sec = seconds;
else
sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
hours = hr;
minutes = min;
seconds = sec;
}

void clockType::printTime() const
{
if (hr < 10)
cout << "0";
cout << hr << ":";
if (min < 10)
cout << "0";
cout << min << ":";
if (sec < 10)
cout << "0";
cout << sec;
}

void clockType::incrementHours()
{
hr++;
if (hr > 23)
hr = 0;
}

void clockType::incrementMinutes()
{
min++;
if (min > 59)
  {
min = 0;
incrementHours(); //increment hours
  }
}

void clockType::incrementSeconds()
{
sec++;
if (sec > 59)
  {
sec = 0;
incrementMinutes(); //increment minutes
  }
}

bool clockType::equalTime(const clockType& otherClock) const
{
return (hr == otherClock.hr
&& min == otherClock.min
&& sec == otherClock.sec);
}
