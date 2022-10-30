#pragma once
#include<iostream>
using namespace std;

class Validation
{
public:
    static string validateName(string name) {
        if (name.length() >= 5 && name.length() <= 20) {
            bool isAlphabetic = true;
            for (int i = 0; i < name.length(); i++) {
                if (!isalpha(name[i])) {
                    isAlphabetic = false;
                    break;
                }
            }
            string status = isAlphabetic ? "Valid" : "The name must contain only alphabetic";
            return status;

        }
        else {
            return "The name must be between 5 and 20 characters";
        }
    }
    static string validatePassword(string password) {
        if (password.length() >= 8 && password.length() <= 20) {
            return "Valid";
        }
        else {
            return "The password must be between 8 and 20 characters";
        }
    }
    static string validateBalance(double balance) {
        if (balance >= 1500) {
            return "Valid";
        }
        else {
            return "Min balance is 1500";
        }
    }
    static string validateSalary(double salary) {
        if (salary >= 5000) {
            return "Valid";
        }
        else {
            return "Min Salary is 5000";
        }
    }
};
