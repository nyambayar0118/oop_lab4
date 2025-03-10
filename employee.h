#ifndef employee_h
#define employee_h

// Ажилчин классыг толгой файлд загварчлав
class employee {
    public:
    // Ажилчны дугаар, нэр, албан тушаал, ажилласан цаг, цагт олдог орлогын дүнг хадгална
    int emp_id;
    char emp_name[20];
    char emp_role[10];
    float emp_work_time;
    float emp_hourly_rate;

    // Байгуулагч функцүүд
    employee();
    employee(int,char[],char[],float,float);

    void printData();
    // Ажилчны цалинг тооцоолно
    float calcSalary();
    // Хэрэв захирал тушаалтай бол цалинг тооцоолно
    float calcBossSalary();
    // Тухайн өдөрт ажилласан цагийг нэмэгдүүлнэ
    bool addWorkTime(float);

};

#endif