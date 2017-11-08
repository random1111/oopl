#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class b1
{
        protected:
                char name[10];
                char dob[10];    
                char bgroup[2];
        public:
                b1(){ name[0]=dob[0]=bgroup[0]='\0';}
void accept()
{
         cout<<"\n Enter the name:";             cin>>name;
         cout<<"\n Enter Date of birth(dd/mm/yy) :";     cin>>dob;
         cout<<"\n Enter bloog group:";  cin>>bgroup;
} 
void display()
    {
        cout<<"\n\n Name is:"<<name;
        cout<<"\n Date of Birth is:"<<dob;
        cout<<"\n Blood group is:"<<bgroup;             
    } 
};
class b2
{
        protected:
        float height,weight;
        public:
void accept()
{
        cout<<"\n Enter Height:";
        cin>>height;
        cout<<"\n Enter Weight:";
        cin>>weight;
}
void display()
    {
        cout<<"\n Height is is:"<<height;
        cout<<"\n Weight is:"<<weight;
    } 
};
class b3
{
   protected:
        long int policy_no;
        char address[30];
   public:
void accept()
    {
        cout<<"\n Enter Policy no:";
        cin>>policy_no;
        cout<<"\n Enter Contact address:";
        cin>>address;
    }
void display()
    {
        cout<<"\n Policy no is:"<<policy_no;
        cout<<"\n Contact address:"<<address;
    } 
};

class d:public b1,public b2,public b3
{
   private:
        long int driving_lic ;
        long int ph_no;
  public:       
        void accept();
        void display();
        void display_all();     
        int search(char[]);
        void modify();
};
void d::accept()
{
         b1::accept(); 
         b2::accept(); 
         b3::accept();
         cout<<"\n Enter Driving licence no:";
         cin>>driving_lic;
         cout<<"\n Enter telephone no:";
         cin>>ph_no;
}
void d::display()
    {
        b1::display(); 
        b2::display(); 
        b3::display();
        cout<<"\n Driving licence no:"<<driving_lic;
        cout<<"\n Telephone no:"<<ph_no;
    }
void d::display_all()
    {
        cout<<endl<<setw(10)<<name<<" "<<setw(10)<<dob<<" ";
        cout<<setw(3)<<bgroup<<setw(5)<<height<<setw(5)<<weight;
        cout<<setw(11)<<policy_no<<setw(11)<<address;
        cout<<setw(11)<<driving_lic<<setw(11)<<ph_no;
    }
int d::search(char nm[])
   {
      if(strcasecmp(name,nm)==0)
        return 1;
      return 0;
   }
void d::modify()
    {
         b1::accept(); b2::accept(); b3::accept();
         cout<<"\n Enter Driving licence no:";
         cin>>driving_lic;
         cout<<"\n Enter telephone no:";
         cin>>ph_no;
    }
int main()
   {
        int choice,n,i;
        char name[10];
        d D[10];
        cout<<"\nCreat Database:";
        cout<<"Enter Number of records:";
        cin>>n;
        for(i=0;i<n;i++)
            D[i].accept(); 
cout<<endl<<setw(5)<<"name"<<setw(5)<<"dob"<<setw(3)<<"bgroup"<<setw(5)<<"height";        cout<<setw(5)<<"weight"<<setw(11)<<"policy_no"<<setw(11)<<"address";
        cout<<setw(11)<<"driving_lic"<<setw(11)<<"ph_no";
        for(i=0;i<n;i++)
            D[i].display_all(); 
        do
          {  
cout<<"\n\tMENU\n\t 1.Insert new entry \n\t 2.Master table Display";
                cout<<"\n\t 3.Search & Display Record";
                cout<<"\n\t 4.Modify Record\n\t 5.Delete Record\n\t 6.Exit";
                cout<<"\n Enter your choice:";
                cin>>choice;
                switch(choice)
                      {
                          case 1: D[n++].accept();
                                  break;
                          case 2: cout<<"\nname\tdob\tbgroup\theight\tweight\tpolicy_no";
                                  cout<<"\taddress\tdriving_no\tph_no";
                                  for(i=0;i<n;i++)
                                  D[i].display_all(); 
                                  break;
                          case 3: cout<<"\nEnter person name";
                                  cin>>name;
                                  for(i=0;i<n;i++)
                                    if(D[i].search(name))
                                       { D[i].display();break;}
                                  if(i==n) cout<<"\nrecord does not present";            
                                   break;
                          case 4: cout<<"\nEnter person name";
                                  cin>>name;
                                  for(i=0;i<n;i++)
                                    if(D[i].search(name))
                                       { 
                                          D[i].display();
                                          D[i].modify();
                                          break;
                                        }
                                  if(i==n) cout<<"\nrecord does not present";            
                                   break;
                          case 5: cout<<"\nEnter person name";
                                  cin>>name;
                                  for(i=0;i<n;i++)
                                    if(D[i].search(name))
                                       { D[i].display();break;}
                                  if(i==n) cout<<"\nrecord does not present";            
                                  else {  n--;
                                          for(;i<n;i++)
                                              D[i]=D[i+1];
                                       }        
                                   break;
         }
  }while(choice<6);
return 0;
}
