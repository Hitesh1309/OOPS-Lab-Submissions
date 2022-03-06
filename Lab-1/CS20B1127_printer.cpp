//CS20B1127
//Hitesh Gupta
//Printer Menu Driven Program for Queue.

#include "CS20B1127_queue"
#include <iostream>

using namespace std;

int main()
{
    queue qu1;
    int choice, num;
    while(1)
    {
        cout << "\n 1.Add to Print Queue \n 2.Current Job \n 3.Execute a Job \n 4.Display Jobs \n 5.Exit";
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "\n Enter an integer Job ID: ";
                cin >> num;
                qu1.enqueue(num);
                if(qu1.isFull())
                {
                    break;
                }
                else
                {
                    cout << " The job ID added is " << num << endl;
                    break;
                }
            case 2:
                num = qu1.peek();
                if(num == -1)
                {  
                    cout << "\n No job ID's working currently" <<endl;
                }
                else
                {
                    cout << "\n The job ID that will be executed next is : " << num << endl;
                }
                break;
            case 3:
                num = qu1.dequeue();
                if(num == -1)
                {
                    cout << "\n No job ID's left to execute " << endl;
                }
                else
                {
                    cout << "\n The job ID " << num << " has been completed." << endl;
                }
                break;
            case 4:
                cout << "\n The jobs in the queue pool are :";
                qu1.display();
                cout << "\n";
                break;
            case 5:
                exit(1);
            default:
                cout<<"\n Enter a valid choice, try again!\n";
        }
    }
    return 1;
}
