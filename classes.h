#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
    protected:
        string name;
        int age;
        char gender;
        long long int contact;

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

        virtual void display_details()
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
        {
            Employee::count++;
        }

        Doctor(string name, int age, char gender, long long int contact, double salary, double years_experience, string specialization)
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

        ~Doctor()
        {
            Employee::count--;
        }

        friend void search_doctor_by_name(string name);
        friend void search_doctor_by_id(int id);
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
        {
            Employee::count++;
        }

        Staff(string name, int age, char gender, long long int contact, double salary, double years_experience, string job_description)
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

        ~Staff()
        {
            Employee::count--;
        }

        friend void search_staff_by_name(string name);
        friend void search_staff_by_id(int id);
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
        {
            Patient::count++;
        }

        Patient(string name, int age, char gender, long long int contact, Doctor doctor_assigned)
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

        void set_data(string name, int age, char gender, long long int contact, Doctor doctor_assigned)
        {
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->contact = contact;
            this->patient_id = count;
            this->doctor_assigned = doctor_assigned;
            this->is_appointment_scheduled = false;
        }

        ~Patient()
        {
            Patient::count--;
        }
};

int Employee::count = 0;
int Patient::count = 0;

Doctor doctor1("Dr. Rajesh Kumar", 40, 'M', 9876543210, 60000.0, 15.0, "Neurology");
Doctor doctor2("Dr. Pooja Patel", 45, 'F', 9876543211, 55000.0, 12.0, "Oncology");
Doctor doctor3("Dr. Vikram Singh", 50, 'M', 9876543212, 70000.0, 20.0, "Orthopedics");
Doctor doctor4("Dr. Neha Sharma", 55, 'F', 9876543213, 50000.0, 10.0, "Pediatrics");
Doctor doctor5("Dr. Ritu Reddy", 60, 'F', 9876543214, 65000.0, 18.0, "Dermatology");

Staff staff1("Amit Patel", 25, 'M', 9876543200, 35000.0, 4.5, "Nurse");
Staff staff2("Priya Sharma", 30, 'F', 9876543201, 30000.0, 3.0, "Receptionist");
Staff staff3("Rahul Singh", 35, 'M', 9876543202, 40000.0, 5.5, "Janitor");
Staff staff4("Sneha Gupta", 28, 'F', 9876543203, 32000.0, 2.0, "Lab Technician");
Staff staff5("Ananya Reddy", 40, 'F', 9876543204, 38000.0, 6.0, "Pharmacist");

Patient patient1("Rahul", 25, 'M', 9876543200, doctor1);
Patient patient2("Priya", 30, 'F', 9876543201, doctor2);
Patient patient3("Vikram", 35, 'M', 9876543202, doctor3);
Patient patient4("Neha", 28, 'F', 9876543203, doctor4);
Patient patient5("Ritu", 40, 'F', 9876543204, doctor5);
Patient patient6("Amit", 32, 'M', 9876543205, doctor1);
Patient patient7("Kavita", 28, 'F', 9876543206, doctor2);
Patient patient8("Suresh", 33, 'M', 9876543207, doctor3);
Patient patient9("Mona", 38, 'F', 9876543208, doctor4);
Patient patient10("Rajesh", 45, 'M', 9876543209, doctor5);


Doctor doctors[] = {doctor1, doctor2, doctor3, doctor4, doctor5};
Staff staff[] = {staff1, staff2, staff3, staff4, staff5};
Patient patients[] = {patient1, patient2, patient3, patient4, patient5, patient6, patient7, patient8, patient9, patient10};

const int doctor_count = 5;
const int staff_count = 5;
const int patient_count = 10;

void search_doctor_by_name(string name)
{
    bool is_found = false;
    for(int i = 0; i < doctor_count; i++)
    {
        if(doctors[i].name == name)
        {
            doctors[i].display_details();
            is_found = true;
            break;
        }
    }

    if(!is_found)
    {
        cout << "Doctor details not found!" << endl;
        cout << endl;
    }
}

void search_doctor_by_id(int id)
{
    bool is_found = false;
    for(int i = 0; i < doctor_count; i++)
    {
        if(doctors[i].emp_id == id)
        {
            doctors[i].display_details();
            is_found = true;
            break;
        }
    }

    if(!is_found)
    {
        cout << "Doctor details not found!" << endl;
        cout << endl;
    }
}

void search_staff_by_name(string name)
{
    bool is_found = false;
    for(int i = 0; i < staff_count; i++)
    {
        if(staff[i].name == name)
        {
            staff[i].display_details();
            is_found = true;
            break;
        }
    }

    if(!is_found)
    {
        cout << "Staff details not found!" << endl;
        cout << endl;
    }
}

void search_staff_by_id(int id)
{
    bool is_found = false;
    for(int i = 0; i < staff_count; i++)
    {
        if(staff[i].emp_id == id)
        {
            staff[i].display_details();
            is_found = true;
            break;
        }
    }

    if(!is_found)
    {
        cout << "Staff details not found!" << endl;
        cout << endl;
    }
}

void search_patient_by_name(string name)
{
    bool is_found = false;
    for(int i = 0; i < staff_count; i++)
    {
        if(patients[i].name == name)
        {
            patients[i].display_details();
            is_found = true;
            break;
        }
    }

    if(!is_found)
    {
        cout << "Patient details not found!" << endl;
        cout << endl;
    }
}

#endif