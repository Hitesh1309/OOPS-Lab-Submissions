// CS20B1127
// Hitesh Gupta
// Lab-9
// Program for Virtual class and templates (TA) (9.1).

#include<iostream>
#include<sstream>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::stringstream; // used for changing int type to string type

template <typename T> // template for roll number.
class Person // class for person.
{
    protected: // data members.
        T roll_num;
        string name;
    public:
        Person() // default constructor.
        {
            roll_num = '\0';
        } 

        Person(string temp, T temp1) // parameterised constructor.
        {
            this->name = temp;
            this->roll_num = temp1;
        }

        void display() // function to display the details of the person.
        {
            cout << "The name of the person is : " << name << endl;
            cout << "The roll number of the person is : " << roll_num << endl;
        }
};

// Derived class for student from base class person in protected mode.
class Student : protected Person<string> 
{
    protected: // data members.
        string course1;
        string course2;
        string course3;
    public:
        Student(){} // default constructor.

        // parameterised constructor.
        Student(string temp, string temp1, string temp2, string temp3, string temp4 ) : Person<string>(temp, temp1)
        {
            this->course1 = temp2;
            this->course2 = temp3;
            this->course3 = temp4;
        }

        void display() // function to display the details of the student.
        {
            Person<string>::display();
            cout << "The first course of the student is : " << this->course1 << endl;
            cout << "The second course of the student is : " << this->course2 << endl;
            cout << "The third course of the student is : " << this->course3 << endl;
        }

        ~Student(){} // Destructor.
};

// Derived class for research student from base class person in protected mode.
class Research_Student : protected Person<int>
{
    protected: // data members.
        string course1;
        string research_area;
    public:
        Research_Student(){} // default constructor.

        // parameterised constructor.
        Research_Student(string temp, int temp1, string temp2, string temp3) : Person<int>(temp,temp1)
        {
            this->course1 = temp2;
            this->research_area = temp3;
        }

        void display() // function to display the details of the research student.
        {
            Person<int>::display();
            cout << "The first course of the research student is : " << course1 << endl;
            cout << "The research area of the research student is : " << research_area << endl;
        }

        ~Research_Student(){} // Destructor.
};

// Derived class for TA from two derived classes student and research student in protected mode.
class TA : virtual protected Student , virtual protected Research_Student 
{
    protected: // data members.
        string course_assigned;
        string role;
    public:
        TA *next; // pointer for linked list of TA's.
        TA(){} // default constructor.

        // parameterised constructor for student as a TA.
        TA(string temp, string temp1, string temp2, string temp3, string temp4, string temp5) 
            : Student(temp, temp1, temp2, temp3, temp4)
                {
                    this->course_assigned = temp5;
                    this->role = "Student";
                }

        // parameterised constructor for research student as a TA.
        TA(string temp, int temp1, string temp2, string temp3, string temp4)
            : Research_Student(temp, temp1, temp2, temp3)
                {
                    this->course_assigned = temp4;
                    this->role = "Research Student";
                }

        void display() // display function to display the details of the TA.
        {
            int num;
            Y:
                cout << "\n     1. Person. ";
                cout << "\n     2. Student. ";
                cout << "\n     3. Research Student. ";
                cout << "\n     4. Teaching Assistant. " << endl;
                cin >> num;
                
            if(getResStuRollNum() != 0 && getStuRoll() != "")
            {
                if(num == 1)
                {
                    Person<int>::display();
                }
                else if(num == 2)
                {
                    cout << "ERROR!!! The given roll number is of a research student." << endl;
                }
                else if(num == 3)
                {
                    Research_Student::display();
                }
                else if(num == 4)
                {
                    Person<int>::display();
                    cout << "The course assigned to the TA is : " << course_assigned << endl;
                    cout << "The role of the TA is : " << role << endl;
                }
                else
                {
                    cout << "Enter a valid option." << endl;
                    goto Y;
                }
            }
            if(getResStuRollNum() == 0 && getStuRoll() != "")
            {
                if(num == 1)
                {
                    Person<string>::display();
                }
                else if(num == 2)
                {
                    Student::display();
                }
                else if(num == 3)
                {
                    cout << "ERROR!!! The given roll number is of a student." << endl;
                }
                else if(num == 4)
                {
                    Person<string>::display();
                    cout << "The course assigned to the TA is : " << course_assigned << endl;
                    cout << "The role of the TA is : " << role << endl;
                }
                else
                {
                    cout << "Enter a valid option." << endl;
                    goto Y;
                }
            }
        }

        string getStuRoll() // function which returns the roll number of student(if he/she is a TA).
        {
            return Student::roll_num;
        }

        string getResStuRoll() // function which returns the roll number of the research student(if he/she is a TA).
        {
            int temp = Research_Student::roll_num;
            stringstream ss;
            ss << temp;
            string str = ss.str();
            return str;
        }

        int getResStuRollNum()
        {
            return Research_Student::roll_num;
        }
};

// Function to check if a given roll number is present in the linked list of student as a TA.
bool stuSearch(TA *t1head, string x)
{
    TA *stu = new TA;
    stu = t1head;
    while(stu != NULL)
    {
        if(stu->getStuRoll() == x || stu->getResStuRoll() == x)
        {
            return true;
        }
        stu = stu->next;
    } 
    return false;
}

