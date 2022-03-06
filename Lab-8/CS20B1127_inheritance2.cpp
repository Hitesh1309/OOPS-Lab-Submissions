//CS20B1127
//Hitesh Gupta
//Program for Inheritance - Public, private and protected.

#include <iostream>
using namespace std;

// Employee class (base class).
class Employee
{
    protected:
        int employee_ID;
        string employee_name;
    public:
        // default constructor.
        Employee()
        {
            employee_ID = 0;
            employee_name = '\0';
        }
};

// Contract class (derived class) derived from the base class Employee.
class Contract : protected Employee
{
    protected:
        int pay_per_hour;
    public:
        // default constructor.
        Contract()
        {
            pay_per_hour = 0;
        }
        // function which updates the value of pay_per_hour.
        void setPay(int amount)
        {   
            pay_per_hour = amount;
        }
        // function which returns the value of pay_per_hour.
        int getPay()
        {
            return pay_per_hour;
        }
};

// Salaried class (derived class) derived from the base class Employee.
class Salaried : protected Employee
{
    protected:
        int monthlyPay;
    public:
        // default constructor. 
        Salaried()
        {
            monthlyPay = 0;
        }
        // function which updates the value of monthlyPay.
        void setPay(int amount)
        {
            monthlyPay = amount;
        }
        // function which returns the value of monthlyPay.
        int getPay()
        {
            return monthlyPay;
        }
};

// Manager class (derived class) derived from the derived class Salaried.
class Manager : private Salaried
{
    public:
        Manager(){}; // default constructor.
        int temp;
        Manager *next; // next pointer for the linked list of objects.
        // function which takes input of the details of the employee.
        void setDetails(int num)
        {
            employee_ID = num;
            cin.ignore(1024, '\n');
            cout << "Enter the name of the employee." << endl;
            getline(cin,employee_name);
            cout << "Enter the monthly pay of the employee." << endl;
            cin >> monthlyPay;
        }
        // function which prints the details of the employee.
        void getDetails()
        {
            cout << "ID of the employee : " << employee_ID << endl;
            cout << "Name of the employee : " << employee_name << endl;
            cout << "Monthly pay of the employee : " << monthlyPay << endl;
        }
        // function which calculates the salary of the employee.
        void calculateSalary()
        {
            int months;
            cout << "Enter the number of working months." << endl;
            cin >> months;
            cout << "The total salary is " << months*monthlyPay << endl;
        }
        // function which updates the salary of the employee.
        void setSalary()
        {
            cout << "Enter the updated salary." << endl;
            cin >> temp;
            setPay(temp);
        }
        // function which updates the ID or the name or the salary of the employee.
        void updateDetails()
        {
            int val;
            A:
            cout << "Press 1 to update Employee ID." << endl;
            cout << "Press 2 to update Employee name." << endl;
            cout << "Press 3 to update Employee salary." << endl;
            cin >> val;
            if(val == 1)
            {
                cout << "Enter the ID of the employee." << endl;
                cin >> employee_ID;
            }
            else if(val == 2)
            {
                cin.ignore(1024, '\n');
                cout << "Enter the name of the employee." << endl;
                getline(cin,employee_name);
            }
            else if(val == 3)
            {
                cout << "Enter the updated salary." << endl;
                cin >> temp;
                setPay(temp);
            }
            else
            {
                cout << "Please enter a valid option." << endl;
                goto A;
            }
            return;
        }
        // Function which returns the ID of the employee.
        int getID()
        {
            return employee_ID;
        }
};

// Intern class (derived class) derived from the derived class Contract.
class Intern : private Contract
{
    public:
        Intern(){}; // default constructor.
        int temp;
        Intern *next; // next pointer for the linked list.
        // function which takes the input of the details of the employee.
        void setDetails(int num)
        {
            employee_ID = num;
            cin.ignore(1024, '\n');
            cout << "Enter the name of the employee." << endl;
            getline(cin,employee_name);
            cout << "Enter the hourly pay of the employee." << endl;
            cin >> pay_per_hour;
        }
        // function which prints the details of the employee.
        void getDetails()
        {
            cout << "ID of the employee : " << employee_ID << endl;
            cout << "Name of the employee : " << employee_name << endl;
            cout << "Hourly pay of the employee : " << pay_per_hour << endl;
        }
        // function which calculates the salary of the employee.
        void calculateSalary()
        {
            int hours;
            cout << "Enter the number of working hours." << endl;
            cin >> hours;
            cout << "The total salary is " << hours*pay_per_hour << endl;
        }
        // function which updates the salary of the employee.
        void setSalary()
        {
            cout << "Enter the updated salary." << endl;
            cin >> temp;
            setPay(temp);
        }
        // function to update the ID or the name or the salary of the employee.
        void updateDetails()
        {
            int val;
            B:
            cout << "Press 1 to update Employee ID." << endl;
            cout << "Press 2 to update Employee name." << endl;
            cin >> val;
            if(val == 1)
            {
                cout << "Enter the ID of the employee." << endl;
                cin >> employee_ID;
            }
            else if(val == 2)
            {
                cin.ignore(1024, '\n');
                cout << "Enter the name of the employee." << endl;
                getline(cin,employee_name);
            }
            else if(val == 3)
            {
                cout << "Enter the updated salary." << endl;
                cin >> temp;
                setPay(temp);
            }
            else
            {
                cout << "Please enter a valid option." << endl;
                goto B;
            }
            return;
        }
        int getID()
        {
            return employee_ID;
        }
};

