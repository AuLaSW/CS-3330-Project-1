#include "../include/Employee.hpp"
#include <iostream>
#include <iomanip>
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
    employeeId(employeeId), firstName(firstName), lastName(lastName),
    phoneNumber(phoneNumber), emailAddress(emailAddress),
    salary(salary) 
{ }

// Since strings are automatically handled with deletion.
Employee::~Employee() {
}

// get the employee id
const int Employee::getID() const {
    return this->employeeId;
}

const std::string Employee::getName() const {
    return this->firstName + " " + this->lastName;
}

const std::string Employee::getPhoneNumber() const {
    return this->phoneNumber; 
}

const std::string Employee::getEmailAddress() const {
    return this->emailAddress;
}

const int Employee::getSalary() const {
    return this->salary;
}

void Employee::print() const {
    // Output the employee object in a user-friendly way.
    std::cout << "Employee: " << std::endl;

    std::cout << "ID: "<< this->employeeId << std::endl;

    std::cout << "Name: "<< this->firstName << " " << this->lastName << std::endl;

    std::cout << "Phone Number: "<< this->phoneNumber << std::endl;

    std::cout << "Email Address : "<< this->emailAddress << std::endl;

    // we are setting the precision to show the money value properly.
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "Salary: "<< "$" << this->salary << std::endl;

    // create an extra space between employees
    std::cout << std::endl;
}

// this function takes an inputted line from the Employee
// file and generates an employee object from it.
Employee& Employee::getEmployeeFromString(std::string &str) {
    std::string delim = " ";
    std::string *empArr = new std::string[NUM_OF_PROPERTIES];

    int count = 0;
    
    while (count <= 5) {
        // get the output from the string ready for formating
        empArr[count] = str.substr(0, str.find(delim));
        
        // remove what we just took from the string so we can skip 
        // over it next time we loop through the string
        if (str.find(delim)) {
            str.erase(0, str.find(delim) + delim.length());
        }
        else {
            str.erase();
        }
        
        // add output to array
        count++;
    }

    // return a new employee object
    return *(new Employee(
                          std::stoi(empArr[ID]),
                          empArr[FIRST_NAME],
                          empArr[LAST_NAME],
                          empArr[PHONE],
                          empArr[EMAIL],
                          std::stod(empArr[SALARY])
                          ));
}
