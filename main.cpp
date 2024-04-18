#include "classes.h"

using namespace std;

int main()
{
    cout << "\n\n-----------HOSPITAL MANAGEMENT SYSTEM----------------" << endl;
    cout << endl;
    cout << "Welcome to Hospital Management System CLI!" << endl;
    cout << endl;

    while(true)
    {
        int input;

        cout << "--------------------------------------------\n" << endl;
        cout << "Please select amongst the following options:" << endl;
        cout << "1. Doctor Manager" << endl;
        cout << "2. Staff Manager" << endl;
        cout << "3. Patient Manager" << endl;
        cout << "4. exit" << endl;
        cout << "--------------------------------------------\n" << endl;

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

                if(sub_input == 1)
                {
                    string name;

                    cout << "Enter Doctor Name: ";
                    getline(cin, name);

                    getchar();

                    search_doctor_by_name(name);
                }
                else if(sub_input == 2)
                {
                    int id;

                    cout << "Enter Doctor id: ";
                    cin >> id;

                    search_doctor_by_id(id);
                }
                else if(sub_input != 1 || sub_input != 2 || sub_input != 3)
                {
                    cout << "Invalid Input" << endl;
                    cout << endl;
                }
            } while (sub_input != 3);
        }
        else if(input == 2)
        {
            // staff manager
        }
        else if(input == 3)
        {
            // patient manager
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

    cout << "\n\n--------------THANK YOU--------------" << endl;

    return 0;
}