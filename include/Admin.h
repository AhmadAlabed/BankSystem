#pragma once
#include"Employee.h"

class Admin : public Employee {
  public:
    //default constructor
    Admin() {}
    //parameterized constructor
    Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) { }

    //Methods

    //To add employee into (employees vector)
    void addEmployee(Employee employee) {
        employeesVec.push_back(employee);
    }

    //search for employee in (employees vector)
    Employee* searchEmployee(int id) {
        for (int i = 0; i < employeesVec.size(); i++) {
            if (employeesVec[i].getId() == id) {
                Employee* employee = &employeesVec[i];
                return employee;
            }
        }
        return NULL;
    }

    //Edit employee  data
    void editEmployee(int id, string name, string password, double salary) {
        searchEmployee(id)->setName(name);
        searchEmployee(id)->setPassword(password);
        searchEmployee(id)->setSalary(salary);
    }

    void listEmployees() {
        for (int i = 0; i < employeesVec.size(); i++) {
            employeesVec[i].displayInfo();
            cout << endl;
        }
    }

};
static  vector<Admin> adminsVec;
