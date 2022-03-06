// CS20B1127
// Hitesh Gupta
// Lab-9
// Program for Bubble sort using templates in C++ (9.2).

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::swap;

template <typename T> // template for function.
// function to implement bubble sort.
void bubbleSort(T arr[], int n) 
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = n-1; i < j; j--)
        {
            if (arr[j] < arr[j-1])
            {
                swap(arr[j], arr[j-1]);
            }
        }
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
    cout << "\n" << endl;
}
  
// Driver Code
int main() 
{
    int choice,n;

    while(1)
    {
        cout << "\n 1. Sort an array of integers. ";
        cout << "\n 2. Sort an array of double number type. ";
        cout << "\n 3. Sort an array of float number type. ";
        cout << "\n 4. Sort an array of characters. ";
        cout << "\n 5. Sort an array of strings. ";
        cout << "\n 6. Exit." << endl;

        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                A:
                cout << "Enter the size of the array: " << endl;
                cin >> n;
                if(n<=0)
                {
                    cout << "Error!!! Please enter a positive value." << endl;
                    goto A;
                }
                int arr[n];

                for(int i = 0; i < n ; i++)
                {
                    cout << "Enter element " << i+1 << " : " ;
                    cin >> arr[i];
                }

                cout << "\nThe Input array is :-  " ;
                PrintArray <int> (arr, n);

                cout << "Implementing Bubble Sort..." << endl;
                bubbleSort <int> (arr, n);

                cout << "\nThe Sorted array is :-  " ;
                PrintArray <int> (arr, n);
                break;
            }
            case 2:
            {
                B:
                cout << "Enter the size of the array: " << endl;
                cin >> n;
                if(n<=0)
                {
                    cout << "Error!!! Please enter a positive value." << endl;
                    goto B;
                }
                double arr[n];

                for(int i = 0; i < n ; i++)
                {
                    cout << "Enter element " << i+1 << " : " ;
                    cin >> arr[i];
                }
                
                cout << "\nThe Input array is :-  " ;
                PrintArray <double> (arr, n);

                cout << "Implementing Bubble Sort..." << endl;
                bubbleSort <double> (arr, n);

                cout << "\nThe Sorted array is :-  " ;
                PrintArray <double> (arr, n);
                break;
            }
            case 3:
            {
                C:
                cout << "Enter the size of the array: " << endl;
                cin >> n;
                if(n<=0)
                {
                    cout << "Error!!! Please enter a positive value." << endl;
                    goto C;
                }
                float arr[n];

                for(int i = 0; i < n ; i++)
                {
                    cout << "Enter element " << i+1 << " : " ;
                    cin >> arr[i];
                }
                
                cout << "\nThe Input array is :-  " ;
                PrintArray <float> (arr, n);

                cout << "Implementing Bubble Sort..." << endl;
                bubbleSort <float> (arr, n);

                cout << "\nThe Sorted array is :-  " ;
                PrintArray <float> (arr, n);
                break;
            }
            case 4:
            {
                D:
                cout << "Enter the size of the array: " << endl;
                cin >> n;
                if(n<=0)
                {
                    cout << "Error!!! Please enter a positive value." << endl;
                    goto D;
                }
                char arr[n];

                for(int i = 0; i < n ; i++)
                {
                    cout << "Enter element " << i+1 << " : " ;
                    cin >> arr[i];
                }
                
                cout << "\nThe Input array is :-  " ;
                PrintArray <char> (arr, n);

                cout << "Implementing Bubble Sort..." << endl;
                bubbleSort <char> (arr, n);

                cout << "\nThe Sorted array is :-  " ;
                PrintArray <char> (arr, n);
                break;
            }
            case 5:
            {
                E:
                cout << "Enter the size of the array: " << endl;
                cin >> n;
                if(n<=0)
                {
                    cout << "Error!!! Please enter a positive value." << endl;
                    goto E;
                }
                string arr[n];
                cin.ignore(1024, '\n');
                for(int i = 0; i < n ; i++)
                {
                    cout << "Enter element " << i+1 << " : " ;
                    getline(cin,arr[i]);
                }
                
                cout << "\nThe Input array is :-  " ;
                PrintArray <string> (arr, n);

                cout << "Implementing Bubble Sort..." << endl;
                bubbleSort <string> (arr, n);

                cout << "\nThe Sorted array is :-  " ;
                PrintArray <string> (arr, n);
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