// main function where the menu is written.
int main()
{
    TA *t1head = new TA;
    t1head = NULL;
    
    int choice,num,value;
    string val,val1,val2,val3,val4,val5;
    
    A:
    while(1)
    {
        cout << "\n 1. Set TA details. " ;
        cout << "\n 2. Display : " ;
        cout << "\n     (a) Person." ;
        cout << "\n     (b) Student." ;
        cout << "\n     (c) Research Student." ;
        cout << "\n     (d) Teaching Assistant." ;
        cout << "\n 3. Exit. " << endl;
        cout << "\n Select Your Option (1 or 2 or 3) :" << endl;

        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                B:

                cout << " Press 1 if the TA is a student or Press 2 if the TA is a research student. " << endl;
                cin >> num;
                if(num == 1)
                {
                    TA *t1 = new TA;
                    cin.ignore(1024, '\n');
                    cout << " Enter the name : " ;
                    getline(cin,val);
                    cout << " Enter the roll number : ";
                    getline(cin,val1);
                    cout << " Enter the first course : ";
                    getline(cin,val2);
                    cout << " Enter the second course : ";
                    getline(cin,val3);
                    cout << " Enter the third course : ";
                    getline(cin,val4);
                    cout << " Enter the course assigned : ";
                    getline(cin,val5);

                    if(val5 == val4 || val5 == val3 || val5 == val2)
                    {
                        cout << "\n ERROR!!! " ;
                        cout << "The course assigned cannot be the same as previous courses. ";
                        C:
                        cout << "Please 1 to Try Again and Press 2 to go to Main menu.\n" << endl;
                        cin >> num;
                        if(num == 1)
                        {
                            goto B;
                        }
                        else if(num == 2)
                        {
                            goto A;
                        }
                        else
                        {
                            cout << "Enter a valid option." << endl;
                            goto C;
                        } 
                    }

                    if(stuSearch(t1head,val1))
                    {
                        cout << "\n ERROR!!! Roll number already exists. " << endl;
                        D:
                        cout << "Please 1 to Try Again and Press 2 to go to Main menu.\n" << endl;
                        cin >> num;
                        if(num == 1)
                        {
                            goto B;
                        }
                        else if(num == 2)
                        {
                            goto A;
                        }
                        else
                        {
                            cout << "Enter a valid option." << endl;
                            goto D;
                        } 
                    }

                    TA t(val,val1,val2,val3,val4,val5);

                    if(t1head == NULL)
                    {
                        *t1 = t;
                        t1->next = NULL;
                        t1head = t1;
                        break;
                    }
                    else
                    {
                        t1 = t1head;
                        while(t1->next != NULL)
                        {
                            t1 = t1->next;
                        }
                        TA *t2 = new TA;
                        *t2 = t;
                        t2->next = NULL;
                        t1->next = t2;
                        break;
                    }
                    break;
                }
                else if(num == 2)
                {
                    TA *t3 = new TA;
                    cin.ignore(1024,'\n');
                    cout << " Enter the name : " ;
                    getline(cin,val);
                    cout << " Enter the roll number : ";
                    cin >> value;
                    cin.ignore(1024,'\n');
                    cout << " Enter the first course : ";
                    getline(cin,val2);
                    cout << " Enter the research area : ";
                    getline(cin,val3);
                    cout << " Enter the course assigned : ";
                    getline(cin,val4);

                    if(val4 == val2)
                    {
                        cout << "\n ERROR!!! " ;
                        cout << "The course assigned cannot be the same as previous courses. ";
                        E:
                        cout << "Please 1 to Try Again and Press 2 to go to Main menu.\n" << endl;
                        cin >> num;
                        if(num == 1)
                        {
                            goto B;
                        }
                        else if(num == 2)
                        {
                            goto A;
                        }
                        else
                        {
                            cout << "Enter a valid option." << endl;
                            goto E;
                        } 
                    }

                    stringstream ss;
                    ss << value;
                    string str = ss.str();

                    if(stuSearch(t1head,str))
                    {
                        cout << "\n ERROR!!! Roll number already exists. " << endl;
                        F:
                        cout << "Please 1 to Try Again and Press 2 to go to Main menu.\n" << endl;
                        cin >> num;
                        if(num == 1)
                        {
                            goto B;
                        }
                        else if(num == 2)
                        {
                            goto A;
                        }
                        else
                        {
                            cout << "Enter a valid option." << endl;
                            goto F;
                        } 
                    }

                    TA t(val,value,val2,val3,val4);

                    if(t1head == NULL)
                    {
                        *t3 = t;
                        t3->next = NULL;
                        t1head = t3;
                    }
                    else
                    {
                        t3 = t1head;
                        while(t3->next != NULL)
                        {
                            t3 = t3->next;
                        }
                        TA *t4 = new TA;
                        *t4 = t;
                        t4->next = NULL;
                        t3->next = t4;
                        break;
                    }
                    break;
                }
                else 
                {
                    cout << "Please enter an valid option. Try again." << endl;
                    goto B;
                }
                break;
            }
            case 2:
            {
                cout << " Enter the roll number of the person : " ;
                cin.ignore(1024,'\n');
                getline(cin,val);
                TA *t1 = new TA;
                t1 = t1head;

                if(stuSearch(t1head,val))
                {
                    while(t1 != NULL)
                    {
                        if(t1->getStuRoll() == val || t1->getResStuRoll() == val)
                        {
                            t1->display();
                            break;
                        }
                        else 
                        {
                            t1 = t1->next;
                        }
                    }
                }
                else 
                {
                    cout << "\n No person found with this roll number." << endl;
                    break;
                }
                break;
            }
            case 3:
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