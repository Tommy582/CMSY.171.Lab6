#include "HourlyEmployee.h"
using namespace std;


// constructor that sets hours worked and pay rate and passes
// employee id number and name to base class constructor
HourlyEmployee::HourlyEmployee(int id, 
	string name, double hours, double payRate) :Employee(id, name)
{
	setNumHours(hours);
	setPayRate(payRate);
}


// mutator function that sets number of hours worked
void HourlyEmployee::setNumHours(double hours)
{
	numHours = hours;
}

// mutator function that sets pay rate
void HourlyEmployee::setPayRate(double rate)
{
	payRate = rate;
}

// accessor function that returns hours worked
double HourlyEmployee::getNumHours() const
{
	return numHours;
}

// accessor function that returns pay rate
double HourlyEmployee::getPayRate() const
{
	return payRate;
}

void HourlyEmployee::printPay()
{
	cout << "The pay for the hourly employee " << getName()
		<< " with ID number " << getID()
		<< " is $" << fixed << setprecision(2) << showpoint
		<< getNumHours() * getPayRate() << noshowpoint << endl;

}