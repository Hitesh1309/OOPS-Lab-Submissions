//CS20B1127
//Hitesh Gupta
//Program for function overloading.
//Note:- The positions for the linked list start from 0 then 1,2 and so on.

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
        //Overloaded insert function to insert at the end.
        void insert(int data)
        {
        	node *temp = new node();
        	temp->data = data;
        	if ( isEmpty() )
        	{
        		head = temp;
        	}
        	else
        	{
        		node *ptr = head;
        		while (ptr->next != NULL)
        		{
        			ptr = ptr->next;
        		}
        		ptr->next = temp;
        	}
        }
        //Overloaded insert function to insert at a specific position.
        void insert(int data, int pos)
        {
        	node *temp = new node();

        	if (pos == 0)
        	{
        		temp->data = data;
                temp->next = head;
        		head = temp;
                cout << "The number " << data << " is inserted at position 0." << endl;
        	}
        	else
        	{
        		node *ptr = head;
        		while(pos > 1) 
        		{
                    if(ptr == NULL || ptr->next == NULL)
                    {
                        cout << "Error!!!" << endl;
                        return;
                    }
                    ptr = ptr->next;
        			--pos;
        		}
                cout << "The number " << data << " is inserted at position " << pos << "." << endl;
                temp->data = data;
        		temp->next = ptr->next;
        		ptr->next = temp;
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
        //Overloaded delete function to delete at the end.
        void deleteNum()
        {
        	if ( isEmpty() )
        	{
        		cout<<"List is Empty"<<endl;
        	}
        	else if (head->next == NULL)
        	{
        		cout<<"Element Deleted: "<<head->data<<endl;
        		delete(head);
        		head = NULL;
        	}
        	else
        	{
        		node *temp = head;
        		while (temp->next->next != NULL) 
        		{
        			temp = temp->next;
        		}
        		cout<<"Element Deleted: "<<temp->next->data<<endl;
        		delete(temp->next);
        		temp->next = NULL;
        	}					
        }
        //Overloaded delete function to delete at a specific position.
        void deleteNum(int pos)
        {
        	if ( isEmpty() )
        	{
        		cout<<"List is Empty"<<endl;
        	}
        	else
        	{
        		node *temp, *ptr;
        		if (pos == 0) 
        		{
        			cout<<"Element Deleted: "<<head->data<<endl;
        			ptr = head;
        			head = head->next;
        			delete(ptr);
        		}
        		else
        		{
        			temp = ptr = head;
        			while(pos>0)
        			{
                        if(ptr == NULL || ptr->next == NULL)
                        {
                            cout << "Error!!!" << endl;
                            return;
                        }
                        --pos;
        				temp = ptr;
        				ptr = ptr->next;
        			}
        			cout<<"Element Deleted: "<<ptr->data<<endl;
        			temp->next = ptr->next;
        			free(ptr);
        		}
        	}
        }
        
    ~linkedList(){}; //Destructor.
};

//Main Function.
int main()
{
    //Menu driven input.
    linkedList linkList1;
    
    int choice,posi,value;
    
    while(1)
    {
        cout << "\n 1.Insert at the end";
        cout << "\n 2.Insert at any position";
        cout << "\n 3.Delete at the end";
        cout << "\n 4.Delete at any position";
        cout << "\n 5.Display";
        cout << "\n 6.Exit" << endl ;

        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << " Enter the number : " ;
                cin >> value;
                linkList1.insert(value);
                cout << "The number " << value << " is inserted." << endl;
                break;
            }
            case 2:
            {
                cout << " Enter the position to be inserted : " ;
                cin >> posi;
                cout << " Enter the number : " ;
                cin >> value;
                linkList1.insert(value,posi);
                break;
            }
            case 3:
            {
                linkList1.deleteNum();
                break;
            }
            case 4:
            {
                cout << " Enter the position to be deleted : " ;
                cin >> posi;
                linkList1.deleteNum(posi);
                break;
            }
            case 5:
            {
                linkList1.displayList();
                break;
            }
            case 6:
            {
                exit(1);
            }
            default:
                cout<<"\n Enter a valid choice, try again!\n";
        }
    }
    return 0;
}

