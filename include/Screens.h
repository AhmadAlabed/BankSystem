#ifndef SCREENS_H
#define SCREENS_H
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "ClientManager.h"
#include "FilesHelper.h"
#include "AdminManager.h"



class Screens
{
    public:
        static void bankName(){
            cout<<"================================"<<endl;
            cout<<"Bank Name"<<endl;
            cout<<"================================"<<endl;
        }
        static void welcome(){
            cout<<"+++++++++++++++++++++++++++++++++"<<endl;
            cout<<"Welcome"<<endl;
            cout<<"+++++++++++++++++++++++++++++++++"<<endl;
        }
        static void loginOptions(){
            cout<<"Login As:"<<endl;
            cout<<"1) Client."<<endl;
            cout<<"2) Employee."<<endl;
            cout<<"3) Admin."<<endl;
        }
        static int loginAs(){
            int loginAsNbr;
            cout<<"Login As:"<<endl;
            cin>>loginAsNbr;
            switch(loginAsNbr){
            case 1:
            case 2:
            case 3:
                return loginAsNbr;
                break;
            default:
                invalid(loginAsNbr);
                break;
            }
        }
        static void invalid(int c){
            cout<<"Invalid choice"<<endl;
            loginAs();
        }
        static void logout(){
            loginOptions();
            int x = loginAs();
            loginScreen(x);
        }
        static void loginScreen(int c){
            int id;
            string password;
            tryAgain:cout<<"Please, enter your ID :"<<endl;
            cin>>id;
            cout<<"Please, enter your password :"<<endl;
            cin>>password;
            switch(c){
                ////////////////////// case 1 (Client) //////////////////////
                case 1:{
                    FilesHelper::getClients();
                    Client* client = ClientManager::login(id,password);
                    if(client == NULL){
                        cout<<"Your id or password is incorrect."<<endl;
                        int choice;
                        rechoose1:cout<<"1) Try again"<<endl;
                        cout<<"2) Back to the start"<<endl;
                        cin>>choice;
                        switch(choice){
                        case 1:{
                            goto tryAgain;
                            break;
                        }
                        case 2:{
                            logout();
                            break;
                        }
                        default:{
                            cout<<"Invalid choice"<<endl;
                            goto rechoose1;
                            break;
                        }
                        }
                    }else{
                        ClientManager::printClientMenu();
                        if(ClientManager::ClientOptions(client)){
                            logout();
                        }
                    }
                    break;
                }
                ////////////////////// case 2 (Employee) //////////////////////
                case 2:{
                    FilesHelper::getClients();
                    FilesHelper::getEmployees();
                    Employee* employee = EmployeeManager::login(id,password);
                    if(employee == NULL){
                        cout<<"Your id or password is incorrect."<<endl;
                        int choice;
                        rechoose2:cout<<"1) Try again"<<endl;
                        cout<<"2) Back to the start"<<endl;
                        cin>>choice;
                        switch(choice){
                            case 1:{
                                goto tryAgain;
                                break;
                            }
                            case 2:{
                                logout();
                                break;
                            }
                            default:{
                                cout<<"Invalid choice"<<endl;
                                goto rechoose2;
                                break;
                            }
                        }
                    }else{
                        EmployeeManager::printEmployeeMenu();
                        if(EmployeeManager::employeeOptions(employee)){
                            logout();
                        }
                    }
                    break;
                }
                ////////////////////// case 3 (Admin) //////////////////////
                case 3:{
                    FilesHelper::getClients();
                    FilesHelper::getAdmins();
                    Admin* admin = AdminManager::login(id,password);
                    if(admin == NULL){
                        cout<<"Your id or password is incorrect."<<endl;
                        int choice;
                        rechoose3:cout<<"1) Try again"<<endl;
                        cout<<"2) Back to the start"<<endl;
                        cin>>choice;
                        switch(choice){
                        case 1:{
                            goto tryAgain;
                            break;
                        }
                        case 2:{
                            logout();
                            break;
                        }
                        default:{
                            cout<<"Invalid choice"<<endl;
                            goto rechoose3;
                            break;
                        }
                        }
                    }else{
                        AdminManager::printAdminMenu();
                        if(AdminManager::adminOptions(admin)){
                            logout();
                        }
                    }
                    break;
                }
            }
        }
        static void createDatabase(){
            fstream file;
            file.open("D:\ClientLastId.txt");
            if(file.is_open()) {
                    file.close();
            } else {
                ofstream MyFile("D:\ClientLastId.txt");
                MyFile << "0";
                MyFile.close();
            }
            file.open("D:\\EmployeeLastId.txt");
            if(file.is_open()) {
                    file.close();
            } else {
                ofstream MyFile("D:\\EmployeeLastId.txt");
                MyFile << "0";
                MyFile.close();
            }
            file.open("D:\AdminLastId.txt");
            if(file.is_open()) {
                    file.close();
            } else {
                ofstream MyFile("D:\AdminLastId.txt");
                MyFile << "1";
                MyFile.close();
            }
            file.open("D:\Admins.txt");
            if(file.is_open()) {
                    file.close();
            } else {
                ofstream MyFile("D:\Admins.txt");
                MyFile << "1|Admin|12345678|5000";
                MyFile.close();
            }
        }

        static void runApp(){
            createDatabase();
            bankName();
            welcome();
            loginOptions();
            int c = loginAs();
            loginScreen(c);
        }

};

#endif // SCREENS_H
