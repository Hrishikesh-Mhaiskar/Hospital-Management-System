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
        static int count;

        void display_details()
        {}
};

class Doctor : public Employee
{
    protected:
        string specialization;
        int num_appointments;
    
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
            cout << "No of appointments: " << num_appointments << endl;
            cout << endl;
        }

        string get_name()
        {
            return name;
        }

        void add_appointment()
        {
            num_appointments++;
        }

        void remove_appointment()
        {
            num_appointments--;
        }

        Doctor()
        {}

        Doctor(string name, int age, char gender, int contact, double salary, double years_experience, string specialization)
        {
            Employee::count++;

            this->name = name;
            this->age = age;
            this->gender = gender;
            this->contact = contact;
            this->emp_id = Employee::count;
            this->salary = salary;
            this->years_experience = years_experience;
            this->specialization = specialization;
        }
};

class Staff : public Employee
{
    protected:
        string job_description;
    
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
            cout << "Job Description: " << job_description << endl;
            cout << endl;
        }

        Staff()
        {}

        Staff(string name, int age, char gender, int contact, double salary, double years_experience, string job_description)
        {
            Employee::count++;

            this->name = name;
            this->age = age;
            this->gender = gender;
            this->contact = contact;
            this->emp_id = Employee::count;
            this->salary = salary;
            this->years_experience = years_experience;
            this->job_description = job_description;
        }
};

class Patient : public Person
{
    protected:
        int patient_id;
        Doctor doctor_assigned;
        bool is_appointment_scheduled;
    
    public:
        static int count;

        void display_details()
        {
            cout << "Doctor Details:-\n" << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Gender: " << gender << endl;
            cout << "Contact: " << "+91 " << contact << endl;
            cout << "Patient ID: " << patient_id << endl;
            cout << "Doctor Name: " << doctor_assigned.get_name();
            cout << "Appointment Status: " << (is_appointment_scheduled)? "Scheduled\n" : "Not Scheduled\n";
            cout << endl;
        }

        void schedule_appointment()
        {
            if(is_appointment_scheduled)
            {
                cout << "Appointment already Scheduled! Pls cancel previous one to schedule a new one!" << endl;
                cout << endl;
            }
            else
            {
                doctor_assigned.add_appointment();
                is_appointment_scheduled = true;
                cout << "Appointment Scheduled Successfully!" << endl;
                cout << endl;
            }
        }

        void cancel_appointment()
        {
            if(!is_appointment_scheduled)
            {
                cout << "No appointment scheduled!" << endl;
                cout << endl;
            }
            else
            {
                doctor_assigned.remove_appointment();
                is_appointment_scheduled = false;
                cout << "Appointment cancelled successfully!" << endl;
                cout << endl;
            }
        }

        Patient()
        {}

        void set_data(string name, int age, char gender, int contact, Doctor doctor_assigned)
        {
            Patient::count++;

            this->name = name;
            this->age = age;
            this->gender = gender;
            this->contact = contact;
            this->patient_id = count;
            this->doctor_assigned = doctor_assigned;
            this->is_appointment_scheduled = false;

        }
};

int Employee::count = 0;
int Patient::count = 0;