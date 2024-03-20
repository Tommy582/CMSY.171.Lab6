#include "SalariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee(int id, 
	string name, double pay):Employee(id, name)
{
	setSalary(pay);
}

void SalariedEmployee::setSalary(double pay)
{
	salary = pay;
}

double SalariedEmployee::getSalary() const
{
	return salary;
}

void SalariedEmployee::printPay()
{
	cout << "The pay for the salaried employee " << getName() << " with ID number " 
		<< getID() << " is $" << fixed << showpoint << setprecision(2) 
		<< getSalary() / static_cast<double>(numWeeks) << noshowpoint<< endl;
}