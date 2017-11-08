#include<iostream>
using namespace std;
class shape
        {
            protected:
                    double a,b;
            public:
                virtual void accept()
                {
                        cout<<"\nEnter a & b";
                        cin>>a>>b;
                }
              virtual void area()=0;
        };
class traingle: public shape
        {
           public:
           void area()
            {
                double ans;
                ans=0.5*a*b;
                cout<<"\nArea of triangle="<<ans;
            }
        };
class rectangle: public shape
        {
           public:
           void area()
            {
                double ans;
                ans=a*b;
                cout<<"\nArea of Rectangle="<<ans;
            }
        };

int main()
{
shape *ptr;
        traingle T;
        rectangle R;
        int ch;
do
        {
          cout<<"\ncalculate 1: Triangle   2:Rectangle    3:Exit";
          cout<<"\nEnter your choice: ";
          cin>>ch;
          switch(ch)
                 {
                case 1: 
                        ptr=&T;
                        ptr->getdata();
                        ptr->area();
                        break;
                case 2: 
                        ptr=&R;
                        ptr->getdata();
                        ptr->area();
                        break;
                }
        }while(ch<3);
        return 0;}
