#include "EmployeeWcomisson.h"

using  namespace std;

EmployeeWcomission::EmployeeWcomission(const string &firstName, const string &surname, const double baseSalary, const double commission, const int numberOfItems)
    : Employee(firstName, surname), baseSalary(baseSalary),
      commission(commission),
      numberOfItems(numberOfItems)
{
    
}
void EmployeeWcomission::commissionPerItem(const double commission_)
{
    commission = commission_;
}
void EmployeeWcomission::salary(const double salary)
{
    baseSalary = salary;
}

void EmployeeWcomission::ItemsSold(const int items)
{
    numberOfItems = items;
}

double EmployeeWcomission::earnings() const
{
    return ((commission * numberOfItems) + baseSalary);
}

void EmployeeWcomission::print() const
{
    cout << "Commissioned Worker: ";
    Employee::print();
    // cout << first_name() << ' ' << surname(); //testing
}
