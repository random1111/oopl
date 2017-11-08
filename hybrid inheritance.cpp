#include<iostream>
using namespace std;
class personal
{
public:
char nm[10];
char dob[10];
};
class academic:virtual public personal
{
public:
char qual[10];
char clgnm[10];
};
class professional:virtual public personal
{
public:
int empid,salary;
char cmpnm[10];
char post[10];
};
class biodata:public academic,public professional
{
public:
void accept();
void display();
};
void biodata::accept()
{
cout<<"\nenter data(nm,dob,qual,clgnm,cmpnm,post,salary,empid)";
cin>>nm>>dob>>qual>>clgnm>>cmpnm>>post>>salary>>empid;
}
void biodata::display()
{
cout<<"\n"<<nm<<"\t"<<dob<<"\t"<<qual<<"\t"<<clgnm<<"\t"<<cmpnm<<"\t"<<post<<"\t"<<salary<<"\t"<<empid;
}

int main()
{
int i,n;
biodata b[10];
cout<<"\nEnter number of records";
cin>>n;
for(i=0;i<n;i++)
{
b[i].accept();
}
cout<<"\nBio Data=";
cout<<"\nName\tDOB\tQual\tClgnm\tCmpnm\tPost\tSalary\tEmpid";
for(i=0;i<n;i++)
{
b[i].display();
}
}
