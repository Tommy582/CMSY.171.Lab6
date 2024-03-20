// Program written by Tommy Trinh
// March 20, 2024
// This program keeps track of 3 types of employee's pay
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "StipendEmployee.h"
using namespace std;

// global constants
const int
TYPE_SIZE=10,			// c string size
MIN_ID = 100000,		// minimum id number
MAX_ID = 999999,		// maximum id number
MINIMUM=0,				// minumum number
HOURLY_CHOICE = 1,		// menu choice for hourly employee
SALARIED_CHOICE = 2,	// menu choice for salaried employee
STIPEND_CHOICE = 3,		// menu choice for stipend employee
QUIT_CHOICE = 4;		// menu choice for quit

// function prototypes
void header();									// displays program information
void getInput(vector<Employee*>& Ve);			// 
void printList(const vector<Employee*>& Ve);	//
bool menuValid(int);							// validates menu choice
bool idValid(int);								// validates id number
bool minValid(int);								// validates number above min
bool minValid(double);							// validates min but double version
bool exitProgram();								// validates user wants to exit

int main()
{
	header();				// call header
	vector<Employee*> Ve;	// new vector of employees
	getInput(Ve);			// enter data for employees
	printList(Ve);			// display data for employees

	system("pause");
	return 0;
}

// displays program info
void header()
{
	cout << "\t\t\t\tCMSY 171 Lab 6\n"
		<< "Copyright 2024 - Howard Community College All rights reserved; "
		<< "Unauthorized duplication prohibited.\n\n"
		<< "\t\tWelcome to CMSY-171 Employee Weekly Pay Program\n\n";
}

// get data on employees with a menu, loop through menu until user
// selects quit
void getInput(vector<Employee*>& Ve)
{
	string input;	// temporary input string
	string name;	// temporary name string
	int id,			// temporary id string
		menuChoice;	// temporary menu choice
	double hours,	// temporary hours input
		pay;		// temporary pay input

	do
	{
		do
		{
			cout << endl << HOURLY_CHOICE << ". Hourly Employee\n"
				<< SALARIED_CHOICE << ". Salaried Employee\n"
				<< STIPEND_CHOICE << ". Stipend Employee\n"
				<< QUIT_CHOICE << ". End Program\n"
				"Enter menu choice: ";
			getline(cin, input);
		} while (menuValid(stoi(input)));
		menuChoice = stoi(input);

		switch (menuChoice)
		{
		case HOURLY_CHOICE:
		{// get id, name, hours, and pay rate
			cout << "\nEnter the employee name: ";
			getline(cin, name);
			do
			{
				cout << "Enter employee id: ";
				getline(cin, input);
			} while (idValid(stoi(input)));
			id = stoi(input);
			do
			{
				cout << "Enter hours worked: ";
				getline(cin, input);
			} while (minValid(stod(input)));
			hours = stod(input);
			do
			{
				cout << "Enter hourly rate: $";
				getline(cin, input);
			} while (minValid(stod(input)));
			pay = stod(input);
			// make a new vector and pushback
			Employee* worker = new HourlyEmployee(id, name, hours, pay);
			Ve.push_back(worker);
			break;
		}
		case SALARIED_CHOICE:
		{
			cout << "\nEnter the employee name: ";
			getline(cin, name);
			do
			{
				cout << "Enter employee id: ";
				getline(cin, input);
			} while (idValid(stoi(input)));
			id = stoi(input);
			do
			{
				cout << "Enter the salary: $";
				getline(cin, input);
			} while (minValid(stod(input)));
			pay = stod(input);
			// make a new vector and pushback
			Employee* worker = new SalariedEmployee(id, name, pay);
			Ve.push_back(worker);
			break;
		}
		case STIPEND_CHOICE:
		{
			cout << "\nEnter the employee name: ";
			getline(cin, name);
			do
			{
				cout << "Enter employee id: ";
				getline(cin, input);
			} while (idValid(stoi(input)));
			id = stoi(input);
			do
			{
				cout << "Enter stipend amount: $";
				getline(cin, input);
			} while (minValid(stod(input)));
			pay = stod(input);
			do
			{
				cout << "Enter total hours: ";
				getline(cin, input);
			} while (minValid(stod(input)));
			hours = stod(input);
			// make a new vector and pushback
			Employee* worker = new StipendEmployee(id, name, hours, pay);
			Ve.push_back(worker);
			break;
		}
		case QUIT_CHOICE:
		{
			if (exitProgram())
				menuChoice = HOURLY_CHOICE;
			break;
		}
		default:
		{
			cout << "Something went wrong\n\n";
			break;
		}
		}
	} while (menuChoice != QUIT_CHOICE);



}

// print output report to user and end program
void printList(const vector<Employee*>& Ve)
{
	cout << "\n\nOutput Report:\n";
	for (auto i : Ve)
		i->printPay();
	cout << "\nThank you for using the CMSY-171 Employee Pay Program\n\n";
}

// validate menu option is valid, returns true if invalid and continues loop,
// false if valid and exit loop
bool menuValid(int choice)
{
	if (choice<HOURLY_CHOICE || choice>QUIT_CHOICE)
	{
		cout << "Error - invalid entry. Please reenter the menu choice.\n";
		return true;
	}
	return false;
}

// validates id number, returns true if invalid and continues loop, 
// false if valid and exits loop
bool idValid(int id)
{
	if (id<MIN_ID || id>MAX_ID)
	{
		cout << "A value between " << MIN_ID << " and " << MAX_ID
			<< " is required. Please re-enter\n";
		return true;
	}
	return false;
}

// validates a number is above minimum, returns true if invalid and continues loop,
// false if valid and exits loop
bool minValid(int num)
{
	if (num <= MINIMUM)
	{
		cout << "Error - this input cannot be less than or equal to 0, Please reenter\n";
		return true;
	}
	return false;
}

// min valid but double version
bool minValid(double num)
{
	if (num <= MINIMUM)
	{
		cout << "Error - this input cannot be less than or equal to 0, Please reenter\n";
		return true;
	}
	return false;
}

// ask user if they really want to quit, return true if they do not and keep
// looping, return false if they want to quit and leave loop
bool exitProgram()
{
	char temp[TYPE_SIZE];	// holds user's choice to quit
	cout << "\nDo you wish to exit the program (Y or N): ";
	cin.getline(temp, TYPE_SIZE);
	while (toupper(temp[0]) != 'Y' && toupper(temp[0]) != 'N')
	{
		cout << "Please enter Y or N: ";
		cin.getline(temp, TYPE_SIZE);
	}
	if (toupper(temp[0]) == 'Y')
		return false;
	else
		return true;
}