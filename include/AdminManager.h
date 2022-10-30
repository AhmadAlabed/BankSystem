#pragma once
#include<fstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"Parser.h"
#include"DataSourceInterface.h"
#include"FilesHelper.h"
#include"EmployeeManager.h"

using namespace std;
class AdminManager : public EmployeeManager{
public:
    ///////////////////////////////////////////////////////////////////
    static void printAdminMenu(){
     cout<<"Admin Functions\n";
     cout<<"1- Add a new client\n";
     cout<<"2- List of all clients\n";
     cout<<"3- Search for a client\n";
     cout<<"4- Edit a client\n";
     cout<<"5- Add a new employee\n";
     cout<<"6- List of all employee\n";
     cout<<"7- Search for an employee\n";
     cout<<"8- Edit an employee\n";
     cout<<"9- Display\n";
     cout<<"10- Update Password\n";
     cout<<"11- Logout\n";
     cout<<endl;
    }
    ///////////////////////////////////////////////////////////////////
    static void updateEmployeesTxt(){
        FileManager f;
        f.removeAllEmployees();
        for(Employee e:employeesVec){
            f.addEmployee(e);
        }
	}
    static void updateAdminTxt(){
        FileManager f;
        f.removeAllAdmins();
        for(Admin a:adminsVec){
            f.addAdmin(a);
        }
	}
    ///////////////////////////////////////////////////////////////////
    static void newEmployee(Admin* admin){
        Employee employee;
        string name, password;
        double salary;
        getNameFromUser:cout << " Enter a New Employee\nName: ";
        cin >> name;
        try{
            employee.setName(name);
        }catch(string error){
            cout<<error<<endl;
            goto getNameFromUser;
        }
        getPasswordFromUser:cout << "\nPassword:  ";
        cin >> password;
        try{
            employee.setPassword(password);
        }catch(string error){
            cout<<error<<endl;
            goto getPasswordFromUser;
        }
        getSalaryFromUser:cout << "\nSalary: ";
        cin >> salary;
        try{
            employee.setSalary(salary);
        }catch(string error){
            cout<<error<<endl;
            goto getSalaryFromUser;
        }
        FilesHelper::saveEmployee("D:\\Employees.txt","D:\\EmployeeLastId.txt",employee);
        FilesHelper::getEmployees();
        //admin->addEmployee(employee);
    }
    ///////////////////////////////////////////////////////////////////
    static void listAllEmployees (Admin* admin)
     {
         FilesHelper::getEmployees();
         admin->listEmployees();
     }
     ///////////////////////////////////////////////////////////////////
    static void searchForEmployee (Admin* admin)
        {
         int id;
         cout<<"Employee Id:  "<<endl;
         cin>> id;
         Employee* employee = admin->searchEmployee(id);
         if (employee == NULL){

            cout<<"Employee is not found"<<endl;
         }
         else {
            employee->displayInfo();
         }
        }
     ///////////////////////////////////////////////////////////////////
     static void editEmployeeInfo(Admin * admin)
     {
         int x;
         int id;
         string name , password;
         double salary;
         cout << "Employee Id:  ";
         cin>>id;
         Employee* employee = admin->searchEmployee(id);
         if (employee != NULL)
         {
             cout<<"Enter What you want to edit: "<<endl;
             cout<<"1- All Data\n";
             cout<<"2- Name\n";
             cout<<"3- Password\n";
             cout<<"4- Salary\n";
             cout<<"Enter Your Choice: ";
             cin>>x;

             switch (x)
             {
          case 1:
            {
                 getNameFromUser1:cout << "Enter the new Name: ";
                    cin >> name;
                    try{
                        employee->setName(name);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getNameFromUser1;
                    }
                    getPasswordFromUser1:cout << "\nEnter the new Password: ";
                    cin >> password;
                    try{
                        employee->setPassword(password);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getPasswordFromUser1;
                    }
                    getSalaryFromUser1:cout << "\nEnter the new salary:  ";
                    cin >> salary;
                    try{
                        employee->setSalary(salary);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getSalaryFromUser1;
                    }
                    admin->editEmployee(id, name, password, salary);
                    updateEmployeesTxt();
                    break;
            }
             case 2:
            {
                getNameFromUser2:cout << "Enter the new Name:  ";
                    cin >> name;
                    try{
                        employee->setName(name);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getNameFromUser2;
                    }
                    password = employee->getPassword();
                    salary = employee->getSalary();
                    admin->editEmployee(id, name, password, salary);
                    updateEmployeesTxt();
                    break;

            }
            case 3:
            {
                getPasswordFromUser3:cout << "\nEnter the new Password: ";
                    cin >> password;
                    try{
                        employee->setPassword(password);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getPasswordFromUser3;
                    }
                    name = employee->getName();
                    salary = employee->getSalary();
                    admin->editEmployee(id, name, password, salary);
                    updateEmployeesTxt();
                    break;
            }
              case 4:
            {
                getSalaryFromUser4:cout << "\nEnter the new salary:  ";
                    cin >> salary;
                    try{
                        employee->setSalary(salary);
                    }catch(string error){
                        cout<<error<<endl;
                        goto getSalaryFromUser4;
                    }
                    name = employee->getName();
                    password = employee->getPassword();
                    admin->editEmployee(id, name, password, salary);
                    updateEmployeesTxt();
                    break;

            }
              default:
                {
                    cout<<"Your Choice is not found"<<endl;
                    editEmployeeInfo(admin);
                    break;
                }
             }
         }
         else
         {
            cout<<"Employee is not found"<<endl;
            cout<<"1- Try Again"<<endl;
            cout<<"2+ Return"<<endl;
            cin>>x;
            if (x==1){
                editEmployeeInfo(admin);
            }
            else if (x==2)
            {
                printAdminMenu();
                adminOptions(admin);

            }
            else
            {
                cout<<"Your Choice is not found"<<endl;
                printAdminMenu();
                adminOptions(admin);
            }
         }
     }
     ///////////////////////////////////////////////////////////////////
        //     1- Add a new client
        //     2- List of all clients
        //     3- Search for a client
        //     4- Edit a client
        //     5- Add a new employee
        //     6- List of all employee
        //     7- Search for an employee
        //     8- Edit an employee
        //     9- Display
        //     10- Update Password
        //     11- Logout
    ///////////////////////////////////////////////////////////////////
         static bool adminOptions (Admin * admin)
         {
             int x=0;
             cout<<"Enter Your Choice: "<<endl;
             cin>>x;

             switch(x)
             {
             case 1:
                 {
                    newClient(admin);
                    break;
                 }
             case 2:
                 {
                     listAllClients(admin);
                     break;
                 }
             case 3:
                 {
                     searchForClient(admin);
                     break;
                 }
             case 4:
                 {
                     editClientInfo(admin);
                     break;
                 }
             case 5:
                {
                    newEmployee (admin);
                    break;
                }
             case 6:
                {
                    listAllEmployees(admin);
                    break;
                }
             case 7:
                {
                    searchForEmployee(admin);
                    break;
                }
             case 8:
                {
                    editEmployeeInfo (admin);
                    break;
                }
             case 9:
                {
                    admin->displayInfo();
                    break;
                }
             case 10:
                {
                    updatePassword(admin);
                    break;
                }
             case 11:
                {
                    return true;
                }
             default:
                {
                    cout <<" Your Choice is not found\n";
                    adminOptions(admin);
                }
             }
         Back(admin);
        }
    ///////////////////////////////////////////////////////////////////
        static void Back(Admin* admin) {
            system("pause");
            printAdminMenu();
            adminOptions(admin);
        }
    ///////////////////////////////////////////////////////////////////
    static void updatePassword(Admin* admin) {
        string password;
		getPasswordFromAdmin:cout << "Please Enter Your New Password: ";
		cin >> password;
        try{
        admin->setPassword(password);
        updateAdminTxt();
        cout << "\tPassword Updated successfully" << endl;
        }catch(string error){
            cout<<error<<endl;
            int c;
            cout <<"1/Update Password\n2/Return\n";
            cin >> c;
            switch (c)
            {
            case 1:
                goto getPasswordFromAdmin;
                break;
            case 2:
                printAdminMenu();
                break;
            default:
                cout << "Invalid option\n";
                printAdminMenu();
                break;
            }
        }

    }

    ///////////////////////////////////////////////////////////////////
        static Admin* login(int id, string password)
        {
            Admin* admin = NULL;
            for (int i = 0; i < adminsVec.size(); i++) {
                if (adminsVec[i].getId() == id) {
                    admin = &adminsVec[i];
                }
            }
            if (admin == NULL) {

                cout << "You Have Entered Invalid ID OR Password " << endl;
                cout << "----------------------------------------" << endl;
                return NULL;
            }
            else
            {
                if (admin->getPassword() == password)
                {
                    return admin;
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
