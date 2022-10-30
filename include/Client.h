#pragma once
#include<iostream>
#include"Validation.h"
#include"Person.h"
#include "vector"
using namespace std;
class Client :public Person {
protected:
    double balance;
public:
    //default constructor
    Client() {
       this-> balance = 0.0;
    };
    //parameterized constructor
    Client(int id,string name, string password, double balance) :Person(id,name, password) {
        this-> balance = balance;
    }

    //Setters:
    void setBalance(double balance) {
        string valid = Validation::validateBalance(balance);
        if (valid == "Valid") {
            this->balance = balance;
        }
        else {
            throw valid;
        }
    }

    //Getters:
    double getBalance() {
        return balance;
    }
    //Methods:
    void deposit(double amount) {
        if (amount < 0) {
            string error = "Deposit amount can't be negative.";
            throw error;
        }
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount < 0) {
            string error = "Withdraw amount can't be negative.";
            throw error;
        }
        if (balance < amount) {
            string error = "The amount you entered will exceed your balance limit. Please enter a lower amount.";
            throw error;
        }
        balance -= amount;
    }
    void transferTo(double amount, Client& recipient) {
        if (amount < 0) {
            string error = "Transfer amount can't be negative.";
            throw error;
        }
        if (balance < amount) {
            string error = "The amount you entered will exceed your balance limit. Please enter a lower amount.";
            throw error;
        }
        withdraw(amount);
        recipient.deposit(amount);
    }

    void checkBalance() {
        cout << getBalance() << endl;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Balance: " << getBalance() << endl;
        cout << "======================" << endl;
    }

};
static vector <Client> clientsVec;
