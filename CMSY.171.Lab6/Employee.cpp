#include "Employee.h"
#include <string>
using namespace std;

// constructor that sets employee id number and name
Employee::Employee(int id, string name)
{
	setID(id);
	setName(name);
}

// mutator function that sets employee id
void Employee::setID(int id)
{
	idNum = id;
}

// mutator function that sets employee name
void Employee::setName(string name)
{
	employeeName = name;
}

// accessor function that returns employee id
int Employee::getID() const
{
	return idNum;
}

// accessor function that returns employee name
string Employee::getName() const
{
	return employeeName;
}