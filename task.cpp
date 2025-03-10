#include <iostream>
#include <string.h>
#include "employee.h"

using namespace std;

// Гарааны хоосон утгуудыг шинжүүдэд онооно
void employee::setInitial() {
    emp_id=0;
    strcpy(emp_name, "");
    strcpy(emp_role, "ajilchin");
    emp_work_time=0;
    emp_hourly_rate=10000;
}

// Гараас утгуудыг авч шинжүүдэд хадгална
void employee::getData() {
    char name[20];
    bool status;
    cout << "Ajilchnii dugaariig oruulna uu?" << endl;
    cin >> emp_id;

    cout << "Ajilchnii neriig oruulna uu?" << endl;
    cin >> name;
    strcpy(emp_name, name);

    cout << "Ajilchingaas uur alban tushaaltai bol 1, ugui bol 0 gej oruulna uu?" << endl;
    cin >> status;
    if (status==1) {
        char role[10];
        cout << "Alban tushaaliig oruulna uu?" << endl;
        cin >> role;
        strcpy(emp_role, role);
    }
    cout << endl;
}

// Шинжүүдийн утгуудыг хэрэглэгчид ойлгомжтойгоор хэвлэнэ
void employee::printData() {
    cout << emp_id << " dugaartai ajilchnii medeelel:" << endl;
    cout << "Ner: " << emp_name << endl;
    cout << "Alban tushaal: " << emp_role << endl;
    cout << "Ajillasan tsag: " << emp_work_time << endl;
}

// Ажилчны цалинг тооцоолно
float employee::calcSalary() {
    float salary = emp_hourly_rate*emp_work_time;

    if (strcmp("Zahiral",emp_role)==0 || strcmp("zahiral",emp_role)==0) {
        salary += calcBossSalary();
    }
    
    return (salary);
}

// Хэрэв захирал тушаалтай бол цалинг тооцоолно
float employee::calcBossSalary() {
    return (emp_hourly_rate*emp_work_time*1.5);
}

// Тухайн өдөрт ажилласан цагийг нэмэгдүүлнэ
bool employee::addWorkTime(float hour) {
    bool ret_value;
    if (hour<0 || hour>24) {
        ret_value=0;
    } else {
        ret_value=1;
        emp_work_time += hour;
    }

    return ret_value;
}


int main() {
    // 3 ширхэг ажилчин объектуудыг үүсгэнэ
    employee worker1, worker2, worker3;

    // Тус тус гарааны хоосон утгуудыг онооно
    worker1.setInitial();
    worker2.setInitial();
    worker3.setInitial();

    cout << endl;

    // Тус тусын шинжийн утгуудыг гараас авна
    worker1.getData();
    worker2.getData();
    worker3.getData();

    cout << endl;

    // Гараас ажилласан цагийн утгыг аваад хадгалах хувьсагч
    float hour;

    // Гараас авсан цагийн утга зөв утга эсэхийг шалгаж байж давталтаас гарна
    while (1) {
        cout << "1-r ajilchnii unuudur ajillasan tsag: " << endl;
        cin >> hour;
        if (worker1.addWorkTime(hour)==0) {
            cout << "Invalid Time" << endl;
        } else {break;};
    };

    while(1) {
        cout << "2-r ajilchnii unuudur ajillasan tsag: " << endl;
        cin >> hour;
        if (worker2.addWorkTime(hour)==0) {
            cout << "Invalid Time" << endl;
        } else {break;};
    }

    while(1) {
        cout << "3-r ajilchnii unuudur ajillasan tsag: " << endl;
        cin >> hour;
        if (worker3.addWorkTime(hour)==0) {
            cout << "Invalid Time" << endl;
        } else {break;};
    }
    

    cout << endl;
    // Ажилчны шинжийн утгуудыг тус тус хэвлэхдээ мөн цалинг тооцоолж хэвлэнэ
    worker1.printData();
    cout << "Tsalin: " << worker1.calcSalary() << endl << endl;
    worker2.printData();
    cout << "Tsalin: " << worker2.calcSalary() << endl << endl;
    worker3.printData();
    cout << "Tsalin: " << worker3.calcSalary() << endl << endl;

}