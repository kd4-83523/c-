
#include<iostream>
using namespace std;

class Product
{
    private:
    int id;
    string title;
    double price;

    public:
    Product()
    {
        id=1;
        title="uhbu";
        price=1000.00;
    }
 
    virtual void acceptProduct()
    {
        cout<<"Id: "<<endl;
        cin>>id;
        cout<<"Title: "<<endl;
        cin>>title;
        cout<<"Price: "<<endl;
        cin>>price;
    }

    virtual void displayProduct()
    {
        cout<<"Id: "<<id<<","<<"Title: "<<title<<","<<"Price: "<<price<<endl;
    }
    double getPrice()
     {
         return price;
     }
    void setPrice(double price)
     {
        this->price = price;
     }
     
};

class Book: public Product
{
    private:
    string author;

    public:
    Book()
    {
        author="xyz";
    }
 
    void acceptProduct()
    {
        cout<<"Author: ";
        cin>>author;
        cout<<"Enter book detail: "<<endl;
        Product::acceptProduct();
        
        double p;
        p=getPrice();
            p=(p-0.1*p);
            setPrice(p);

    }

    void displayProduct()
    {
        cout<<"Author: "<<author<<endl;
        cout<<"Book details are:";
        Product::displayProduct();
    }   
};

class Tape: public Product
{
    private:
    string artist;

    public:
    Tape()
    {
        artist="pqr";
    }
 
    void acceptProduct()
    {
        cout<<"Artist: ";
        cin>>artist;
        cout<<"Enter tape detail: "<<endl;
        Product::acceptProduct();
        
        double p;
        p=getPrice();
            p=(p-0.1*p);
            setPrice(p);
    }

    void displayProduct()
    {
        cout<<"Artist: "<<artist<<endl;
        cout<<"Tape details are:";
        Product::displayProduct();
        
    }
};



int main()
{
   
Product *arr[3];
int choice;
int index=0;
do
{  
    cout<<endl;
    cout<<"0 . EXIT"<<endl;
    cout<<"1 . Book"<<endl;
    cout<<"2 . Tape"<<endl;
    cout<<"3 . Calculate Total"<<endl;
    cout<<"4 . To see all details"<<endl;       
    cout<<"enter choice : ";
    cin>>choice;

            switch(choice)
            {
            case 0:
                cout<<"thank for using app...."<<endl;
                break;

            case 1:
                if(index<3)
                {
                  arr[index]=new Book();        //upcasting
                  arr[index]->acceptProduct();         
                  index++;
                }
                else
                {
                    cout<<"list is full"<<endl;
                }
                break;


            case 2:
                 if(index<3)
                {
                  arr[index]=new Tape();
                  arr[index]->acceptProduct();  
                  index++;
                }
                else
                {
                    cout<<"list is full"<<endl;
                }
                break;


            case 3:
                { 
                    double total=0;
                   for (int i = 0; i < index; i++)
                   {
                    total=total+arr[i]->getPrice();
                   }

                   cout<<"total is : "<<total;
                   

                }
                break;

            case 4:
                for(int i=0;i<index;i++)
                {
                    arr[i]->displayProduct();
                    cout<<endl;
                    cout<<endl;
                }
               break;


            default:
    
                  cout<<"Wrong choice"<<endl;
    
              break;

            }
} while (choice!=0);

for (int i = 0; i < index; i++)
{
    delete arr[i];
    arr[i]=NULL;
}
    return 0;

}
