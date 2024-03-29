
#include<iostream>
using namespace std;

class Date 
{
  private:
     int day;
     int month;
     int year;

  public:
    
      Date()
      {
        day = 0;
        month = 0;
        year = 0;
      }
     
     void acceptDate()
     {
        cout<<"Enter the day-"<<endl;
        cin>>day;
        cout<<"Enter the month-"<<endl;
        cin>>month;
        cout<<"Enter the year-"<<endl;
        cin>>year;
     }

     void displayDate()
     {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
     }
     
};

class Person
{
   private:
       string name;
       string address;
       Date dob;
       
   public:
        
       virtual void acceptData()
       {
        cout<<"Enter the name-"<<endl;
        cin>>name;
        cout<<"Enter the address-"<<endl;
        cin>>address;
        dob.acceptDate();
       }

       virtual void displayData()
       {
        cout<<"name:"<<name<<","<<"address:"<<address<<endl;
        cout<<"dob: "<<endl;
        dob.displayDate();
       }

};

class Employee: public Person
{
    private:
      int id;
      double salary;
      string dept;
      Date doj;

    public:
      void acceptData()
      {
        cout<<"Enter id- "<<endl;
        cin>>id;
        cout<<"Enter salary- "<<endl;
        cin>>salary;
        cout<<"Enter dept- "<<endl;
        cin>>dept;
        cout<<"doj- "<<endl;
        doj.acceptDate();
        Person::acceptData();
      }

      void displayData()
      {
        cout<<"id: "<<id<<","<<"salary: "<<salary<<","<<"dept- "<<dept<<endl;
        cout<<"doj: "<<endl;
        doj.displayDate();
        Person::displayData();
      }
};

int main()
{
  Person *pptr = new Employee();
    pptr->acceptData();
    pptr->displayData(); 
    delete pptr;
    pptr = NULL;

    return 0;
}
