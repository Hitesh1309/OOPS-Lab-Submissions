//CS20B1127
//Hitesh Gupta
//Printer Menu Driven Program for report cards of students

#include "CS20B1127_reportcard"
#include <iostream>

using namespace std;

int main()
{
    reportCard stu1,stu2,stu3;
    int choice,i,j;
    string name[10];
    int roll[10], score1[10], score2[10], score3[10], score4[10], score5[10];
    
    cout << " Enter the name of the student " ;
    getline(cin , name[1]);
    cout << " Enter the roll number of the student " ;
    cin >> roll[1];
    
    for(i=2;i<6;++i)
    {
        cout << " Enter the name of the student " ;
        cin.ignore(1024, '\n');
        getline(cin , name[i]);
        
        cout << " Enter the roll number of the student " ;
        cin >> roll[i];
    }
    
    reportCard stu4(name[4],roll[4]), stu5(name[5],roll[5]);
    
    while(1)
    {
        cout << "\n 1.Input the details for 5 students manually" ;
        cout << "\n 2.Input the details for 5 students randomly" ;
        cout << "\n 3.Display all students' report card records " ;
        cout << "\n 4.Exit " << endl;
        
        cin >> choice;
        switch(choice)
        {
            case 1:
                for(i=1;i<6;i++)
                {
                    cout << " Enter the marks for the subjects for the student - " << name[i] << " (roll number " << roll[i] << " ) :" << endl;
                    cout << " DSA : ";
                    cin >> score1[i];
                    while(score1[i]<0||score1[i]>100)
                    {
                        cout << "Please enter the marks between 0 to 100" << endl;
                        cin >> score1[i];
                    }
                    cout << " DAA : ";
                    cin >> score2[i];
                    while(score2[i]<0||score2[i]>100)
                    {
                        cout << " Please enter the marks between 0 to 100" << endl;
                        cin >> score2[i];
                    }
                    cout << " DSCS : ";
                    cin >> score3[i];
                    while(score3[i]<0||score3[i]>100)
                    {
                        cout << " Please enter the marks between 0 to 100" << endl;
                        cin >> score3[i];
                    }
                    cout << " OOP : ";
                    cin >> score4[i];
                    while(score4[i]<0||score4[i]>100)
                    {
                        cout << " Please enter the marks between 0 to 100" << endl;
                        cin >> score4[i];
                    }
                    cout << " PSP : ";
                    cin >> score5[i];
                    while(score5[i]<0||score5[i]>100)
                    {
                        cout << " Please enter the marks between 0 to 100" << endl;
                        cin >> score5[i];
                    }
                }
                
                stu1.createReportCard(name[1], roll[1], score1[1], score2[1], score3[1], score4[1], score5[1]);
                stu2.createReportCard(name[2], roll[2], score1[2], score2[2], score3[2], score4[2], score5[2]);
                stu3.createReportCard(name[3], roll[3], score1[3], score2[3], score3[3], score4[3], score5[3]);
                stu4.createReportCard(name[4], roll[4], score1[4], score2[4], score3[4], score4[4], score5[4]);
                stu5.createReportCard(name[5], roll[5], score1[5], score2[5], score3[5], score4[5], score5[5]);
                break;
            
            case 2:
                for(i=1;i<6;i++)
                {
                    score1[i]= rand()/((RAND_MAX + 1u)/100);
                    score2[i]= rand()/((RAND_MAX + 1u)/100);
                    score3[i]= rand()/((RAND_MAX + 1u)/100);
                    score4[i]= rand()/((RAND_MAX + 1u)/100);
                    score5[i]= rand()/((RAND_MAX + 1u)/100);
                }
                
                stu1.createReportCard(name[1], roll[1], score1[1], score2[1], score3[1], score4[1], score5[1]);
                stu2.createReportCard(name[2], roll[2], score1[2], score2[2], score3[2], score4[2], score5[2]);
                stu3.createReportCard(name[3], roll[3], score1[3], score2[3], score3[3], score4[3], score5[3]);
                stu4.createReportCard(name[4], roll[4], score1[4], score2[4], score3[4], score4[4], score5[4]);
                stu5.createReportCard(name[5], roll[5], score1[5], score2[5], score3[5], score4[5], score5[5]);
                break;
                
            case 3:
                cout << "----------------------------- Report Card -----------------------------" << endl;
                stu1.displayAll();
                cout << "\n-----------------------------------------------------------------------" << endl;
                stu2.displayAll();
                cout << "\n-----------------------------------------------------------------------" << endl;
                stu3.displayAll();
                cout << "\n-----------------------------------------------------------------------" << endl;
                stu4.displayAll();
                cout << "\n-----------------------------------------------------------------------" << endl;
                stu5.displayAll();
                cout << "\n-----------------------------------------------------------------------" << endl;
                cout << "\n-----------------------------------------------------------------------" << endl;
                break;
                
            case 4:
                exit(1);
                
            default:
                cout<<"\n Enter a valid choice, try again!\n";
        }
        
    }
}