// Boolean Search function to search the Employee ID in Manager class.
bool manSearch (Manager *mhead, int x)
{
    Manager* mana = new Manager;
    mana = mhead;
    while(mana != NULL)
    {
        if(mana->getID() == x)
            return true;
        mana = mana->next;
    }
    return false;
}

// Boolean Search function to search the Employee ID in Intern class.
bool intSearch (Intern *ihead, int x)
{
    Intern* intern = new Intern;
    intern = ihead;
    while(intern != NULL)
    {
        if(intern->getID() == x)
            return true;
        intern = intern->next;
    }
    return false;
}

int main()
{
    int choice,num,k,val,mcount = 0,icount = 0;
    Manager *mhead = new Manager;
    Intern *ihead = new Intern;
    mhead = NULL;
    ihead = NULL;

    while(1)
    {
        cout << "\n 1. Create Employee (Manager or Intern). ";
        cout << "\n 2. Update Employee Details (Manager or Intern). ";
        cout << "\n 3. Print Employee Details (Manager or Intern). ";
        cout << "\n 4. Update Pay (Manger or Intern). ";
        cout << "\n 5. Calculate Salary (Manager or Intern). ";
        cout << "\n 6. Exit. " << endl;
        cout << "\n Select Your Option :" << endl;

        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                C:
                cout << "Press 1 for Manager and 2 for Intern." << endl;
                cin >> num;
                Manager *m1 = new Manager;
                Intern *i1 = new Intern;
                if(num == 1)
                {
                    cout << "Enter the ID of the employee: " << endl;
                    cin >> val;
                    if(manSearch(mhead,val) || intSearch(ihead,val))
                    {
                        cout << "Employee ID already exists. Please try again.\n" << endl;
                        goto C;
                    }
                    if(mhead == NULL)
                    {
                        m1->setDetails(val);
                        m1->next = NULL;
                        mhead = m1;
                        break;
                    }
                    else
                    {
                        m1 = mhead;
                        while(m1->next!=NULL)
                        {
                            m1 = m1->next;
                        }
                        Manager *m2 = new Manager;
                        m2->setDetails(val);
                        m2->next = NULL;
                        m1->next = m2;
                        break;
                    }
                }
                else if(num == 2)
                {
                    cout << "Enter the ID of the employee: " << endl;
                    cin >> val;
                    if(manSearch(mhead,val) || intSearch(ihead,val))
                    {
                        cout << "Employee ID already exists. Please try again." << endl;
                        goto C;
                    }
                    if(ihead == NULL)
                    {
                        i1->setDetails(val);
                        i1->next = NULL;
                        ihead = i1;
                        break;
                    }
                    else
                    {
                        i1 = ihead;
                        while(i1->next!=NULL)
                        {
                            i1 = i1->next;
                        }
                        Intern *i2 = new Intern;
                        i2->setDetails(val);
                        i2->next = NULL;
                        i1->next = i2;
                        break;
                    }
                }
                else
                {
                    cout << "Please enter an valid option!!!" << endl;
                    goto C;
                }
                break;
            }
            case 2:
            {
                D:
                cout << "Press 1 for Manager and 2 for Intern." << endl;
                cin >> num;
                Manager *m1 = new Manager;
                Intern *i1 = new Intern;
                m1 = mhead;
                i1 = ihead;
                if(num == 1)
                {
                    cout << "Enter the employee ID: " << endl;
                    cin >> val;
                    if(manSearch(mhead , val))
                    {
                        while(m1 != NULL)
                        {
                            if(m1->getID() == val)
                            {
                                cout << "The details of the employee are -" << endl;
                                m1->getDetails();
                                cout << "\n" << endl;
                                m1->updateDetails();
                                cout << "\nThe details after updating are -" << endl;
                                m1->getDetails();
                                cout << endl;
                                break;
                            }
                            else
                            {
                                m1 = m1->next;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << "No employee found with the given ID in this Job." << endl;
                        break;
                    }
                }
                else if(num == 2)
                {
                    cout << "Enter the employee ID: " << endl;
                    cin >> val;
                    if(intSearch(ihead , val))
                    {
                        while(i1 != NULL)
                        {
                            if(i1->getID() == val)
                            {
                                cout << "The details of the employee are -" << endl;
                                i1->getDetails();
                                cout << "\n" << endl;
                                i1->updateDetails();
                                cout << "\nThe details after updating are -" << endl;
                                i1->getDetails();
                                cout << endl;
                                break;
                            }
                            else
                            {
                                m1 = m1->next;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << "No employee found with the given ID in this Job." << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Please enter an valid option!!!" << endl;
                    goto D;
                }
                break;
            }
            case 3:
            {
                E:
                cout << "Press 1 for Manager and 2 for Intern." << endl;
                cin >> num;
                Manager *m1 = new Manager;
                Intern *i1 = new Intern;
                m1 = mhead;
                i1 = ihead;
                if(num == 1)
                {
                    cout << "Enter the employee ID: " << endl;
                    cin >> val;
                    if(manSearch(mhead , val))
                    {
                        while(m1 != NULL)
                        {
                            if(m1->getID() == val)
                            {
                                cout << "The details of the employee are -" << endl;
                                m1->getDetails();
                                break;
                            }
                            else
                            {
                                m1 = m1->next;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << "No employee found with the given ID in this Job." << endl;
                        break;
                    }
                }
                else if(num == 2)
                {
                    cout << "Enter the employee ID: " << endl;
                    cin >> val;
                    if(intSearch(ihead , val))
                    {
                        while(i1 != NULL)
                        {
                            if(i1->getID() == val)
                            {
                                cout << "The details of the employee are -" << endl;
                                i1->getDetails();
                                break;
                            }
                            else
                            {
                                i1 = i1->next;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << "No employee found with the given ID in this Job." << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Please enter an valid option!!!" << endl;
                    goto E;
                }
                break;
            }
            case 4:
            {
                F:
                cout << "Press 1 for Manager and 2 for Intern." << endl;
                cin >> num;
                Manager *m1 = new Manager;
                Intern *i1 = new Intern;
                m1 = mhead;
                i1 = ihead;
                if(num == 1)
                {
                    cout << "Enter the employee ID: " << endl;
                    cin >> val;
                    if(manSearch(mhead , val))
                    {
                        while(m1 != NULL)
                        {
                            if(m1->getID() == val)
                            {
                                m1->setSalary();
                                cout << "\nThe details of the employee after updating is -" << endl;
                                m1->getDetails();
                                break;
                            }
                            else
                            {
                                m1 = m1->next;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << "No employee found with the given ID in this Job." << endl;
                        break;
                    }
                }
                else if(num == 2)
                {
                    cout << "Enter the employee ID: " << endl;
                    cin >> val;
                    if(intSearch(ihead , val))
                    {
                        while(i1 != NULL)
                        {
                            if(i1->getID() == val)
                            {
                                i1->setSalary();
                                cout << "\nThe details of the employee after updating is -" << endl;
                                i1->getDetails();
                                break;
                            }
                            else
                            {
                                i1 = i1->next;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << "No employee found with the given ID in this Job." << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Please enter an valid option!!!" << endl;
                    goto E;
                }
                break;
            }
            case 5:
            {
                G:
                cout << "Press 1 for Manager and 2 for Intern." << endl;
                cin >> num;
                Manager *m1 = new Manager;
                Intern *i1 = new Intern;
                m1 = mhead;
                i1 = ihead;
                if(num == 1)
                {
                    cout << "Enter the employee ID: " << endl;
                    cin >> val;
                    if(manSearch(mhead , val))
                    {
                        while(m1 != NULL)
                        {
                            if(m1->getID() == val)
                            {
                                m1->calculateSalary();
                                break;
                            }
                            else
                            {
                                m1 = m1->next;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << "No employee found with the given ID in this Job." << endl;
                        break;
                    }
                }
                else if(num == 2)
                {
                    cout << "Enter the employee ID: " << endl;
                    cin >> val;
                    if(intSearch(ihead , val))
                    {
                        while(i1 != NULL)
                        {
                            if(i1->getID() == val)
                            {
                                i1->calculateSalary();
                                break;
                            }
                            else
                            {
                                i1 = i1->next;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << "No employee found with the given ID in this Job." << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Please enter an valid option!!!" << endl;
                    goto E;
                }
                break;
            }
            case 6:
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