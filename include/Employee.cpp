#include "Employee.hpp"
#include <iostream>
#include <ostream>

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

void Employee::print() const {
    // Output the employee object in a user-friendly way.
    std::cout << "Employee: " << std::endl;

    std::cout << "ID: "<< '\r' + '\t' + '\t' 
              << this->employeeId << std::endl;

    std::cout << "Name: "<< '\r' + '\t' + '\t' 
              << this->firstName << " "
              << this->lastName << std::endl;

    std::cout << "Phone Number: "<< '\r' + '\t' + '\t' 
              << '\t' << this->phoneNumber << std::endl;

    std::cout << "Email Address : "<< '\r' + '\t' + '\t' 
              << '\t' << this->emailAddress << std::endl;

    std::cout << "Salary: "<< '\r' + '\t' + '\t' 
              << '\t' << this->salary << std::endl;
}
