//CS20B1127
//Hitesh Gupta
//Program to find area and volume.

#include<iostream>
#include<cmath>

using namespace std;

//Class for finding area.
class Area
{
    private:
        int length;
        int breadth;
        int radius;
    public:
    
        Area() // Default constructor
        {
            length = 1;
            breadth = 1;
            radius = 1;
        }
        
        Area(int test1, int test2) // Parameterised constructor for Rectangle.
        {
            length = test1;
            breadth = test2;
            radius = 1;
        }

        Area(int test3) // Parameterised constructor for Circle.
        {
            length = 1;
            breadth = 1;
            radius = test3;
        }
        
        friend int areaOfRectangle(Area); // Friend function for finding area of rectangle.
        friend float areaOfCircle(Area); // Friend function for finding area of circle.
        
        ~Area(){}; //Destructor
};

//Class for finding volume.
class Volume
{
    private:
        int length;
        int breadth;
        int height;
        int radius;
    public:

        Volume() // Default Constructor.
        {
            length = 1;
            breadth = 1;
            height = 1;
            radius = 1;
        }

        Volume(int tem3) // Parameterised Constructor.
        {
            length = 1;
            breadth = 1;
            height = tem3;
            radius = tem3;
        }

        int volOfCuboid(Area); // Function to find volume of cuboid.
        float volOfSphere(Area); // Function to find volume of sphere.
        // Function to compare volume of two cuboids.
        int compareCuboid(Volume v, Area a, Area b)
        {
            return this->volOfCuboid(a) > v.volOfCuboid(b);
        }
        // Function to compare volume of two spheres.
        float compareSphere(Volume v, Area a, Area b)
        {
            return this->volOfSphere(a) > v.volOfSphere(b);
        }

        ~Volume(){};
};

// Function to find the area of rectangle.
inline int areaOfRectangle(Area a1)
{
    int temparea1 = a1.length*a1.breadth;
    return ( temparea1 );
}

// Function to find the area of the circle.
inline float areaOfCircle(Area a1)
{
    float temparea2 = (22.0*a1.radius*a1.radius)/7.0;
    return( temparea2 );
}

// Function to find the volume of cuboid.
inline int Volume :: volOfCuboid(Area a1)
{
    int temp = areaOfRectangle( a1 );
    int volC = temp*height;
    return( volC );
}

// Function to find the volume of sphere.
inline float Volume :: volOfSphere(Area a1)
{
    float temp1 = areaOfCircle( a1 );
    float volS = ((4*temp1*(sqrt(temp1*7/22)))/3);
    return( volS );
}

