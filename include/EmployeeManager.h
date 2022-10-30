#pragma once
#include"FileManager.h"
#include"Employee.h"
#include"ClientManager.h"

class EmployeeManager
{
public:
    static void printEmployeeMenu() {
        cout << "***********Employee Opthions***********\n";
        cout <<"1- Add a new client\n"
            << "2- List of all clients\n"
            << "3- Search for a client\n"
            << "4- Edit a client\n"
            << "5- DisplayInformation\n"
            << "6- Update Password\n"
            << "7- Logout\n";
    }
    static void updateEmployeesTxt(){
        FileManager f;
        f.removeAllEmployees();
        for(Employee e:employeesVec){
            f.addEmployee(e);
        }
	}
    static void updateClientsTxt(){
        FileManager f;
        f.removeAllClients();
        for(Client c:clientsVec){
        FilesHelper::saveClient(c);
        }
	}

    static void newClient(Employee* employee) {
        Client client;
        string name, password;
        int id;
        double balance;

        getNameFromUser:cout << " Enter a New Client\nName: ";
        cin >> name;
        try{
            client.setName(name);
        }catch(string error){
            cout<<error<<endl;
            goto getNameFromUser;
        }
        getPasswordFromUser:cout << "\nPassword:  ";
        cin >> password;
        try{
            client.setPassword(password);
        }catch(string error){
            cout<<error<<endl;
            goto getPasswordFromUser;
        }
        getBalanceFromUser:cout << "\nBalance: ";
        cin >> balance;
        try{
            client.setBalance(balance);
        }catch(string error){
            cout<<error<<endl;
            goto getBalanceFromUser;
        }
        FilesHelper::saveClient(client);
        FilesHelper::getClients();
        //employee->addClient(client);
    }

   static void listAllClients(Employee* employee) {
        employee->listClient();
    }

    static void editClientInfo(Employee* employee)
    {
        int x;
        int id;
        string name, password;
        double balance;
        cout << "Client Id:  ";
        cin >> id;
        Client* client = employee->searchClient(id);
        if (client != NULL)
        {
            cout << "Enter What you want to edit: \n"
                << "1- All Data\n"
                << "2- Name\n"
                << "3- Password\n"
                << "4- Balance\n"
                << "Enter Your Choice: ";
            cin >> x;

            switch (x)
            {
                case 1:
                {
                    getNameFromUser1:cout << "Enter the new Name: ";
                    cin >> name;
                    try{
                        client->setName(name);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getNameFromUser1;
                    }
                    getPasswordFromUser1:cout << "\nEnter the new Password: ";
                    cin >> password;
                    try{
                        client->setPassword(password);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getPasswordFromUser1;
                    }
                    getBalanceFromUser1:cout << "\nEnter the new Balance:  ";
                    cin >> balance;
                    try{
                        client->setBalance(balance);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getBalanceFromUser1;
                    }
                    employee->editClient(id, name, password, balance);
                    updateClientsTxt();
                    break;
                }
                case 2:
                {
                    getNameFromUser2:cout << "Enter the new Name:  ";
                    cin >> name;
                    try{
                        client->setName(name);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getNameFromUser2;
                    }
                    password = client->getPassword();
                    balance = client->getBalance();
                    employee->editClient(id, name, password, balance);
                    updateClientsTxt();
                    break;

                }
                case 3:
                {
                    getPasswordFromUser3:cout << "\nEnter the new Password: ";
                    cin >> password;
                    try{
                        client->setPassword(password);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getPasswordFromUser3;
                    }
                    name = client->getName();
                    balance = client->getBalance();
                    employee->editClient(id, name, password, balance);
                    updateClientsTxt();
                    break;
                }
                case 4:
                {
                    getBalanceFromUser4:cout << "\nEnter the new Balance:  ";
                    cin >> balance;
                    try{
                        client->setBalance(balance);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getBalanceFromUser4;
                    }
                    name = client->getName();
                    password = client->getPassword();
                    employee->editClient(id, name, password, balance);
                    updateClientsTxt();
                    break;
                }
                default:
                {
                    cout << "Your Choice is not found" << endl;
                    editClientInfo(employee);
                    break;
                }
            }
        }
        else
        {
            cout << "Client is not found" << endl;
            cout << "1- Try Again" << endl;
            cout << "2- Return" << endl;
            cin >> x;
            if (x == 1) {
                editClientInfo(employee);
            }
            else if (x == 2)
            {
                printEmployeeMenu();
                employeeOptions(employee);

            }
            else
            {
                cout << "Your Choice is not found" << endl;
                printEmployeeMenu();
                employeeOptions(employee);
            }
        }
    }

    static void searchForClient(Employee * employee){
        int id;
        cout << "Client Id:  ";
        cin >> id;
        Client* client = employee->searchClient(id);
        if (client == NULL) {
            cout << "Client is not found" << endl;
        }
        else {
            client->displayInfo();
        }
    }

    static void updatePassword(Employee* employee) {
        //ClientManager::updatePassword(employee);
        string password;
		getPasswordFromUser:cout << "Please Enter Your New Password: ";
		cin >> password;
        try{
        employee->setPassword(password);
        updateEmployeesTxt();
        cout << "\tPassword Updated successfully" << endl;
        }catch(string error){
            cout<<error<<endl;
            int c;
            cout <<"1/Update Password\n2/Return\n";
            cin >> c;
            switch (c)
            {
            case 1:
                goto getPasswordFromUser;
                break;
            case 2:
                printEmployeeMenu();
                break;
            default:
                cout << "Invalid option\n";
                printEmployeeMenu();
                break;
            }
        }
    }

    static bool employeeOptions(Employee* employee) {
        int x = 0;
        cout << "Enter your choise: ";
        cin >> x;
        switch (x) {
        case(1):
            newClient(employee);
            break;
        case(2):
            listAllClients(employee);
            break;
        case(3):
            searchForClient(employee);
            break;
        case(4):
            editClientInfo(employee);
            break;
        case(5):
            employee->displayInfo();
            break;
        case(6):
            updatePassword(employee);
            break;
        case(7):
            return true;
            break;
        defualt:
            {
                cout << "invalid Choise" << endl;
                employeeOptions(employee);
            }
        }
        Back(employee);
    }

    static void Back(Employee* employee) {
        system("pause");
        printEmployeeMenu();
        employeeOptions(employee);
    }

    static Employee* login(int id, string password)
	{
	    Employee* employee = NULL;
		for (int i = 0; i < employeesVec.size(); i++) {
            if (employeesVec[i].getId() == id) {
                employee = &employeesVec[i];
            }
        }
		if (employee == NULL) {

			cout << "You Have Entered Invalid ID OR Password " << endl;
			cout << "----------------------------------------" << endl;
			return NULL;
		}
		else
		{
			if (employee->getPassword() == password)
			{
				return employee;
			}
			else
			{
				cout << "You Have Entered Invalid ID OR Password " << endl;
				cout << "----------------------------------------" << endl;
				return NULL;
			}
		}
	}
};


//#endif // EMPLOYEEMANAGER_H
