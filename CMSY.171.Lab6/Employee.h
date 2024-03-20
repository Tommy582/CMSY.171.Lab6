#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private:
	int idNum;					// holds employee id number
	string employeeName;		// holds employee name
public:
	Employee(int, string);		// constructor that takes id number and name
	void setID(int);			// mutator function to set id number
	void setName(string);		// mutator function to set name
	int getID() const;			// accessor function to get id number
	string getName() const;		// accessor function to get name
	virtual void printPay() = 0;// virtual function
};
#endif