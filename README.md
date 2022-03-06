# OOPS-Lab-Submissions
Object Oriented Programming Lab Course @IIITDM, 2021.
```
Kattamuri V S J V S Hitesh Gupta   - CS20B1127
```
This Lab covers C++ and Java.
# C++
## Lab-1
```
1.Write a C++ program to implement a queue or a circular queue ADT as a header file using class. Create a class for a queue with the following operations, enqueue, dequeue, display, peek, isFull, and isEmpty functions. Declare the enqueue and dequeue member functions inside the queue class and write their definitions outside the queue class using scope resolution operator. Define the remaining functions inside the queue class. The data members(variables declared inside the function) should use "Private" access specifier and member functions (function declared and defined withing the scope of a class) should use "Public" access specifier. Assume the queue stores integers and can store a maximum of  5 integers. Note: Should use cin and cout for getting and displaying values. Import the created queue header file into a "printer.cpp" file. The printer.cpp has the following menus,

1. Add to Print Queue
2. Current Job
3. Execute a Job
4. Display Jobs
5. Exit

Option 1 gets an integer job ID and stores it into the queue. 2 prints the job ID that will be executed next (Value present at the front of the queue). 3 removes the currently executed job ID from the queue and prints a message that The job <<Insert job ID>> has been completed. 4 Displays all the jobs pending in the queue pool. 5 quits from the program. Any other option should prompt the user to enter a valid option. Write appropriate boundary conditions, design functions, and comment properly.
```
---
## Lab-2
```
Write a C++ header program(abstraction) to create a Student Report Card System( use classes - encapsulation). Note: All the data members are declared private (secure data members) and member functions are defined under public.
Create student report card record: This feature creates a new student record containing his marks. For this, the information to be provided are the name and roll no. of the student, and the marks obtained by him/her in 5 subjects Any five subjects.

Display all student’s report card records: This feature displays the roll no. and name of all the students, the marks obtained by them in 5 subjects.

Declare a constructor that initializes the data members’ value to 0.

Declare a parameterized constructor that takes a name and roll number as parameters and assigns all other marks to 0.

Now, write a C++ Menu driven program to utilize the student report card system. Get details for 5 students. Let the 5 objects be stu1, stu2, stu3, stu4, and stu5. Let stu1, stu2, and stu3 be initialized by default constructors and stu4 and stu5 be initialized by parameterized constructors.  Maintain proper boundary conditions, follow coding best practices, declare and define functions following coding practices.

Eg: From the Menu program, for display, call like,
stu1.displayRecord();
stu2.displayRecord();
stu3.displayRecord();
stu4.displayRecord() ..
For creation, call from the main function like
stu1.create(name, roll no, mark1, mark2, mark3, mark4, mark5);
stu2.create(name, roll no, mark1, mark2, mark3, mark4, mark5); ..
Note: The above variable names and passing of parameters are just examples. 
```
---
## Lab-3
```
Note: No need of a separate header file.	
Given two sorted lists, merge them so as to produce a combined sorted list (without using extra space). The data members and the member function isEmpty() are private and the other member functions are public. The list stores integer data. Use new and delete keywords to dynamically allocate and deallocate memory whenever needed.
 Hint: use objects as function arguments and return type from a function or call an object by reference.
Examples: 
 
Input : head1: 5->7->9
        head2: 4->6->8 
Output : 4->5->6->7->8->9
Explanation: The output list is in sorted order.

Input : head1: 1->3->5->7
        head2: 2->4
Output : 1->2->3->4->5->7
Explanation: The output list is in sorted order.

The options for the list are
1. Insert
2. Delete
3. Display
4. Merge
5. Exit

When 1. Insert option is selected, request the user at which linked list should you insert the new element in the sorted order in the corresponding list.

When 2. Delete option is selected, request the user at which linked list should you delete at what position and delete the node present in the corresponding list.

When 3. Display option is selected, request the user which linked list should you display and print the elements in the corresponding list.

When 4. Merge option is selected, you can merge the contents of list2 to list1 or create a list 3 and merge the contents of list1 and list2 in the sorted order.

When 5. Exit option is selected, stop the program.
```
---
## Lab-4
```
Note: No need of a separate header file.	
Write a C++ program with Area and Volume class. The Area class has length, breath, and radius private data members. It has rectangle, and circle public member functions that calculate and return the area of the respective shape. All the member functions are inline functions and friend functions. If the parameters of a shape are not given, it calculates the unit area of the respective shape.

The Volume class has length, breadth, height and radius private data members. It has cuboid, sphere, compare cuboid, and compare sphere public member functions. The cuboid and sphere member functions are inline functions that use the respective area friend function of Area class to calculate the volume of the respective shapes. The compare volume function prints which among the two volumes is greater than the other. Utilize this pointer when calling compare volume function. If the parameters of a shape are not given, it calculates the unit volume of the respective shape.

Write a menu driven program to calculate the area of rectangle, area of circle, unit area of rectangle, unit area of circle, unit volume of cuboid, unit volume of sphere, volume of cuboid, volume of sphere, compare volume of two cuboids and compare volume of two spheres options.
```
---
## Lab-5
```
Write a C++ program using classes to implement a single linked list. The data members are private and member functions are public. Note: No need for a separate header file. Given two sorted lists, merge them so as to produce a combined sorted list (without using extra space). The data members and the member function isEmpty() are private and the other member functions are public. The list stores integer data. Overload the + operator to merge the two sorted linked lists. The merged list also should be in sorted order.
Examples: 
 
Input : head1: 5->7->9
           head2: 4->6->8 
Output : 4->5->6->7->8->9
Explanation: The output list is in sorted order.

Input : head1: 1->3->5->7
           head2: 2->4
Output : 1->2->3->4->5->7
Explanation: The output list is in sorted order.

The options for the list are
1. Insert
2. Display
3. Merge (Overload + operator to do this task)
4. Exit
```
---
## Lab-6
```
Write a C++ program using classes to implement a single linked list. The data members are private and member functions are public. Overload the insert and delete functions. If the insert function passes only the head pointer and the number to be inserted, then, insert at the end of the list. If the insert function passes head pointer, number to be inserted, and position to insert the element, overload the insert function and insert the number at the specified position. Similarly, overload the delete function. If the delete function passes only the head pointer, then, delete the element at the end of the list and return the deleted element.  If the delete function passes the head pointer, and position to delete the element, overload the delete function. Display function prints all the elements in the list. Maintain proper boundary conditions and design a menu driven program.
```
---
## Lab-7
```
Create an inheritance hierarchy that a bank might use to represent customers’ bank accounts. All customers at this bank can deposit (i.e., credit) money into their accounts and withdraw (i.e., debit) money from their accounts. More specific types of accounts also exist. Savings accounts, for instance, earn interest on the money they hold. Checking accounts, on the other hand, charge a fee per transaction (i.e., credit or debit). Create an inheritance hierarchy containing base class Account and derived classes SavingsAccount and CheckingAccount that inherit from class Account. Base class Account should include one data member of type double to represent the account balance and one data member of type int that represents the account number. The account number should be unique and must be provided by the user. The class should provide a constructor that receives an initial balance and uses it to initialize the data member. The constructor should validate the initial balance to ensure that it’s greater than or equal to 0.0. If not, the balance should be set to 0.0 and the constructor should display an error message, indicating that the initial balance was invalid. The class should have necessary member functions. Member function credit should add an amount to the current balance. Member function debit should withdraw money from the Account and ensure that the debit amount does not exceed the Account’s balance. If it does, the balance should be left unchanged and the function should print the message "Debit amount exceeded account balance." Member function getBalance should return the current balance. Member function creates an account number and it should be a unique account number for each user. 

Derived class SavingsAccount should inherit the functionality of an Account, but also include a data member of type double indicating the interest rate (percentage) assigned to the Account. SavingsAccount ’s constructor should receive the initial balance, as well as an initial value for the SavingsAccount ’s interest rate. SavingsAccount should provide a public member function calculateInterest that returns a double indicating the amount of interest earned by an account. Member function calculateInterest should determine this amount by multiplying the interest rate by the account balance. [Note: SavingsAccount should inherit member functions credit and debit as is without redefining them.]

Derived class CheckingAccount should inherit from base class Account and include an additional data member of type double that represents the fee charged per transaction. CheckingAccount’s constructor should receive the initial balance, as well as a parameter indicating a fee amount. Class CheckingAccount should redefine member functions credit and debit so that they subtract the fee from the account balance whenever either transaction is performed successfully. CheckingAccount ’s versions of these functions should invoke the base-class Account version to perform the updates to an account balance. CheckingAccount ’s debit function should charge a fee only if money is actually withdrawn (i.e., the debit amount does not exceed the account balance). [Hint: Define Account’s debit function so that it returns a bool indicating whether money was withdrawn. Then use the return value to determine whether a fee should be charged.] 

The data about the customers are stored in a separate singly linked list for SavingsAccount and CheckingAccount fashion. Use public inheritance for both derived classes. Maintain proper boundary conditions.

After defining the classes in this hierarchy, write a menu-driven program with the following options, 

1. Open Account (Savings or Checking Account)
2. Credit (Savings or Checking Account)
3. Debit (Savings or Checking Account)
4. Change/Update Interest rate (Savings Account)
5. Calculate Interest (Savings Account - Print)
6. Calculate and Update Interest (Savings Account - Credit)
7. Change/Update Fee Amount (Checking Account)
8. Print Checking Fee (Checking Account)
9. Transact and Update (Checking Account - Debit)
10. Exit
```
---
## Lab-8
```
Write a C++ program with Employee, Contract, Salaried, Manager, Intern  classes. The Employee class consists of employee_ID and employee_name as protected members.

Contract and Salaried classes are derived from Employee in protected mode. Contract consists of a pay_per_hour protected data member. It has setPay and getPay public member functions. Salaried consists of monthlyPay as protected data member. It also has setPay and getPay public member functions.

Manager is derived from Salaried in private mode. The Manager class consists of setDetails, getDetails, calculateSalary, and setSalary public member functions. setDetails updates employee_ID, employee_name, monthlyPay, and getDetails prints the values stored in these member functions. setSalary updates the salary of the manager. caculateSalary gets the number of working months and prints the total salary for the number of months the manager has worked.

Intern is derived from Contract in private mode. The Intern class consists of setDetails, getDetails, calculateSalary, and setSalary public member functions. setDetails updates employee_ID, employee_name, hourlyPay, and getDetails prints the values stored in these member functions. setSalary updates the salary of the intern. caculateSalary gets the number of working hours and prints the total salary for the number of hours the intern has worked. You can use an array of objects (size n) or singly-linked lists for storing and retrieving the information. Follow coding best practices, boundary conditions, and proper function design.
The menu to be created is as follows,
1. Create Employee (Manager or Intern)
2. Update Employee Details (Manager or Intern)
3. Print Employee Details (Manager or Intern)
4. Update Pay (Manager or Intern)
5. Calculate Salary (Manager or Intern)
6. Exit
```
---
## Lab-9
```
9.1 Consider 4 classes person, student, research_student, and TA. ‘person’ is the base class for student and research_student classes. TA inherits from student and research_student class. In every base class, all the data members have protected access and member functions have public access. All derived classes derive in protected mode. It has a parameterized constructor for the initialization of its data members.

The person class has name and roll_number as data members. It has a display member function with no arguments that display the name and roll_number of a person. It has a parameterized constructor for the initialization of its data members.

The student class has course1, course2, and course3 data members. It also has a display member function with no arguments that display the name, roll_number, and courses credited by the student. It has a parameterized constructor for the initialization of its data members.

The research_student class has course1 and research_area data members. It also has a display member function with no arguments that display the name, roll_number, course1, and research_area by the research student. It has a parameterized constructor for the initialization of its data members.

The TA class has course_assigned and role data members. It also has a display member function with no arguments. When display sub-option a. Person is selected, display the name, roll_number. If sub-option b) Student is selected display the name, roll_number, course1, course2, and course3. If sub-option c) Research Student is selected, display the name, roll_number, course1, and research_area. Finally, if sub-option d) Teaching Assistant is selected, display the name, roll_number, course_assigned, and role. ‘role’ can be either student or research student. Make sure ‘role’ should not be interchanged between student and research student. Course_assigned should not be the same as course1, course2, and course3 for a student and Course_assigned should not be the same as course1 for a research_student.  It has two parameterized constructors for the initialization of data members belonging to student and research_student data members respectively.

Identify and use the virtual, and template keywords wherever necessary. A person’s detail is stored in a singly-linked list. For simplicity, create list objects for the TA class alone. Maintain proper boundary conditions and follow coding best practices.

Write a menu-driven program with the following menus:

1. Set TA Details
2. Display 
  a. Person
  b. Student
  c. Research Student
  d. Teaching Assistant
3. Exit

9.2 Program to implement Bubble Sort using the template in C++ (function template). Write the program with menus.

9.3 Implement stack for int, char using templates in C++ (class template). Write the program with appropriate menus.

```
---
## Lab-10
```
Program to implement selection sort using the template in C++ (function template). The data is stored in an array of size ‘n’. Identify 1 boundary condition and handle them using exception handling. The program has the following menus,

1. Get Values
2. Sort
3. Display
4. Exit
```
---
# Java
## Lab-11
```
Create an applet window with a width of 1024 x 720 (width x height). Create an oval and place it at the top right portion of the applet window. Place a smaller filled oval inside the first oval. Draw a filled rectangle in the bottom left with an unfilled rectangle inside it. Draw a circle using the fill oval function and print a string inside the circle at the center. The size and color of each shape is your choice but it should satisfy the conditions given in the question. Make sure the color and size for each of the shapes are different.
```
---
## Lab-12
```
Write a Java program to create a calculator using event handling. The calculator supports addition, subtraction, multiplication, and division operations.
```
