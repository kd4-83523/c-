#include<iostream>
using namespace std;

class Date {
    private:
    int day;
    int month;
    int year;

    public:
    void acceptDate()
    {
        cout<<"Enter a day : ";
        cin>>day;
        cout<<"Enter a month : ";
        cin>>month;
        cout<<"Enter a year : ";
        cin>>year;
    }

    void displayDate()
    {
        cout<<"Date : "<<day<<" - "<<month<<" - "<<year<<endl;
    }
};

class Person {
    private:
    string name;
    string address;
    Date *dptr;

    public:
    void acceptPerson()
    {
        cout<<"Enter a Person Name : ";
        cin>>name;
        cout<<"Enter a Person Address : ";
        cin>>address;
    }
    void addDate()
    {
        dptr = new Date;
        dptr->acceptDate();
    }
    void displayPerson()
    {
        cout<<"Person Name :"<<name<<endl;
        cout<<"Person Address : "<<address<<endl;
        
        if(dptr != NULL)
        {
            dptr->displayDate();
        }
    }

    ~Person()
    {
        delete dptr;
        dptr = NULL;
    }
};

class Employee{
    private :
    int id;
    double salary;
    int dept;
    Date d;

    public:
    void acceptEmployee()
    {
        cout<<"Enter an employee id :";
        cin>>id;
        cout<<"Enter an employee salary :";
        cin>>salary;
        cout<<"Enter an  employee dept :";
        cin>>dept;

        d.acceptDate();
    }

    void displayEmployee()
    {
        cout<<"Employee Id : "<<id<<endl;
        cout<<"Employee Salary : "<<salary<<endl;
        cout<<"Employee Department :"<<dept<<endl;

        d.displayDate();
    }
};

int main()
{
    Person p;
    Employee e;

    int choice;
    do
    {
        cout<<"0: Exit "<<endl;
        cout<<"1: Accept Person "<<endl;
        cout<<"2: Display Person "<<endl;
        cout<<"3: Accept Employee "<<endl;
        cout<<"4: Display Employee "<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>choice;

        switch (choice)
        {
        case 0:
            cout<<"Thank You !!"<<endl;
            break;
        
        case 1:
            p.acceptPerson();
            p.addDate();
            break;

        case 2:
            p.displayPerson();
            break;

        case 3:
            e.acceptEmployee();
            break;

        case 4:
            e.displayEmployee();
            break;

        default:
            cout<<"Invalid Choice !!"<<endl;
            break;
        }
    } while (choice != 0);
    
    return 0;
}