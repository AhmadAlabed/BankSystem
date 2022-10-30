#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <sstream>
#include "Admin.h"


class Parser
{
private:
    static vector<string> split(string line) {
        vector<string> myVec;
        stringstream myStream(line);
        string word;
        while (!myStream.eof()) { //eof() End Of File (true/false)
            getline(myStream, word, '|');
            myVec.push_back(word);
        }
        return myVec;
    }

public:
    static Client parseToClient(string line) {
        vector<string> myVec = split(line);
        Client client(stoi(myVec[0]),myVec[1], myVec[2], stod(myVec[3])); //stod() Convert string to double
        return client;
    }
    static Employee parseToEmployee(string line) {
        vector<string> myVec = split(line);
        Employee employee(stoi(myVec[0]), myVec[1], myVec[2], stod(myVec[3]));
        return employee;
    }
    static Admin parseToAdmin(string line) {
        vector<string> myVec = split(line);
        Admin admin(stoi(myVec[0]), myVec[1], myVec[2], stod(myVec[3]));
        return admin;
    }

};
#endif // PARSER_H
