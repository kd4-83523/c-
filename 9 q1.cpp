#include<iostream>
#include<vector>
using namespace std;

enum EAccountType 
{
    SAVING = 1,
    CURRENT,
    DMAT
};

class InsufficientFundsException 
{
    int accno;
    double currentBalance;
    double withdrawBalance;
    string messages;
    public:
    InsufficientFundsException(int accno, double currentBalance, double withdrawBalance,string messages)
    {
        this->accno = accno;
        this->currentBalance = currentBalance;
        this->withdrawBalance = withdrawBalance;
        this->messages = messages;
    }
    void display()
    {
        cout<<"Error : "<<endl;
        cout<<"Message : "<<messages<<endl;
    }
};

class Account 
{
    int accNo;
    string type;
    double balance;

    public:
    Account()
    {
        this->accNo = 0;
        this->type = "";
        this->balance = 0;
    }
    Account(int accNo, string type, double balance)
    {
        this->accNo = accNo;
        this->type = type;
        this->balance = balance;
    }

    void accept()
    {
        cout<<"Enter Account Number : ";
        cin>>accNo;
        cout<<"Enter Account Type : ";
        cin>>type;
        cout<<"Enter Current Balance : ";
        cin>>balance;
    }   

    void display()
    {
        cout<<"Enter Account Number : "<<accNo<<endl;
        cout<<"Enter Current Balance : "<<balance<<endl;
        cout<<"Enter Account Type : "<<type<<endl;
    }
    void withdraw(double amount)
    {
        if(amount > balance)
        {
            throw InsufficientFundsException(accNo,balance,amount,"Insufficient balance to withdraw");
        }
        balance -= amount;  
    }

    void deposit(double amount)
    {
        if(amount < 0)
        {
            throw InsufficientFundsException(accNo,balance,amount,"Amount should be negative!!");
        }
        balance += amount;
    }

    int getAccNo()
    {
        return accNo;
    }
};

int main()
{
    vector<Account *>accountList;
    Account *aptr;
    int index;
    int accountNo;
    double amount;
    int choice;
    do
    {
        cout<<"0: Exit"<<endl;
        cout<<"1: Add Account"<<endl;
        cout<<"2: Display Account"<<endl;
        cout<<"3: Withdraw"<<endl;
        cout<<"4: Deposit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
        case 0:
        for(int i = 0;i<accountList.size();i++)
        {
            delete accountList[i];
            accountList[i] = NULL;
        }
        cout<<"Thank you for your using account !!"<<endl;
        break;

        case 1:
        aptr = new Account();
        aptr->accept();
        accountList.push_back(aptr);
        break;

        case 2:
        cout<<"============ All account details ================="<<endl;
        for(int i = 0;i<accountList.size();i++)
        {
            accountList[i]->display();
        }
        break;
        
        case 3:
            try 
            {
            cout<<"Enter account number : "<<endl;
            cin>>accountNo;
            cout<<"Enter amount to be withdraw :"<<endl;
            cin>>amount;
            for(int i = 0;i<accountList.size();i++)
            {
                if(accountList[i]->getAccNo() ==  accountNo)
                {
                    accountList[i]->withdraw(amount);
                    cout<<"amount has been debited from your account "<<endl;
                }
            }
            }catch(InsufficientFundsException e)
            {
                    e.display();
            }
            break;

        case 4:
            try 
            {
                cout<<"Enter account number : "<<endl;
                cin>>accountNo;
                cout<<"Enter amount to Deposit :"<<endl;
                cin>>amount;
                for(int i = 0;i<accountList.size();i++)
                {
                    if(accountList[i]->getAccNo() == accountNo)
                    {
                        accountList[i]->deposit(amount);
                        cout<<amount<< "has been credited to your account."<<endl;
                    }
                }
            }catch(InsufficientFundsException e)
            {
                e.display();
            }
        }

    } while (choice != 0);
    
    return 0;
}