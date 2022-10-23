#define EMPLOYEE
#include <string>

class Employee {
public:
    // Constructor
    Employee(const int, const std::string, const std::string, 
             const std::string, const std::string, const double);

    // Destructor
    ~Employee();

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
