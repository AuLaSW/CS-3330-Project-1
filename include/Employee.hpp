#ifndef EMPLOYEE
#define EMPLOYEE 
#include <string>

// This is a simple class that handles the Employee objects we will
// be using.
class Employee {
public:
    // Constructor
    Employee();

    Employee(const int, const std::string, const std::string, 
             const std::string, const std::string, const double);

    // Destructor
    ~Employee();

    // Accessor
    const int getId() const;
    const std::string getName() const;
    const std::string getPhoneNumber() const;
    const std::string getEmailAddress() const;
    const int getSalary() const;

    // convert a string into an employee and return the employee
    static Employee& getEmployeeFromString(std::string&);

    // print method;
    void print() const;

private:
    int employeeId;
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string emailAddress;
    double salary;

    // create an enum so it is easier to access array inputs
    // when converting a string to an employee
    enum { ID, FIRST_NAME, LAST_NAME, PHONE, EMAIL, SALARY, NUM_OF_PROPERTIES };
};

#endif /* ifndef EMPLOYEE */
