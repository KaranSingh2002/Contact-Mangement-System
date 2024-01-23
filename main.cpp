#include<iostream>
#include<fstream>
using namespace std;

// Global variables
string fname, lname, phone_num;

// Function prototypes
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{
    short int choice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\tContact Management.";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input !";
            cout << "\n\tPress Any Key To Continue..";
            cin.ignore();
            cin.get();
            main();
    }
    return 0;
}

void self_exit()
{
    system("cls");
    cout << "\n\n\n\t\tThank You For Using !";
    exit(1);
}

void help()
{
    cout << "This displays help";
}

void addContact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");
    cout << "\n\n\tEnter First Name : ";
    cin >> fname;
    cout << "\n\tEnter Last Name : ";
    cin >> lname;
    cout << "\n\tEnter 10-Digit Phone Number : ";
    cin >> phone_num;

    if(check_digits(phone_num) && check_numbers(phone_num))
    {
        if(phone.is_open())
        {
            phone << fname << " " << lname << " " << phone_num << endl;
            cout << "\n\tContact Saved Successfully !";
        }
        else
        {
            cout << "\n\tError Opening File !";
        }
    }
    else
    {
        cout << "\n\tInvalid Phone Number Format.";
    }

    phone.close();
}

void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout << "\n\tEnter Name To Search : ";
    cin >> keyword;

    while(myfile >> fname >> lname >> phone_num)
    {
        if(keyword == fname || keyword == lname)
        {
            system("cls");
            cout << "\n\n\n\t\tContact details..";
            cout << "\n\n\tFirst Name : " << fname;
            cout << "\n\tLast Name : " << lname;
            cout << "\n\tPhone Number : " << phone_num;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\n\tNo Such Contact Found";
}

bool check_digits(string x)
{
    return x.length() == 10;
}

bool check_numbers(string x)
{
    for(int i=0; i < x.length(); i++)
    {
        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            return false;
        }
    }
    return true;
}
