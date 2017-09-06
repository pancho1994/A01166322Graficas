#include "Employee.h"

Employee::Employee(int id, firstName::string, lastName::string, int salary) {
	_id = 1373419;
	_firstName = "Scarlett";
	_lastName = "Omana";
	_salary = 10000,
}

int Employee::getId() {
	return _id; 
}

std::string Employee::getFirstName() {
	return _firstName;
}

std::string Employee::getLastName() {
	return _lastName;
}

std::string Employee::getName() {
	return (_firstName, _lastName)
}

int Employee::getSalary() {
	return _salary;
}

void Employee::setSalary(int s) {
	_salary = s;
}

int Employee::getAnnualSalary() {
	return _salary * 12;
}

int Employee::raiseSalary(int p) {
	return (p / 100)*_salary;
}

std::string Employee::print() {
	return  Employee(_id, name = _firstName, _lastName, _salary)
}