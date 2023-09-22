#ifndef EMPLOYEEWCOMISSION_H
#define EMPLOYEEWCOMISSION_H
#include "Employee.h"
using namespace std;

class EmployeeWcomission : public Employee
{
public:
    EmployeeWcomission(const string &first_name, const string &surname, const double baseSalary, const double commission, const int numberOfItems);

    virtual void print() const;
    virtual double earnings() const override;
    void salary(const double);
    void commissionPerItem(const double);
    void ItemsSold(const int);

private:
    double commission;
    double baseSalary;
    int numberOfItems;
};

#endif // EMPLOYEEWCOMISSION