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

        if(input == 1)
        {
            // doctor manager
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