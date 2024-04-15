#include <iostream>

using namespace std;

class Person
{
    protected:
        string name;
        int age;
        char gender;
        int contact;

    public:
        virtual void display_details()
        {}
};

class Employee : public Person
{
    protected:
        int emp_id;
        double salary;
        double years_experience;

    public:
        void display_details()
        {}
};

class Doctor : public Employee
{
    protected:
        string specialization;
    
    public:
        void display_details()
        {
            cout << "Doctor Details:-\n" << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Gender: " << gender << endl;
            cout << "Contact: " << "+91 " << contact << endl;
            cout << "Employee ID: " << emp_id << endl;
            cout << "Salary: Rs." << salary << endl;
            cout << "Years of Experience: " << years_experience << endl;
            cout << "Specialization: " << specialization << endl;
            cout << endl;
        }
};