#pragma once
#include"Person.h"
#include<iostream>
#include<string>
#include "Admin.h"
#include "Parser.h"
#include "Employee.h"
#include"Validation.h"
#include"Client.h"



using namespace std;

class ClientManager
{
public:
	static void printClientMenu() {
		cout << "***********Client Opthions***********\n";
		cout << "1/ Check Balance\n2/ DisplayInformation\n3/ Update Password\n4/ Deposit\n5/ Withdraw\n6/ TransferTo\n7/ LogOut\n";
	}

	static void updatePassword(Person* person) {
		string password;
		getPasswordFromUser:cout << "Please Enter Your New Password: ";
		cin >> password;
        try{
        person->setPassword(password);
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
                printClientMenu();
                break;
            default:
                cout << "Invalid option\n";
                printClientMenu();
                break;
            }
        }
	}

	static Client* login(int id, string password)
	{
        Employee employee;
		Client* clientptr = employee.searchClient(id);
		if (clientptr == NULL) {

			cout << "You Have Entered Invalid ID OR Password " << endl;
			cout << "----------------------------------------" << endl;
			return NULL;
		}
		else
		{
			if (clientptr->getPassword() == password)
			{
				return clientptr;
			}
			else
			{
				cout << "You Have Entered Invalid ID OR Password " << endl;
				cout << "----------------------------------------" << endl;
				return NULL;
			}
		}
	}
	static void updateTxt(){
        FileManager f;
        f.removeAllClients();
        for(Client c:clientsVec){
        FilesHelper::saveClient(c);
        }
	}

	static bool ClientOptions(Client* client) {
		Employee employee;
		int choise = 0;
		cout << "Please Enter your Choise :  " << endl;
		cin >> choise;

		switch (choise)
		{
		case (1):
		{
			client->checkBalance();
			break;
		}
		case (2):
		{
			client->displayInfo();
			break;
		}
		case (3):
		{
			updatePassword(client);
			updateTxt();
			break;
		}
		case (4):
		{
			double amount;
			getAmountFromUser1:cout << "Please Enter the Amount you want to Deposit" << endl;
			cin >> amount;
			try{
			    client->deposit(amount);
			    updateTxt();
			}catch(string error){
			    cout<<error<<endl;
			    goto getAmountFromUser1;
			}
			break;
		}
		case (5):
		{
			double amount;
			getAmountFromUser2:cout << "Please Enter the Amount you want to Withdraw" << endl;
			cin >> amount;
			try{
			    client->withdraw(amount);
			    updateTxt();
			}catch(string error){
			    cout<<error<<endl;
			    goto getAmountFromUser2;
			}
			break;
		}
		case (6):
		{
			double amount = 1500;
			int id = 0;
			Client* client2;
			cout << "Please Enter the CLient ID you want to transfer to " << endl;
			cin >> id;
			client2 = employee.searchClient(id);
			if (client2 == NULL) {

				cout << "You Have Entered Invalid ID " << endl;
				cout << "----------------------------------------" << endl;
			}

			else
			{
				getAmountFromUser3:cout << "Please Enter the Amount you want to Transfer " << endl;
				cin >> amount;
				try{
                    client->transferTo(amount, *client2);
                    updateTxt();
                    cout << "_______DONE______  " << endl;
                }catch(string error){
                    cout<<error<<endl;
                    goto getAmountFromUser3;
                }
			}
			break;
		}
		case (7):
		{
			return true;
		}
		default:
			cout << "You Have Entered Invalid choise " << endl;
			cout << "----------------------------------";
			ClientOptions(client);

		}
		Back(client);
	}

	static void Back(Client* client) {
		system("pause");
		printClientMenu();
		ClientOptions(client);
	}
};
