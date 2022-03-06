//CS20B1127
//Hitesh Gupta
//Program for Inheritance.

// NOTE : The credit and debit in checking account using option 2 and 3 respectively are done without cutting the transaction fee. 

#include <iostream>
using namespace std;  

// Class for storing linked list of Saving Accounts.
class SavingsLL
{
    public:
        int value1;
        double value2;
        double value3;
        SavingsLL *snext;
};   

// Class for storing linked list of Checking Accounts.
class CheckingLL
{
    public:
        int value1;
        double value2;
        double value3;
        CheckingLL *cnext;
};

// Base Class Account
class Account
{
    public:
        int accNum;
        double accBal; 
        // Default constructor.
        Account()
        {
            accNum = 0;
            accBal = 0.0;
        }
        // Parameterised constructor.
        Account(int temp ,double bal)
        {
            accNum = temp;
            if(bal >= 0.0)
                this->accBal = bal;
            else
            {
                this->accBal = 0.0;
                cout << "The initial balance is invalid." << endl;
            }
        }
        // Function to credit amount.
        void credit(double amount)
        {
            if(amount <= 0)
            {
                cout << "The amount is invalid." << endl;
            }
            else
            {
                accBal = accBal + amount;
            }
        }
        // Boolean function to debit amount and return whether the amount is debited or not.
        bool debit(double amount) 
        {
            if(amount <= 0)
            {
                cout << "The amount is invalid." << endl;
                return false;
            }
            else if(amount > accBal)
            {
                cout << "Debit amount exceeded account balance." << endl;
                return false;
            }
            else
            {
                accBal = accBal - amount; 
                return true;
            }
        } 
        // Function to return the balance.
        double getBal()
        {
            return this->accBal;
        }
};

// Derived class for saving accounts.
class SavingsAccount : public Account
{
    public:
        double intRate;
        // Default constructor.
        SavingsAccount()
        {
            intRate = 0.0;
        }
        // Parameterised constructor.
        SavingsAccount(int temp, double bal , double rate):Account(temp,bal)
        {
            if(rate >= 0.0)
            {
                intRate = rate;
            }
            else
            {
                cout << "The initial interest rate is invalid." << endl;
                intRate = 0.0;
            }
        }
        // Function to return the interest amount.
        double calculate_interest( )
        {
            return getBal()*(intRate/100);
        }
};

// Derived class for checking accounts.
class CheckingAccount : public Account
{
    public:
        double tranFee;
        // Default constructor.
        CheckingAccount()
        {
            tranFee = 0.0;
        }
        // Parameterised constructor.
        CheckingAccount(int temp, double bal, double fee):Account(temp,bal)
        {
            if(fee >= 0.0)
            {
                tranFee = fee;
            }
            else
            {
                cout << "The initial fee is invalid." << endl;
                tranFee = 0.0;
            }
        }
        // Function that credits amount into checking account by subtracting the fee amount.
        void credit(double amount)
        {
            if(amount <= 0)
            {
                cout << "The amount is invalid." << endl;
            }
            else if(getBal()-tranFee+amount < 0)
            {
                cout << "Charge fee exceeded account balance after credit." << endl;
                cout << "Please enter more money." << endl;
            }
            else
            {
                Account :: credit(amount);
                Account :: debit(tranFee);
            }
        }
        // Function that debits amount from checking account by subtracting the fee amount.
        void debit(double amount)
        {
            if(amount <= 0)
            {
                cout << "The amount is invalid." << endl;
            }
            else if((amount+tranFee) > getBal())
            {
                cout << "Debit amount along with the transaction fee exceeded account balance." << endl;
            }
            else
            {
                Account :: debit(amount);
                Account :: debit(tranFee);
            }
        }
};

// Boolean function to check whether the account number already exists in Savings account LL.
bool savSearch (SavingsLL *head, double x)
{
    SavingsLL* current = head;
    while (current != NULL) 
    { 
        if (current->value1 == x) 
            return true; 
        current = current->snext; 
    } 
    return false;
}

// Boolean function to check whether the account number already exists in Checking account LL.
bool checSearch (CheckingLL *head, double x)
{
    CheckingLL* current = head;
    while (current!=NULL)
    {
        if(current->value1 == x)
            return true;
        current = current->cnext;
    }
    return false;
}

