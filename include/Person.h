#pragma once
#include<iostream>
#include"Validation.h"
using namespace std;
class Person {
protected:
    int id;
    string name;
    string password;
    //default constructor
    Person(){
        this->id =0;
        this-> name = " ";
        this->password = " ";
    }
public:
    //parameterized constructor
    Person(int id,string name, string password) {
        this->id = id;
        this-> name = name;
        this->password = password;
    }
    //Setters:
    void setId(int id) {
        this->id = id;
    }
    void setName(string name) {
        string valid = Validation::validateName(name);
        if (valid == "Valid") {
            this->name = name;
        }
        else {
            throw valid;
        }
    }
    void setPassword(string password) {
        string valid = Validation::validatePassword(password);
        if (valid == "Valid") {
            this->password = password;
        }
        else {
            throw valid;
        }
    }
    //Getters:
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getPassword() {
        return password;
    }
    //Methods:
    virtual void displayInfo() {
        cout << "--------------" << getName() << " Information--------------\n"
            << "Id: " << getId()
            << "\n" << "Name: " << getName()
            << "\n" << "Password: " << getPassword() << endl;
    }
};
