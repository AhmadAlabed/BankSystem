#ifndef PUBLICVARIABLES_H
#define PUBLICVARIABLES_H
#include "vector"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class PublicVariables
{
    public:
        static vector <Client> clientsVec;
        static vector <Employee> employeesVec;
        static  vector<Admin> adminsVec;

};

#endif // PUBLICVARIABLES_H
