#include <iostream>
#include <string.h>
#include "employee.h"

using namespace std;

employee::employee()
{
    emp_id = 0;
    strcpy(emp_name, "Empty");
    strcpy(emp_role, "Worker");
    emp_work_time = 0;
    emp_hourly_rate = 5000;
}

employee::employee(int id = 0, char* name = NULL, char* role = NULL, float work_time = 0, float hourly_rate = 5000)
{
    emp_id = id;
    strcpy(emp_name, name);
    strcpy(emp_role, role);
    emp_work_time = work_time;
    emp_hourly_rate = hourly_rate;
}

employee::~employee()
{
    cout << emp_id << " id-tai ajiltan ustav" << endl;
}

void employee::printData()
{
    cout << get_emp_id() << " id-tai ajilchnii medeelel:" << endl;
    cout << "Ner: " << get_emp_name() << endl;
    cout << "Alban tushaal: " << get_emp_role() << endl;
    cout << "Ajillasan tsag: " << get_emp_work_time() << endl;
    cout << "Tsagiin orlogo: " << get_emp_hourly_rate() << endl
         << endl;
}

float employee::calcSalary()
{
    float salary = emp_hourly_rate * emp_work_time;

    if (strcmp("Zahiral", emp_role) == 0 || strcmp("zahiral", emp_role) == 0)
    {
        salary += calcBossSalary();
    }

    return (salary);
}

float employee::calcBossSalary()
{
    return (emp_hourly_rate * emp_work_time * 1.5);
}

bool employee::addWorkTime(float hour)
{
    bool ret_value;
    if (hour < 0 || hour > 24)
    {
        ret_value = 0;
        cout << "Failed" << endl;
    }
    else
    {
        ret_value = 1;
        emp_work_time += hour;
        cout << "Successful" << endl;
    }

    return ret_value;
}

int employee::get_emp_id() { return emp_id; };
char *employee::get_emp_name() { return emp_name; };
char *employee::get_emp_role() { return emp_role; };
float employee::get_emp_work_time() { return emp_work_time; };
float employee::get_emp_hourly_rate() { return emp_hourly_rate; };

// void employee::set_emp_id();
void employee::set_emp_name(char name[20])
{
    strcpy(emp_name, name);
};
void employee::set_emp_role(char role[10])
{
    strcpy(emp_role, role);
};
// void employee::set_emp_work_time();
void employee::set_emp_hourly_rate(float rate)
{
    emp_hourly_rate = rate;
};

int main()
{
    // 100 ширхэг ажилчин объектын хүснэгт үүсгэнэ
    employee *worker[100]{};
    int i=0;
    int choice;

    while (1)
    {
        cout << "1. Ajiltan oruulah, 2. Erembelj haruulah, 3. Hevleh, 9. Exit" << endl;
        cout << "Songoltiig oruul: ";
        cin >> choice;
        if (choice == 1)
        {
            char name[20];
            char role[10];
            float work_time;
            float hourly_rate;

            cout << "Ajilchnii ner: ";
            cin >> name;
            cout << "Alban tushaal: ";
            cin >> role;
            cout << "Ajillasan tsag: ";
            cin >> work_time;
            cout << "Tsagiin orlogo: ";
            cin >> hourly_rate;

            worker[i] = new employee(i, name, role, work_time, hourly_rate);
            i++;

            cout << "Successful" << endl << endl;
        } else if (choice==2) {

        } else if (choice==3) {
            for (int n=0; n<=i; n++) {
                if (worker[n]->get_emp_id()!=0) {
                    worker[n]->printData();
                }
            }
        } else if (choice==9) {
            break;
        }
        else { cout << "Invalid choice" << endl;}
    }
}