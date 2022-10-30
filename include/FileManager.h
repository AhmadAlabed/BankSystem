#pragma once
#include"DataSourceInterface.h"
#include"FilesHelper.h"
#include "Client.h"
class FileManager :public DataSourceInterface
{
public:
	//To add client into Clients.txt
     void addClient(Client client){
		FilesHelper::saveClient(client);
	}

	//To add employee into Employees.txt
	 void addEmployee(Employee employee) {
		FilesHelper::saveEmployee("D:\\Employees.txt","D:\\EmployeeLastId.txt",employee);
	}

	//To add admin into Admins.txt
	 void addAdmin(Admin admin) {
		FilesHelper::saveEmployee("D:\Admins.txt","D:\AdminLastId.txt",admin);
	}

	//To get the data from Clients.txt and push it back to the (clients vector)
	 vector<Client> getAllClients() {
		FilesHelper::getClients();
		return clientsVec;
	}

	//To get the data from Employees.txt and push it back to the (employees vector)
     vector<Employee> getAllEmployees() {
		FilesHelper::getEmployees();
		return employeesVec;
	}

	//To get the data from Admins.txt and push it back to the (admins vector)
	 vector<Admin> getAllAdmins() {
		FilesHelper::getAdmins();
		return adminsVec;
	}

	//Remove all data from the  text file
	 void removeAllClients() {
		FilesHelper::clearFile("D:\Clients.txt", "D:\ClientLastId.txt");
	}
	 void removeAllEmployees() {
		FilesHelper::clearFile("D:\\Employees.txt","D:\\EmployeeLastId.txt");
	}
	 void removeAllAdmins() {
		FilesHelper::clearFile("D:\Admins.txt","D:\AdminLastId.txt");
	}

};
