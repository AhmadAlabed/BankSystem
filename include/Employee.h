#pragma once
#include"Client.h"
#include "Person.h"
#include "vector"

using namespace std;
class Employee :public Person {
protected:
    double salary;
public:
    //default constructor
    Employee() {
        this->salary = 0.0;
    }
    //parameterized constructor
    Employee(int id, string name, string password, double salary) :Person(id, name, password) {
        this->salary =salary;
    }
    //Setters:
    void setSalary(double salary) {
        string valid = Validation::validateSalary(salary);
        if (valid == "Valid") {
            this->salary = salary;
        }
        else {
            throw valid;
        }
    }
    //Getters:
    double getSalary() {
        return salary;
    }
    //Methods:

    //To add client into (clients vector)
    void addClient(Client& client) {
        clientsVec.push_back(client);
    }

    //search for client in (employees vector)
    Client* searchClient(int id) {
        for (int i = 0; i < clientsVec.size(); i++) {
            if (clientsVec[i].getId() == id) {
                Client* client = &clientsVec[i];
                return client;
            }
        }
        return NULL;
    }

    void listClient() {
        for (int i = 0;i< clientsVec.size();i++) {
            clientsVec[i].displayInfo();
            cout << endl;
        }
    }

    //Edit client  data
    void editClient(int id, string name, string password, double balance) {
        searchClient(id)->setName(name);
        searchClient(id)->setPassword(password);
        searchClient(id)->setBalance(balance);
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Salary: " << getSalary() << endl;
        cout << "======================" << endl;
    }

};
static vector <Employee> employeesVec;
