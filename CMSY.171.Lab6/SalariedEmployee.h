#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H
#include "Employee.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// global constants
const int numWeeks = 52;// number of weeks in a year

class SalariedEmployee :public Employee
{
private:
	double salary;				// yearly salary
public:
	// constructor that takes employee id, name, and salary
	SalariedEmployee(int, string, double);
	void setSalary(double);		// mutator that sets salary
	double getSalary() const;	// accessor that gets salary
	virtual void printPay();	// prints out employee info
};
#endif