// Main function for menu.
int main()
{
    Area o;
    Volume v;
    int choice,num1,num2,num3;

    while(1)
    {
        cout << "\n 1.Area of Rectangle. " ;
        cout << "\n 2.Area of Circle. " ;
        cout << "\n 3.Unit Area of Rectangle. " ;
        cout << "\n 4.Unit Area of Circle. " ;
        cout << "\n 5.Unit Volume of Cuboid. " ;
        cout << "\n 6.Unit Volume of Sphere. " ;
        cout << "\n 7.Volume of Cuboid. " ;
        cout << "\n 8.Volume of Sphere. " ;
        cout << "\n 9.Compare Volume of two Cuboids. " ;
        cout << "\n 10.Compare Volume of two Spheres. " ;
        cout << "\n 11.Exit. " << endl ;
        cout << "\n Please enter your choice." << endl ;
        cin >> choice ;

        switch(choice)
        {
            case 1:
            {
                A:

                cout << "Enter the length of the Rectangle." << endl;
                cin >> num1;
                if(num1 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto A;
                }
                cout << "Enter the breadth of the Rectangle." << endl;
                cin >> num2;
                if(num2 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto A;
                }                

                Area o1(num1,num2);
                cout << "\nThe area of the Rectangle is : " ;
                cout << areaOfRectangle(o1) << endl ;

                break;
            }
            case 2:
            {
                B:

                cout << "Enter the radius of the Circle." << endl;
                cin >> num1;
                if(num1 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto B;
                }           

                Area o2(num1);
                cout << "\nThe area of the Circle is : " ;
                cout << areaOfCircle(o2) << endl ;

                break;
            }
            case 3:
            {
                cout << "\nThe area of Unit Rectangle is : ";
                cout << areaOfRectangle(o) << endl;

                break;
            }
            case 4:
            {
                cout << "\nThe area of Unit Circle is : ";
                cout << areaOfCircle(o) << endl;

                break;
            }
            case 5:
            {
                cout << "\nThe volume of Unit Cuboid is : ";
                cout << v.volOfCuboid(o) << endl;

                break;
            }
            case 6:
            {
                cout << "\nThe volume of Unit Sphere is : ";
                cout << v.volOfSphere(o) << endl;

                break;
            }
            case 7: 
            {
                C:

                cout << "Enter the length of the Cuboid." << endl;
                cin >> num1;
                if(num1 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto C;
                }
                cout << "Enter the breadth of the Cuboid." << endl;
                cin >> num2;
                if(num2 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto C;
                }                

                Area o3(num1,num2);

                cout << "Enter the height of the Cuboid." << endl;
                cin >> num3;
                if(num3 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto C;
                }           

                Volume v1(num3);
                cout << "\nThe volume of the Cuboid is : " ;
                cout << v1.volOfCuboid(o3) << endl ;

                break;
            }
            case 8:
            {
                D:

                cout << "Enter the radius of the Circle." << endl;
                cin >> num1;
                if(num1 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto D;
                }           

                Area o4(num1);
                Volume v2(num1);
                cout << "\nThe volume of the Sphere is : " ;
                cout << v2.volOfSphere(o4) << endl;    

                break;
            }
            case 9:
            {
                E:

                cout << "\nEnter the length of the Cuboid 1." << endl;
                cin >> num1;
                if(num1 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto E;
                }
                cout << "Enter the breadth of the Cuboid 1." << endl;
                cin >> num2;
                if(num2 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto E;
                }                

                Area o5(num1,num2);

                cout << "Enter the height of the Cuboid 1." << endl;
                cin >> num3;
                if(num3 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto E;
                }           

                Volume v3(num3);
                cout << "\nThe volume of the Cuboid 1 is : " ;
                cout << v3.volOfCuboid(o5) << endl ;

                F:

                cout << "\nEnter the length of the Cuboid 2." << endl;
                cin >> num1;
                if(num1 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto F;
                }
                cout << "Enter the breadth of the Cuboid 2." << endl;
                cin >> num2;
                if(num2 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto F;
                }                

                Area o6(num1,num2);

                cout << "Enter the height of the Cuboid 2." << endl;
                cin >> num3;
                if(num3 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto F;
                }           

                Volume v4(num3);
                cout << "\nThe volume of the Cuboid 2 is : " ;
                cout << v4.volOfCuboid(o6) << endl ;

                if( v4.compareCuboid( v3, o6, o5) == 0 )
                {
                    cout << "\nThe Volume of Cuboid 1 is greater than Cuboid 2" << endl;
                }
                else
                {
                    cout << "\nThe Volume of Cuboid 2 is greater than Cuboid 1" << endl;
                }

                break;
            }
            case 10:
            {
                G:

                cout << "\nEnter the radius of the Circle." << endl;
                cin >> num1;
                if(num1 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto G;
                }           

                Area o7(num1);
                Volume v5(num1);
                cout << "The volume of the Sphere is : " ;
                cout << v5.volOfSphere(o7) << endl;    

                H:

                cout << "\nEnter the radius of the Circle." << endl;
                cin >> num2;
                if(num2 < 0)
                {
                    cout << "Enter a positive number!!!" << endl;
                    goto H;
                }           

                Area o8(num2);
                Volume v6(num2);
                cout << "The volume of the Sphere is : " ;
                cout << v6.volOfSphere(o8) << endl;

                if( v6.compareCuboid( v5, o8, o7) == 0 )
                {
                    cout << "\nThe Volume of Sphere 1 is greater than Sphere 2" << endl;
                }
                else
                {
                    cout << "\nThe Volume of Sphere 2 is greater than Sphere 1" << endl;
                }

                break;
            }
            case 11:
            {
                exit(1);
            }
            default:
            {
                cout<<"\n Enter a valid choice, try again!\n";
            }
        }
    }    
    return 0;
}
