#include <iostream>
#include <string>
#include <vector>

class Employee {
public:
    // Constructor
    Employee(const std::string& name, double salary) : name_(name), salary_(salary) {}

    // Method to display information
    void showinfo() const {
        std::cout << "Name: " << name_ << ", Salary: $" << salary_ << std::endl;
    }

    // Getter for salary (useful for calculations in derived classes)
    double getSalary() const {
        return salary_;
    }

protected:
    std::string name_;
    double salary_;
};

class Manager : public Employee {
public:
    // Constructor
    Manager(const std::string& name, double salary, double allowance)
        : Employee(name, salary), allowance_(allowance) {}

    // Method to display information
    void showinfo() const {
        Employee::showinfo(); // Call base class method to show name and salary
        std::cout << "Allowance: $" << allowance_ << std::endl;
    }

    // Calculate total income
    double getTotalIncome() const {
        return getSalary() + allowance_;
    }

private:
    double allowance_;
};

int main() {
    // a) Create and initialize objects
    Employee emp("John Doe", 50000);
    Manager mgr("Jane Smith", 70000, 10000);

    std::cout << "Employee Information:" << std::endl;
    emp.showinfo();
    std::cout << "\nManager Information:" << std::endl;
    mgr.showinfo();

    // b) Create an array of Manager objects using dynamic allocation
    const int numManagers = 5;
    Manager** managers = new Manager*[numManagers];

    // Initialize manager objects (example data)
    managers[0] = new Manager("Alice", 80000, 12000);
    managers[1] = new Manager("Bob", 75000, 11000);
    managers[2] = new Manager("Charlie", 85000, 13000);
    managers[3] = new Manager("David", 78000, 10000);
    managers[4] = new Manager("Eve", 90000, 15000);

    // Calculate the total income and average
    double totalIncomeSum = 0;
    for (int i = 0; i < numManagers; ++i) {
        totalIncomeSum += managers[i]->getTotalIncome();
    }
    double averageIncome = totalIncomeSum / numManagers;

    std::cout << "\nAverage Total Income of Managers: $" << averageIncome << std::endl;

    // Deallocate memory (important to prevent memory leaks)
    for (int i = 0; i < numManagers; ++i) {
        delete managers[i];
    }
    delete[] managers;

    return 0;
}