// Main function.
int main()
{
    int choice,obj;
    double temp;
    CheckingAccount ch1;
    SavingsAccount sA1;
    SavingsLL *shead = NULL;
    CheckingLL *chead = NULL;
    SavingsLL *ptr1 = shead;
    CheckingLL *ptr2 = chead;
    
    while(1)
    {
        cout << "\n 1. Open Account (Savings or Checking Account) " << endl;
        cout << "\n 2. Credit in Savings or Checking Account/n" << endl;
        cout << "\n 3. Debit in Savings or Checking Account " << endl;
        cout << "\n 4. Change/Update Interest rate in Savings Account" << endl;
        cout << "\n 5. Calculate Interest in Savings Account and printing " << endl;
        cout << "\n 6. Calculate and Update Interest in Savings Account  " << endl;
        cout << "\n 7. Change/Update Fee Amount in Checking Account " << endl;
        cout << "\n 8. Print Checking Fee in Checking Account " << endl;
        cout << "\n 9. Transact and Update the balence in Checking Account " << endl;
        cout << "\n 10. Exit" << endl;
        cout << "\n Select Your Option :" << endl;
        
        cin >> choice;
        switch(choice)
        {
            case 1:
            {   
                A:
                cout << "Press 1 for savings Account and 2 for checking Account:" << endl;;
                cin >> obj;
                if(obj == 1)
                {
                    ptr1 = new SavingsLL( );
                    cout << "Please enter the Account number: " << endl;
                    cin >> temp;
                    if(savSearch(shead,temp)||checSearch(chead,temp))
                    {
                        cout << "Account number already exists. Please try again.\n" << endl;
                        break;
                    }
                    else
                    {
                        ptr1->value1 = temp;
                    }
                    cout << "Please enter the initial Balance: " << endl;
                    cin >> ptr1->value2;
                    cout << "Please enter the initial Interest Rate : " << endl;
                    cin >> ptr1->value3;
                    
                    if(shead == NULL)
                    {
                        shead = ptr1;
                        shead->snext = NULL;
                    }
                    else
                    {   
                        ptr1->snext = shead;
                        shead = ptr1;
                    }
                }
                else if(obj == 2)
                {
                    ptr2 = new CheckingLL( );
                    cout << "Please enter the Account number: " << endl;
                    cin >> temp;
                    if(checSearch(chead,temp)||savSearch(shead,temp))
                    {
                        cout << "Account number already exists. Please try again.\n" << endl;
                        break;
                    }
                    else
                    {
                        ptr2->value1 = temp;
                    }
                    cout << "Please enter the initial balance: " << endl;
                    cin >> ptr2->value2;
                    cout << "Please enter the initial Fee per transaction : " << endl;
                    cin >> ptr2->value3;
                    if(chead == NULL)
                    {
                        chead = ptr2;
                        chead->cnext = NULL;
                    }
                    else
                    {
                        ptr2->cnext = chead;
                        chead = ptr2;
                    }
                }
                else
                {
                    cout << "Please enter an valid option." << endl;
                    goto A;
                }
                break;
            }
            case 2:
            {
                B:
                cout << "Press 1 for crediting amount in savings Account and 2 for checking Account :" << endl;
                cin >> obj;
                if( obj == 1)
                {
                    cout << "Please enter the Account number: " << endl;
                    cin >> obj;
                    SavingsLL *pointer = shead;
                    if(savSearch(pointer,obj))
                    {
                        sA1 = SavingsAccount (pointer->value1,pointer->value2,pointer->value3);
                        cout << "The balance before the credit is " << sA1.getBal() << endl;
                        cout << "Please enter the amount to be credited: " << endl;
                        cin >> temp;
                        sA1.credit(temp);
                        pointer->value2 = sA1.accBal;
                        cout << "The balance after the credit is " << sA1.getBal() << endl;
                        break;
                    }
                    else
                    {
                        cout << "There is no account in savings Account" << endl;
                        break;
                    }
                }
                else if( obj == 2)
                {
                    cout << "Please enter the Account number: " << endl;
                    cin >> obj;
                    CheckingLL *pointer = chead;
                    
                    if(checSearch(pointer,obj))
                    {
                        ch1 = CheckingAccount (pointer->value1,pointer->value2,pointer->value3);
                        cout << "The balance before the credit is " << ch1.getBal() << endl;
                        cout << "Please enter the amount to be credited: " << endl;
                        cin >> temp;
                        ch1.Account::credit(temp);
                        pointer->value2 = ch1.accBal;
                        cout << "The balance after the credit is " << ch1.getBal() << endl;
                        break;
                    }
                    else
                    {
                        cout << "There is no account in checking Account" << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Please enter an valid option." << endl;
                    goto B;
                }
                break;
            }
            case 3:
            {
                C:
                cout << "Press 1 for debiting amount in savings Account and 2 for checking Account :" << endl;
                cin >> obj;
                if( obj == 1)
                {
                    cout << "Please enter the Account number: " << endl;
                    cin >> obj;
                    SavingsLL *pointer = shead;
                    if(savSearch(pointer,obj))
                    {
                        cout << "The balance before the debit is " << sA1.getBal() << endl;
                        cout << "Please enter the amount to be debited: " << endl;
                        cin >> temp;
                        sA1.debit(temp);
                        pointer->value2 = sA1.accBal;
                        cout << "The balance after the debit is " << sA1.getBal() << endl;
                        break;
                    }
                    else
                    {
                        cout << "There is no account in savings Account" << endl;
                        break;
                    }
                }
                else if( obj == 2)
                {
                    cout << "Please enter the Account number: " << endl;
                    cin >> obj;
                    CheckingLL *pointer = chead;
                    
                    if(checSearch(pointer,obj))
                    {
                        cout << "The balance before the debit is " << ch1.getBal() << endl;
                        cout << "Please enter the amount to be debited: " << endl;
                        cin >> temp;
                        ch1.Account::debit(temp);
                        pointer->value2 = ch1.accBal;
                        cout << "The balance after the debit is " << ch1.getBal() << endl;
                        break;
                    }
                    else
                    {
                        cout << "There is no account in checking Account" << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Please enter an valid option." << endl;
                    goto C;
                }
                break;
            }
            case 4:
            {
                cout << "Please enter the Account number: " << endl;
                cin >> obj;
                SavingsLL *pointer = shead;
                if(savSearch(pointer,obj))
                {
                    cout << "The existing interest rate is " << pointer->value3 << endl;
                    cout << "Please enter the new interest rate." << endl;
                    cin >> temp;
                    pointer->value3 = temp;
                    sA1 = SavingsAccount(pointer->value1,pointer->value2,pointer->value3);
                    break;
                }
                else
                {
                    cout << "There is no account in savings Account" << endl;
                    break;
                }
                break;
            }
            case 5:
            {
                cout << "Please enter the Account number: " << endl;
                cin >> obj;
                SavingsLL *pointer = shead;
                if(savSearch(pointer,obj))
                {
                    cout << "The total interest is " << sA1.calculate_interest() << endl;
                    break;
                }
                else
                {
                    cout << "There is no account in savings Account" << endl;
                    break;
                }
                break;
            }
            case 6:
            {
                cout << "Please enter the Account number: " << endl;
                cin >> obj;
                SavingsLL *pointer = shead;
                if(savSearch(pointer,obj))
                {
                    cout << "The balance before adding the interest is " << sA1.accBal << endl;
                    temp = sA1.calculate_interest();
                    sA1.credit(temp);
                    cout << "The balance after adding the interest is " << sA1.accBal << endl;
                    break;
                }
                else
                {
                    cout << "There is no account in savings Account" << endl;
                    break;
                }
                break;
            }
            case 7:
            {
                cout << "Please enter the Account number: " << endl;
                cin >> obj;
                CheckingLL *pointer = chead;
                if(checSearch(pointer,obj))
                {
                    cout << "The existing transaction fee is " << pointer->value3 << endl;
                    cout << "Please enter the new transaction fee." << endl;
                    cin >> temp;
                    pointer->value3 = temp;
                    ch1 = CheckingAccount(pointer->value1,pointer->value2,pointer->value3);
                    break;
                }
                else
                {
                    cout << "There is no account in savings Account" << endl;
                    break;
                }
                break;
            }
            case 8:
            {
                cout << "Please enter the Account number: " << endl;
                cin >> obj;
                CheckingLL *pointer = chead;
                if(checSearch(pointer,obj))
                {
                    cout << "The existing transaction fee is " << pointer->value3 << endl;
                    break;
                }
                else
                {
                    cout << "There is no account in savings Account" << endl;
                    break;
                }
                break;
            }
            case 9:
            {
                cout << "Please enter the Account number: " << endl;
                cin >> obj;
                CheckingLL *pointer = chead;
                if(checSearch(pointer,obj))
                {
                    cout << "The balance before the debit is " << ch1.getBal() << endl;
                    cout << "Please enter the amount to be debited: " << endl;
                    cin >> temp;
                    ch1.debit(temp);
                    pointer->value2 = ch1.accBal;
                    cout << "The balance after the debit along with the transaction fee is " << ch1.getBal() << endl;
                    break;
                }
                else
                {
                    cout << "There is no account in checking Account" << endl;
                    break;
                }
                break;
            }
            case 10:
            {
                exit(1);
            }
            default:
            {
                cout << "\n Enter a valid choice, try again!\n";
            }
        }
    }
    return 0;
}