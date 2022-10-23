#ifndef EMPLOYEE
#define EMPLOYEE 
#include <string>

// This is a simple class that handles the Employee objects we will
// be using.
class Employee {
public:
    // Constructor
    Employee(const int, const std::string, const std::string, 
             const std::string, const std::string, const double);

    // Destructor
    ~Employee();

    // Accessor
    int getEmployeeId() const;

    // print method;
    void print() const;

private:
    int employeeId;
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string emailAddress;
    double salary;
};

#endif /* ifndef EMPLOYEE */
