#include "classes.h"

using namespace std;

int main()
{
    cout << "\n\n                                            ---------HOSPITAL MANAGEMENT SYSTEM---------" << endl;
    cout << endl;
    cout << "                                             Welcome to Hospital Management System CLI!" << endl;
    cout << endl;

    while(true)
    {
        int input;

        cout << "                                             ----------HOSPITAL MANAGEMENT SYSTEM--------\n" << endl;
        cout << "                                             Please select amongst the following options:" << endl;
        cout << "                                             1. Doctor Manager" << endl;
        cout << "                                             2. Staff Manager" << endl;
        cout << "                                             3. Patient Manager" << endl;
        cout << "                                             4. exit" << endl;
        cout << "                                             --------------------------------------------\n" << endl;

        cout << "Enter option: ";
        cin >> input;

        int sub_input;

        if(input == 1)
        {
            do
            {
                cout << "--------------------DOCTOR MANAGER------------------------\n" << endl;
                cout << "Please select amongst the following options:" << endl;
                cout << "1. Search by name" << endl;
                cout << "2. Search by Id" << endl;
                cout << "3. Back" << endl;
                cout << "--------------------------------------------\n" << endl;

                cout << "Enter option: ";
                cin >> sub_input;
                cin.ignore();

                if(sub_input == 1)
                {
                    string name;

                    cout << "Enter Employee Name: ";
                    getline(cin, name);

                    search_doctor_by_name(name);
                }
                else if(sub_input == 2)
                {
                    int id;

                    cout << "Enter Employee id: ";
                    cin >> id;

                    search_doctor_by_id(id);
                }
                else if(sub_input != 3)
                {
                    cout << "Invalid Input" << endl;
                    cout << endl;
                }
            } while (sub_input != 3);
        }
        else if(input == 2)
        {
             do
            {
                cout << "---------------------STAFF MANAGER------------------------\n" << endl;
                cout << "Please select amongst the following options:" << endl;
                cout << "1. Search by name" << endl;
                cout << "2. Search by Id" << endl;
                cout << "3. Back" << endl;
                cout << "--------------------------------------------\n" << endl;

                cout << "Enter option: ";
                cin >> sub_input;
                cin.ignore();

                if(sub_input == 1)
                {
                    string name;

                    cout << "Enter Employee Name: ";
                    getline(cin, name);

                    search_staff_by_name(name);
                }
                else if(sub_input == 2)
                {
                    int id;

                    cout << "Enter Employee id: ";
                    cin >> id;

                    search_staff_by_id(id);
                }
                else if(sub_input != 3)
                {
                    cout << "Invalid Input" << endl;
                    cout << endl;
                }
            } while (sub_input != 3);
        }
        else if(input == 3)
        {
             do
            {
                cout << "-------------------PATIENT MANAGER------------------------\n" << endl;
                cout << "Please select amongst the following options:" << endl;
                cout << "1. Search by name" << endl;
                cout << "2. Search by Id" << endl;
                cout << "3. Schedule Appointment" << endl;
                cout << "4. Cancel Appointment" << endl;
                cout << "5. View Assigned Doctor details" << endl;
                cout << "6. Back" << endl;
                cout << "--------------------------------------------\n" << endl;

                cout << "Enter option: ";
                cin >> sub_input;
                cin.ignore();

                if(sub_input == 1)
                {
                    string name;

                    cout << "Enter Patient Name: ";
                    getline(cin, name);

                    search_patient_by_name(name);
                }
                else if(sub_input == 2)
                {
                    int id;

                    cout << "Enter Patient id: ";
                    cin >> id;

                    search_patient_by_id(id);
                }
                else if(sub_input == 3)
                {
                    bool found = false;
                    int id;

                    cout << "Enter Patient id: ";
                    cin >> id;

                    Patient *ptr = NULL;

                    for (int i = 0; i < patient_count; i++)
                    {
                        if(patients[i].get_id() == id)
                        {
                            ptr = &patients[i];
                            found = true;
                            break;
                        }
                    }

                    if(found)
                    {
                        ptr->schedule_appointment();
                    }
                    else
                    {
                        cout << "Patient Not found!" << endl;
                        cout << endl;
                    }
                }
                else if(sub_input == 4)
                {
                    bool found = false;
                    int id;

                    cout << "Enter Patient id: ";
                    cin >> id;

                    Patient *ptr = new Patient;

                    for (int i = 0; i < patient_count; i++)
                    {
                        if(patients[i].get_id() == id)
                        {
                            ptr = &patients[i];
                            found = true;
                        }
                    }

                    if(found)
                    {
                        ptr->cancel_appointment();
                    }
                    else
                    {
                        cout << "Patient Not found!" << endl;
                        cout << endl;
                    }
                }
                else if(sub_input == 5)
                {
                    bool found = false;
                    int id;

                    cout << "Enter Patient id: ";
                    cin >> id;

                    Patient *ptr = new Patient;

                    for (int i = 0; i < patient_count; i++)
                    {
                        if(patients[i].get_id() == id)
                        {
                            ptr = &patients[i];
                            found = true;
                        }
                    }

                    if(found)
                    {
                        cout << "Assigned doctor is:" << endl;
                        cout << endl;
                        cout << "Patient: " << ptr->get_name() << endl;
                        ptr->get_doctor_details();
                    }
                    else
                    {
                        cout << "Patient Not found!" << endl;
                        cout << endl;
                    }
                }
                else if(sub_input != 6)
                {
                    cout << "Invalid Input" << endl;
                    cout << endl;
                }

            } while (sub_input != 6);
        }
        else if(input == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid Input! Pls enter a valid input!" << endl;
            cout << endl;
        }
    }

    cout << "\n\n                                             ------------------THANK YOU-----------------" << endl;

    return 0;
}