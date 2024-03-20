#include "StipendEmployee.h"

// constructor that takes employee id, name, total hours, and total paid
StipendEmployee::StipendEmployee(int id, 
	string name, double hours, double paid) :Employee(id, name)
{
	setTotalHours(hours);
	setTotalPaid(paid);
}

// mutator that sets total hours
void StipendEmployee::setTotalHours(double hours)
{
	totalHours = hours;
}

// mutator that sets total paid over contract
void StipendEmployee::setTotalPaid(double paid)
{
	totalPaid = paid;
}

// accessor that gets total hours
double StipendEmployee::getTotalHours() const
{
	return totalHours;
}

// accessor that gets total paid
double StipendEmployee::getTotalPaid() const
{
	return totalPaid;
}

// prints employee info
void StipendEmployee::printPay()
{
	cout << "The pay for the stipend employee " << getName() << " with ID number "
		<< getID() << " is $" << fixed << showpoint << setprecision(2)
		<< getTotalPaid() / (getTotalHours() / static_cast<double>(numHours))
		<< noshowpoint << endl;
}