#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include <string>
#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

class HourlyEmployee :public Employee
{
private:
	double numHours;			// hours worked
	double payRate;				// pay rate in dollars per hour
public:
	// constructor that takes id, name, hours worked, and pay rate
	HourlyEmployee(int, string, double, double);
	void setNumHours(double);	// mutator that sets hours worked
	void setPayRate(double);	// mutator that sets pay rate
	double getNumHours() const;	// accessor that returns hours worked
	double getPayRate() const;	// accessor that returns pay rate
	virtual void printPay();	// prints out employee info
};
#endif