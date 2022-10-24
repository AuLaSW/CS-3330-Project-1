#include <iostream>
#include <fstream>
#include <string>
#include "../include/DoublyLinkedList.hpp"
#include "../include/Employee.hpp"

int main(int argc, char *argv[])
{
    // read the file
    std::fstream myfile ("Week 1-employeeDataset_Project 1.txt");

    // strings to manage file output
    std::string line;
    std::string delimiter = " ";
    std::string *employeeInput = new std::string[6];
    std::string output;

    // the linked list
    DoublyLinkedList * const employeeList = new DoublyLinkedList();

    // a temporary employee variable to hold the infomration
    Employee *employee = nullptr;

    int count = 0;

    // loop through the file to get the employee information
    while (getline(myfile, line)) {
        count = 0; 
        while (count <= 5) {
            // get the output from the string ready for formating
            output = line.substr(0, line.find(delimiter));
            if (line.find(delimiter)) {
                line.erase(0, line.find(delimiter) + delimiter.length());
            }
            else {
                line.erase();
            }
            // add output to array
            employeeInput[count] = output;
            count++;
        }
        // create new employee based on input
        employee = new Employee(
                                std::stoi(employeeInput[0]),
                                employeeInput[1],
                                employeeInput[2],
                                employeeInput[3],
                                employeeInput[4],
                                std::stod(employeeInput[5])
                                );
        // add employee to list
        employeeList->addNode(*employee);
    }


    myfile.close();

    // loop through the list to print employees.
    for (int i = 0; i < employeeList->size(); i++) {
        // print out the elements
        employeeList->getElement(i).print();
    }

    return 0;
}
