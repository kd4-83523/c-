
#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        id = 0;
        salary = 0;
    }

    Employee(int, double)
    {
        this->id = id;
        this->salary = salary;
    }

    void set(int id)
    {
        this->id = id;
    }

    int get(int id)
    {
        return id;
    }

    void set(double salary)
    {
        this->salary = salary;
    }

    virtual void accept()
    {
        cout << "Enter the id:" << endl;
        cin >> id;
        cout << "Enter the salary:" << endl;
        cin >> salary;
    }

    virtual void display()
    {
        cout << "id:" << id << ","
             << "salary:" << salary << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter bonus:" << endl;
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "bonus:" << bonus << endl;
    }

public:
    Manager()
    {
        bonus = 0;
    }
    Manager(double bonus, int id, double salary) : Employee(id, salary)
    {
        this->bonus = bonus;
    }

    void set(double bonus)
    {
        this->bonus = bonus;
    }
    double get(double bonus)
    {
        return bonus;
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commision;

protected:
    void acceptSalesman()
    {
        cout << "Enter commision:" << endl;
        cin >> commision;
    }

    void displaySalesman()
    {
        cout << "commision:" << commision << endl;
    }

public:
    Salesman()
    {
        commision = 0;
    }

    Salesman(double commision, int id, double salary) : Employee(id, salary)
    {
        this->commision = commision;
    }

    void set(double commision)
    {
        this->commision = commision;
    }

    double get(double commision)
    {
        return commision;
    }

    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "Inside Salesmanager constructor...." << endl;
    }

    SalesManager(int id, double salary, double bonus, double commision) : Manager(id, salary, bonus), Salesman(id, salary, commision)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{
    int choice, choice1;
    int Mcount=0;
    int Scount=0;
    int SMcount=0;

    int index = 0;
    Employee *arr[5];
    do
    {
        cout << "0. Exit" << endl;
        cout << "1. Accept employee:" << endl;
        cout << "2. count employee:" << endl;
        cout << "3. display all managers list:" << endl;
        cout << "4. display all salesmans list:" << endl;
        cout << "5. display all salesmanagers list:" << endl;
        cout << "Enter your choice - ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Thanks for using app..." << endl;
            break;
        case 1:
            
                cout << "1.Accept Manager" << endl;
                cout << "2.Accept Salesman" << endl;
                cout << "3.Accept SalesManager" << endl;
                cout << "4.Enter your choice" << endl;
                cin >> choice1;

                switch (choice1)
                    {
                        case 1:
                            if(index<5)
                            {
                                arr[index] = new Manager();
                                arr[index]->accept();
                                index++;
                                cout << "Manager Details Added" << endl;
                            }
                            else
                            {
                                cout << "EMPLOYEE VACANCY IS FULL.." << endl;
                            }
                            break;
                    

                        case 2:
                            if(index<5)
                            {
                                arr[index] = new Salesman();
                                arr[index]->accept();
                                index++;
                                cout << "Salesman Details Added" << endl;
                            }
                            else
                            {
                                cout << "EMPLOYEE VACANCY IS FULL.." << endl;
                            }
                            break;

                        case 3:
                            if(index<5)
                            {
                                arr[index] = new SalesManager();
                                arr[index]->accept();
                                index++;
                                cout << "Salesmanager Details Added" << endl;
                            }
                            else
                            {
                                cout << "EMPLOYEE VACANCY IS FULL.." << endl;
                            }
                            break;
                    }
            
        case 2:
            {
                for (int i=0;i<index;i++)
                {
                    if(typeid(*arr[i]).name()==typeid(Manager).name())
                    {
                        Mcount++;
                    }
                     if(typeid(*arr[i]).name()==typeid(Salesman).name())
                    {
                        Scount++;
                    }
                     if(typeid(*arr[i]).name()==typeid(SalesManager).name())
                    {
                        SMcount++;
                    }

                }
                cout<<"Number of Managers: "<<Mcount<<endl;
                cout<<"Number of Salesman: "<<Scount<<endl;
                cout<<"Number of SalesManager: "<<SMcount<<endl;
            } 
            break;

        case 3:
            {
                cout<<"----------Managers list----------"<<endl;
                int count=0;
                for(int i=0;i<index;i++)
                {
                    if(typeid(*arr[i])==typeid(Manager))
                    {
                        arr[i]->display();
                        count++;
                    }
                }
                if(count==0)
                {
                    cout<<"There are no manager in company"<<endl;
                }
            }
            break;

        case 4:
            {
                cout<<"----------Salesman list----------"<<endl;
                int count=0;
                for(int i=0;i<index;i++)
                {
                    if(typeid(*arr[i])==typeid(Salesman))
                    {
                        arr[i]->display();
                        count++;
                    }
                }
                if(count==0)
                {
                    cout<<"There are no Salesman in company"<<endl;
                }
            }
            break;

        case 5:
            {
                cout<<"----------SalesManager list----------"<<endl;
                int count=0;
                for(int i=0;i<index;i++)
                {
                    if(typeid(*arr[i])==typeid(SalesManager))
                    {
                        arr[i]->display();
                        count++;
                    }
                }
                if(count==0)
                {
                    cout<<"There are no SalesManager in company"<<endl;
                }
            }
            break;

        deafult:
            cout<<"Wrong choice......"<<endl;
            break;


              

        }
    }while(choice!=0);

for(int i=0;i<index;i++)
{
    delete arr[i];
    arr[i]=NULL;
}

    return 0;
}