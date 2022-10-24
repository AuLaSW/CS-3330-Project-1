#include "../include/Employee.hpp"
#include <iostream>
#include <string>

Employee::Employee() {
    this->employeeId = 0;
    this->firstName = "";
    this->lastName = "";
    this->phoneNumber = "";
    this->emailAddress = "";
    this->salary = 0;
}

// Employee constructor, uses a member initalization list
// to instantaite the fields in the class
Employee::Employee(const int         employeeId, 
                   const std::string firstName, 
                   const std::string lastName, 
                   const std::string phoneNumber, 
                   const std::string emailAddress, 
                   const double      salary) :
    employeeId(employeeId), firstName(firstName),
    phoneNumber(phoneNumber), emailAddress(emailAddress),
    salary(salary) 
{ }

// Since strings are automatically handled with deletion.
Employee::~Employee() {
}

int Employee::getEmployeeId() const {
    return this->employeeId;
}

void Employee::print() const {
    // Output the employee object in a user-friendly way.
    std::cout << "Employee: " << std::endl;

    std::cout << "ID: "<< this->employeeId << std::endl;

    std::cout << "Name: "<< this->firstName << " " << this->lastName << std::endl;

    std::cout << "Phone Number: "<< this->phoneNumber << std::endl;

    std::cout << "Email Address : "<< this->emailAddress << std::endl;

    std::cout << "Salary: "<< this->salary << std::endl;
}
