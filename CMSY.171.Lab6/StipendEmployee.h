#ifndef STIPENDEMPLOYEE_H
#define STIPENDEMPLOYEE_H
#include "Employee.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// global constants
const int numHours = 40;			// hours in a week

class StipendEmployee :public Employee
{
private:
	double totalHours;				// total hours of the stipend contract
	double totalPaid;				// total dollars paid over contract
public:
	// constructor that takes employee id, name, hours, and pay of a contract
	StipendEmployee(int, string, double, double);
	void setTotalHours(double);		// mutator that sets total hours over contract
	void setTotalPaid(double);		// mutator that sets total paid over contract
	double getTotalHours() const;	// accessor that returns total hours
	double getTotalPaid() const;	// accessor that returns total paid
	virtual void printPay();		// prints out employee info
};
#endif