// CS20B1127
// Hitesh Gupta
// Lab-10
// Program for Selection sort using templates in C++ .

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;


template <typename T> // template for function.
// function to swap variables.
void swap(T &temp1, T &temp2) 
{
    T temp = temp1;
    temp1 = temp2;
    temp2 = temp;
}

template <typename T> // template for function.
// function to implement selection sort.
void selectionSort(T arr[], int n) 
{
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
}

template <typename T> // template for function.
// function to print the sorted array.
void PrintArray(T arr[], int n)
{
    int i;
    for (i = 0; i < n-1; ++i)
    {
        cout << arr[i] << ", ";
    }
    if(i == n-1)
    {
        cout << arr[i] << ". ";
    }
}
  
// Driver Code
int main() 
{
    int choice,choice1,n;

    while(1)
    {
        A:
        cout << "\nEnter the data type ( Enter the corresponding number ) : " << endl;
        cout << " 1. Int. " << endl;
        cout << " 2. Float. " << endl;
        cout << " 3. Char. " << endl;
        cout << " 4. Exit. \n" << endl;

        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                B:
                cout << "Enter the size of the array: ";
                cin >> n;
                // exception handling (catching if the array size is less than or equal to 0)
                try
                {
                    if(n<=0)
                    {
                        throw n;
                    }
                }
                catch (int x)
                {
                    cout << "Error!!! Please enter a positive value." << endl;
                    goto B;
                }
                int arr[n] = {0}; // initialising the array with 0 so that the array doesnt gets stored with garbage value.

                while(1)
                {
                    cout << "\n\n       1. Get Value. " << endl;
                    cout << "       2. Sort. " << endl;
                    cout << "       3. Display. " << endl;
                    cout << "       4. Select another data type. " << endl;
                    cout << "       5. Exit. \n" << endl;

                    cin >> choice1;

                    switch(choice1)
                    {
                        case 1:
                        {
                            for(int i = 0; i < n ; i++)
                            {
                                cout << "Enter element " << i+1 << " : " ;
                                cin >> arr[i];
                            }
                            cout << "The Input array is :-  " ;
                            PrintArray <int> (arr, n);
                            break;
                        }
                        case 2:
                        {
                            cout << "Implementing Selection Sort..." << endl;
                            selectionSort <int> (arr, n);

                            cout << "The Sorted array is :-  " ;
                            PrintArray <int> (arr, n);
                            break;
                        }
                        case 3:
                        {
                            cout << "The array is :- ";
                            PrintArray <int> (arr, n);
                            break;
                        }
                        case 4:
                        {
                            goto A;
                            break;
                        }
                        case 5:
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
                C:
                cout << "Enter the size of the array: ";
                cin >> n;
                // exception handling (catching if the array size is less than or equal to 0)
                try
                {
                    if(n<=0)
                    {
                        throw n;
                    }
                }
                catch (int x)
                {
                    cout << "Error!!! Please enter a positive value." << endl;
                    goto C;
                }
                float arr[n] = {0.0}; // initialising the array with 0 so that the array doesnt get stored with garbage value.

                while(1)
                {
                    cout << "\n\n       1. Get Value. " << endl;
                    cout << "       2. Sort. " << endl;
                    cout << "       3. Display. " << endl;
                    cout << "       4. Select another data type. " << endl;
                    cout << "       5. Exit. \n" << endl;

                    cin >> choice1;

                    switch(choice1)
                    {
                        case 1:
                        {
                            for(int i = 0; i < n ; i++)
                            {
                                cout << "Enter element " << i+1 << " : " ;
                                cin >> arr[i];
                            }
                            cout << "The Input array is :-  " ;
                            PrintArray <float> (arr, n);
                            break;
                        }
                        case 2:
                        {
                            cout << "Implementing Selection Sort..." << endl;
                            selectionSort <float> (arr, n);

                            cout << "The Sorted array is :-  " ;
                            PrintArray <float> (arr, n);
                            break;
                        }
                        case 3:
                        {
                            cout << "The array is :- ";
                            PrintArray <float> (arr, n);
                            break;
                        }
                        case 4:
                        {
                            goto A;
                            break;
                        }
                        case 5:
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
                D:
                cout << "Enter the size of the array: ";
                cin >> n;
                // exception handling (catching if the array size is less than or equal to 0)
                try
                {
                    if(n<=0)
                    {
                        throw n;
                    }
                }
                catch (int x)
                {
                    cout << "Error!!! Please enter a positive value." << endl;
                    goto D;
                }
                char arr[n] = {'\0'}; // initialising the array with null string,
                                      // so that the array doesnt get stored with garbage value.

                while(1)
                {
                    cout << "\n\n       1. Get Value. " << endl;
                    cout << "       2. Sort. " << endl;
                    cout << "       3. Display. " << endl;
                    cout << "       4. Select another data type. " << endl;
                    cout << "       5. Exit. \n" << endl;

                    cin >> choice1;

                    switch(choice1)
                    {
                        case 1:
                        {
                            for(int i = 0; i < n ; i++)
                            {
                                cout << "Enter element " << i+1 << " : " ;
                                cin >> arr[i];
                            }
                            cout << "The Input array is :-  " ;
                            PrintArray <char> (arr, n);
                            break;
                        }
                        case 2:
                        {
                            cout << "Implementing Selection Sort..." << endl;
                            selectionSort <char> (arr, n);

                            cout << "The Sorted array is :-  " ;
                            PrintArray <char> (arr, n);
                            break;
                        }
                        case 3:
                        {
                            cout << "The array is :- ";
                            PrintArray <char> (arr, n);
                            break;
                        }
                        case 4:
                        {
                            goto A;
                            break;
                        }
                        case 5:
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
}