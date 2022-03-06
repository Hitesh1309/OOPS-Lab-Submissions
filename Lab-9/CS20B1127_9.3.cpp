// CS20B1127
// Hitesh Gupta
// Lab-9
// Program for Stack implementation using templates in C++ (9.3).

#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::string;
using std::endl;

template<class T> // template for class.
// class for stack.
class stack
{
    private: // data members
        T *a;
        int top,i,size;

    public:
        // parameterised constructor.
        stack(int value)
        {
            a = new T[value];
            size = value;
            top = -1;
        }
        // push function to insert elements.                
        void push(T num)
        {
            if(isFull())
            {
                cout << "The Stack is Full." << endl;
            }
            else
            {
                cout << "Inserted Element is " << num << endl;
                a[top++] = num;
            }
        }
        // pop function to delete element from the top.    
        void pop()     
        {
            if(isEmpty())
            {
                cout << "The Stack is Empty." << endl;
            }
            else
            {
                T x = a[--top];
                cout << "Popped Element is " << x << endl;
            }
        }
        // peek function to display the topmost element in the stack.
        void peek()
        {
            if(isEmpty())
            {
                cout << "The Stack is Empty." << endl;
            }
            else
            {
                T y = a[top-1];
                cout << "The Top Element is " << y << endl;
            }
        }
        // boolean function to check whether the stack is full or not.
        bool isFull()
        {
            if (top == (size - 1))
            {
                return true;
            }
            else
            {
                return false;
            }
        }   
        // boolean function to check whether the stack is empty or not.
        bool isEmpty()
        {
            if (top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        // print function to print all the elements in the stack.
        void print()
        {
            if(isEmpty())
            {
                cout << "The Stack is Empty." << endl;
            }
            else
            {
                for(i = -1; i < top; i++)
                {
                    cout << " " << a[i];
                }                                
                cout << "\n";
            }
        }
};

// main to function to implement menu.             
int main()
{   
    int i,choice,n,choice1,value;
    float fvalue;
    char cvalue;
    A:
    while(1)
    {
        cout << "\n 1. Stack of Integers. ";
        cout << "\n 2. Stack of Floats. ";
        cout << "\n 3. Stack of Characters. ";
        cout << "\n 4. Exit." << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "Enter the Size of the Stack : " ;
                cin >> n;
                stack <int> st1(n); 
                while(1)
                {
                    cout << "\n     1. Push into Stack.";
                    cout << "\n     2. Pop out of Stack.";
                    cout << "\n     3. Peek into the Stack.";
                    cout << "\n     4. Print all the Elements in the Stack.";
                    cout << "\n     5. Enter another Stack.";
                    cout << "\n     6. Exit." << endl;
                    cin >> choice1;
                    switch(choice1)
                    {
                        case 1:
                        {
                            cout << "Enter the Number : " ;
                            cin >> value;
                            st1.push(value);
                            break;
                        }
                        case 2:
                        {
                            st1.pop();
                            break;
                        }
                        case 3:
                        {
                            st1.peek();
                            break;
                        }
                        case 4:
                        {
                            st1.print();
                            break;
                        }
                        case 5:
                        {
                            goto A;
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
                break;
            }
            case 2:
            {
                cout << "Enter the Size of the Stack : " ;
                cin >> n;
                stack <float> st2(n); 
                while(1)
                {
                    cout << "\n     1. Push into Stack.";
                    cout << "\n     2. Pop out of Stack.";
                    cout << "\n     3. Peek into the Stack.";
                    cout << "\n     4. Print all the Elements in the Stack.";
                    cout << "\n     5. Enter another Stack.";
                    cout << "\n     6. Exit." << endl;
                    cin >> choice1;
                    switch(choice1)
                    {
                        case 1:
                        {
                            cout << "Enter the Number : " ;
                            cin >> fvalue;
                            st2.push(fvalue);
                            break;
                        }
                        case 2:
                        {
                            st2.pop();
                            break;
                        }
                        case 3:
                        {
                            st2.peek();
                            break;
                        }
                        case 4:
                        {
                            st2.print();
                            break;
                        }
                        case 5:
                        {
                            goto A;
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
                break;
            }
            case 3:
            {
                cout << "Enter the Size of the Stack : " ;
                cin >> n;
                stack <char> st3(n); 
                while(1)
                {
                    cout << "\n     1. Push into Stack.";
                    cout << "\n     2. Pop out of Stack.";
                    cout << "\n     3. Peek into the Stack.";
                    cout << "\n     4. Print all the Elements in the Stack.";
                    cout << "\n     5. Enter another Stack.";
                    cout << "\n     6. Exit." << endl;
                    cin >> choice1;
                    switch(choice1)
                    {
                        case 1:
                        {
                            cout << "Enter the Number : " ;
                            cin >> cvalue;
                            st3.push(cvalue);
                            break;
                        }
                        case 2:
                        {
                            st3.pop();
                            break;
                        }
                        case 3:
                        {
                            st3.peek();
                            break;
                        }
                        case 4:
                        {
                            st3.print();
                            break;
                        }
                        case 5:
                        {
                            goto A;
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
                break;
            }
            case 4:
            {
                exit(1);
            }
            default:
            {
                cout << "\n Enter a valid choice, try again!\n";
            }
        }
    }
    
    return(0);
}