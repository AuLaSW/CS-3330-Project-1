// Austin Swanlaw
#include <iostream>
#include <fstream>
#include <string>
#include "../include/DoublyLinkedList.hpp"
#include "../include/Employee.hpp"

int main(int argc, char *argv[])
{
    // read the file
    std::fstream myfile ("Week 1-employeeDataset_Project 1.txt");

    // string that will hold each line from the file above
    std::string line;

    // the linked list
    DoublyLinkedList * const employeeList = new DoublyLinkedList();

    // loop through the file to get the employee information
    while (getline(myfile, line)) {
        // create an employee from the line input then
        // add the employee to the list
        employeeList->addNode(Employee::getEmployeeFromString(line));
    }

    // close the file
    myfile.close();

    // loop through the list to print employees.
    for (int i = 0; i < employeeList->size(); i++) {
        // print out the elements
        employeeList->getElement(i).print();
    }

    return 0;
}
