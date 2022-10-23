#define EMPLOYEE
#include <string>

class Employee {
public:
    // Constructor
    Employee(int, std::string, std::string, std::string, std::string, double);

    // Destructor
    ~Employee();

    // print method;
    void print() const;

private:
    int employeeID;
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string emailAddress;
    double salary;
};
