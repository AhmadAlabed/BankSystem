#pragma once
#include<fstream>
#include <sstream>
#include"Parser.h"
#include "PublicVariables.h"

using namespace std;
class FilesHelper
{
public:
	static void saveLast(string fileName, int id) {
		fstream file(fileName);
		file << id;
		file.close();
	}

	static int getLast(string fileName) {
		fstream file (fileName);
		int id;
		file >> id;
		file.close();
		return id;
	}
	//To add client into Clients.txt
	static void saveClient(Client c) {
		int id = getLast("D:\ClientLastId.txt");
		fstream file("D:\Clients.txt", ios::app);
		file << id + 1 << '|' << c.getName() << '|' << c.getPassword() << '|' << c.getBalance() << endl;
		file.close();
		saveLast("D:\ClientLastId.txt", id + 1);
	}

	//To add employee or admin into Employees.txt or Admins.txt
	static void saveEmployee(string fileName, string lastIdFile,Employee e) {
		int id = getLast(lastIdFile);
		fstream file(fileName, ios::app);
		file << id + 1 << '|' << e.getName() << '|' << e.getPassword() << '|' << e.getSalary() << endl;
		file.close();
		saveLast(lastIdFile, id + 1);
	}

	static void getClients() {
	    clientsVec.clear();
		fstream file("D:\Clients.txt", ios::in);
		string line;
		while (getline(file, line)) {
			Client c = Parser::parseToClient(line);
			clientsVec.push_back(c);
		}
		file.close();
	}

	static void getEmployees() {
	    employeesVec.clear();
		fstream file("D:\\Employees.txt", ios::in);
		string line;
		while (getline(file, line)) {
			Employee e = Parser::parseToEmployee(line);
			employeesVec.push_back(e);
		}
		file.close();
	}

	static void getAdmins() {
	    adminsVec.clear();
		fstream file("D:\Admins.txt", ios::in);
		string line;
		while (getline(file, line)) {
			Admin a = Parser::parseToAdmin(line);
			adminsVec.push_back(a);
		}
		file.close();
	}

	static void clearFile(string fileName, string lastIdFile) {
		fstream file1(fileName, ios::out | ios::trunc);
		file1.close();
		fstream file2(lastIdFile, ios::out);
		file2 << 0;
		file2.close();
	}
};
