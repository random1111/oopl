#include<iostream>
using namespace std;
class test
{
float x,y;
public:
void accept()
{
  cout<<"Enter two numbers";
 cin>>x>>y;
}
float divide()
{
   try
   {
    	if(y==0)
	    throw(y);
  	cout<<"Division is:"<<x/y;
    } 
    catch(float p)
    {
    		cout<<"Divide by zero exception"<<p;
    }
}
};
int main()
{
     test T;
     T.accept();
     T.divide();
}
