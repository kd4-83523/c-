#include<iostream>
using namespace std;

class Employee
{
    private:
    int id;
    double salary;

    public:
    Employee()
    {
       id=0;
       salary=0;
    }

    Employee(int, double)
    {
       this-> id = id;
       this-> salary = salary;
    }

    void set(int id)
    {
        this->id=id;
    }

    int get(int id)
    {
        return id;
    }

    void set(double salary)
    {
        this->salary=salary;
    }

    
    virtual void accept()
    {
       cout<<"Enter the id:"<<endl;
       cin>>id;
       cout<<"Enter the salary:"<<endl;
       cin>>salary;

    }

    virtual void display()
    {
       cout<<"id:"<<id<<","<<"salary:"<<salary<<endl;
    }
};

class Manager :  virtual public Employee
{
    private:
    double bonus;

    protected:
     void acceptManager()
    {
        cout<<"Enter bonus:"<<endl;
        cin>>bonus;
        
    }

    void displayManager()
    {
        cout<<"bonus:" << bonus <<endl;
        
    }
     
    public:
    Manager()
    {
        bonus=0;
    }
    Manager(double bonus,int id,double salary):Employee(id,salary)
    {
      this->bonus = bonus;
    }

    void set(double bonus)
    {
        this->bonus=bonus;
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

class Salesman:  virtual public Employee
{
    private:
    double commision;

    protected:

    void acceptSalesman()
    {
        cout<<"Enter commision:"<<endl;
        cin>>commision;
        
    }

    void displaySalesman()
    {
        cout<<"commision:"<<commision<<endl;
        
    }

    public:

    Salesman()
    {
        commision=0;
    }

    Salesman(double commision,int id,double salary):Employee(id,salary)
    {
        this->commision=commision;
    }

    void set(double commision)
    {
        this->commision=commision;
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

class SalesManager:public Manager, public Salesman 
{
    public:
    SalesManager()
    {
       cout<<"Inside Salesmanager constructor...."<<endl;
    }

    SalesManager(int id,double salary,double bonus,double commision):Manager(id,salary,bonus),Salesman(id,salary,commision)
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
    SalesManager s1;
    s1.accept();
    s1.display();
    return 0;
}
