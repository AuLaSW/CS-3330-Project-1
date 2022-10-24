#include <iostream>
#include <fstream>
#include <string>
#include "../include/DoublyLinkedList.hpp"
#include "../include/Employee.hpp"

int main(int argc, char *argv[])
{
    std::fstream myfile ("Week 1-employeeDataset_Project 1.txt");
    std::string line;
    std::string delimiter = " ";
    std::string *employeeInput = new std::string[6];

    DoublyLinkedList * const employeeList = new DoublyLinkedList();
    Employee *employee = nullptr;

    int count = 0;
    int outputInt = 0;

    if (myfile.is_open()) {
        std::cout << "it's open" << std::endl;
    }

    while (getline(myfile, line)) {
        count = 0; 
        while (count <= 5) {
            // get the output from the string
            std::string output = line.substr(0, line.find(delimiter));
            if (line.find(delimiter)) {
                line.erase(0, line.find(delimiter) + delimiter.length());
            }
            else {
                line.erase();
            }
            employeeInput[count] = output;
            count++;
        }
        employee = new Employee(
                                std::stoi(employeeInput[0]),
                                employeeInput[1],
                                employeeInput[2],
                                employeeInput[3],
                                employeeInput[4],
                                std::stod(employeeInput[5])
                                );
        employeeList->addNode(*employee);
    }

    std::cout << "we made it"<< std::endl;
    std::cout << employeeList->size() << std::endl;

    myfile.close();

    for (int i = 0; i < employeeList->size(); i++) {
        std::cout << i << std::endl;
        // print out the elements
        employeeList->getElement(i).print();
    }

    return 0;
}
