// Using the Employee hierarchy - inheritance and polymorphism

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <iomanip>
using std::ios;
using std::setiosflags;
using std::setprecision;

#include <iostream>
using std::cout;
using std::endl;

#include "Employee.h"
#include "Fixed.h"
#include "Hourly.h"
#include "EmployeeWcomisson.h"
#include <vector>

typedef vector<shared_ptr<Employee>> EmployeesVec;

double TotalPerWeek(const EmployeesVec &Employees)
{
	double WeeklyTotal = 0;
	for (auto i : Employees)
	{
		WeeklyTotal = WeeklyTotal + i->earnings();
	}
	return WeeklyTotal;
}

int main()
{
	// set output formatting for floating point types
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

	shared_ptr<FixedRateWorker> fixed_rate_ptr = make_shared<FixedRateWorker>("Ted", "Ramgasamy", 905.00);
	shared_ptr<HourlyWorker> hourly_ptr = make_shared<HourlyWorker>("Louisa", "Mahlungu", 12.00, 52);

	fixed_rate_ptr->print();									// static binding
	cout << " earned R " << fixed_rate_ptr->earnings() << endl; // dynamic binding

	hourly_ptr->print();									// static binding
	cout << " earned R " << hourly_ptr->earnings() << endl; // dynamic binding

	cout << endl;
	cout << "Why is the output below not identical to the output above ?" << endl;
	cout << endl;

	shared_ptr<Employee> employee1_ptr = make_shared<FixedRateWorker>("Ted", "Ramgasamy", 905.00);
	shared_ptr<Employee> employee2_ptr = make_shared<HourlyWorker>("Louisa", "Mahlungu", 12.00, 52);
	// 2.2
	shared_ptr<Employee> employee3_ptr = make_shared<EmployeeWcomission>("Wiseman", "Kunene", 3000.00, 50.0, 20);

	employee1_ptr->print();									   // static binding
	cout << " earned R " << employee1_ptr->earnings() << endl; // dynamic binding

	employee2_ptr->print();									   // static binding
	cout << " earned R " << employee2_ptr->earnings() << endl; // dynamic binding

	// 2.2
	employee3_ptr->print();									   // static binding
	cout << " earned R " << employee3_ptr->earnings() << endl; // dynamic binding

	cout << endl;

	/// Exercise 2.3
	EmployeesVec Employees;
	Employees.push_back(employee1_ptr);
	Employees.push_back(employee2_ptr);
	Employees.push_back(employee3_ptr);

	cout << "Total wages per week : R" << TotalPerWeek(Employees) << endl;

	return 0;
	// 2.1
	// The pointers in line 39 and 40 are using the Employee print function which is the base class
	// the first output refers to the fixedRate and hourlyWorker class print functions
	// the print function in Employee class is non-virtual
	// virtual function means the function can be override without problems
}
