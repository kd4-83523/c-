
#include<iostream>
using namespace std;

class Tollbooth
{
    private :
    unsigned int tnc1;
    unsigned int tnc2;
    double tam;
    public:
    Tollbooth()
    {
        tnc1 = 0;
        tnc2 = 0;
        tam = 0;
    }    
    void payingCar()
    {
        tnc1 = ++tnc1;
        tam = tam+0.50;
    }
    void noPayCar()
    {
        tnc2 = ++tnc2;
    }
    void printOnConsole()
    {
        cout << "----------DETAILS----------" << endl;
        cout<< "TOTAL NO OF CARS : " << tnc1+tnc2 << endl;
        cout<<"TOTAL NO OF PAYING CARS : " << tnc1 << endl;
        cout<<"TOTAL NO OF NON PAYING CARS : " << tnc2 << endl;
        cout<<"TOTAL AMOUNT : " << tam << endl;
    }
};
 int main()
 {
    int choice;
    Tollbooth t;
    do
    {
        cout << "0. EXIT " << endl;
        cout << "1. PAYING CARS " << endl;
        cout << "2. NON PAYING CARS " << endl;
        cout << "3. DISPLAY DETAILS " << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice ;
        switch(choice)
        {
            case 0:
                cout << "THANK YOU FOR USING OUR APP................" << endl;
                break;

            case 1:
                t.payingCar();
                break;

            case 2:
                t.noPayCar();
                break;

            case 3:
                t.printOnConsole();
                break;

            default:
                cout << "WRONG CHOICE........" << endl;
                break;
        }
    }while(choice != 0);
 }
