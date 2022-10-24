#include <iostream>
#include <ios>
#include <fstream>
#include <string>
#include "../include/DoublyLinkedList.hpp"
#include "../include/Employee.hpp"

int main(int argc, char *argv[])
{
    std::fstream myfile;
    std::string line;
    std::string delimiter = " ";
    std::string *employeeInput = new std::string[6];
    myfile.open("Week 1-employeeDataset_Project 1.txt", std::ios::out);

    DoublyLinkedList * const employeeList = new DoublyLinkedList();
    Employee *employee = nullptr;

    int count = 0;
    int outputInt = 0;
    
    while (getline (myfile, line)) {
        count = 0;
        while (line.length() > 0) {
            // get the output from the string
            std::string output = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            employeeInput[count] = output;
            count++;
        }

        employee = new Employee(
                                std::stoi(employeeInput[0]),
                                employeeInput[1],
                                employeeInput[2],
                                employeeInput[3],
                                employeeInput[4],
                                std::stoi(employeeInput[5])
                                );
        employeeList->addNode(*employee);
    }

    for (int i = 0; i < employeeList->size(); i++) {
        // print out the elements
        employeeList->getElement(i).print();
    }

    return 0;
}
