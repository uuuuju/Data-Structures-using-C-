//Chapter 1. Software Engineering Principles and C++ Classes

#include <string>
using namespace std;
class personType
{
public:
void print() const;
//Function to output the first name and last name in the form firstName lastName.

void setName(string first, string last);
//Function to set firstName and lastName according to the parameters.
//Postcondition: firstName = first; lastName = last

string getFirstName() const;
//Function to return the first name.
//Postcondition: The value of firstName is returned.

string getLastName() const;
//Function to return the last name.
//Postcondition: The value of lastName is returned.

personType();
//Default constructor
//Sets firstName and lastName to null strings.
//Postcondition: firstName = ""; lastName = "";

personType(string first, string last);
//Constructor with parameters.
//Sets firstName and lastName according to the parameters.
//Postcondition: firstName = first; lastName = last;

private:
string firstName; //variable to store the first name
string lastName; //variable to store the last name
};

void personType::print() const
	{
		cout << firstName << " " << lastName;
	}

void personType::setName(string first, string last)
  {
    firstName = first;
    lastName = last;
  }

string personType::getFirstName() const
  {
    return firstName;
  }
string personType::getLastName() const
	{
		return lastName;
	}
//Default constructor
personType::personType()
	{
		firstName = "";
		lastName = "";
	}
//Constructor with parameters
personType::personType(string first, string last)
	{
		firstName = first;
		lastName = last;
	}
