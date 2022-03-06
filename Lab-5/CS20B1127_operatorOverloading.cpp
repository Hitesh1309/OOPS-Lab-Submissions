//CS20B1127
//Hitesh Gupta
//Program to merge two sorted linked lists.

#include <iostream>
using namespace std;

// Class for storing the data of the linked list.
class node
{
    public:
        int data;
        node *next;
};

// Class for creating linked list.
class linkedList
{
    private:
        node *head;
        //bool function to check whether the linked list is empty or not.
        bool isEmpty()
        {
            if(head == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
    public:
        //Constructor.
        linkedList()
        {
            head = NULL;
        }
        //Function which returns the head.
        node *header()
        {
            return head;
        }
        //Function to insert nodes in linked list.
        void insert(int num)
        {
            node *newNode = new node;
            
            newNode->data = num;
            newNode->next = NULL;
            
            node *current;
            
            if( isEmpty() || head->data >= newNode->data)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                current = head;
                while(current->next!=NULL && current->next->data < newNode->data)
                {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
        }
        
        //Function to display the linked list.
        void displayList()
        {   
            node* val = head;
            
            if( isEmpty() )
            {
                cout << "The linked list is empty." << endl;
            }
            while(val != NULL)
            {
                cout << val->data << " ";
                val = val->next;
            }
        }
        ~linkedList(){};
};

//Function to merge two linked lists in sorted way.
linkedList operator + (linkedList temp1, linkedList temp2)
{
    linkedList final;
    node *l1 = new node;
    node *l2 = new node;
    
    l1 = temp1.header();
    l2 = temp2.header();
    
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->data <= l2->data)
        {
            final.insert(l1->data);
            l1 = l1->next;
        }
        else 
        {
            final.insert(l2->data);
            l2 = l2->next;
        }
    }
    
    while(l1!=NULL)
    {
        final.insert(l1->data);
        l1=l1->next;
    }
    
    while(l2!=NULL)
    {
        final.insert(l2->data);
        l2=l2->next;
    }
    
    return final;
}

//Main Function.
int main()
{
    //Menu driven input.
    linkedList linkList1, linkList2, linkList3;
    
    int choice,num,value;
    
    while(1)
    {
        cout << "\n 1.Insert \n 2.Display \n 3.Merge the two linked lists \n 4.Exit \n";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                A:
                
                cout << " Enter the list number to enter data into(1 or 2) : ";
                cin >> num;
                
                if(num == 1)
                {
                    cout << " Enter the number : " ;
                    cin >> value;
                    linkList1.insert(value);
                    cout << "\n The number " << value << " is entered into list 1." << endl;
                }
                else if(num == 2)
                {
                    cout << " Enter the number : " ;
                    cin >> value;
                    linkList2.insert(value); 
                    cout << "\n The number " << value << " is entered into list 2." << endl;
                }
                else
                {
                    cout << " Enter an valid list number!!!";
                    goto A;
                }
                break;
            }
            case 2:
            {
                B:
                
                cout << "\n Enter the list number to display data(1 or 2) : ";
                cin >> num;
                
                if(num == 1)
                {
                    linkList1.displayList();
                }
                else if(num == 2)
                {
                    linkList2.displayList();
                }
                else
                {
                    cout << " Enter an valid list number!!!";
                    goto B;
                }
                break;
            }
            case 3:
            {
                linkedList linkList3 = linkList1 + linkList2;
                cout << " The merged linked list is : ";
                linkList3.displayList();
                cout << "\n";
                break;
            }
            case 4:
            {
                exit(1);
            }
            default:
                cout<<"\n Enter a valid choice, try again!\n";
        }
    }
    
    return 0;
}