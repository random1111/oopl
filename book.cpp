#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Book
     {
                char *Bname,*Author,*Publisher;
                int Stock; float Price;
                static int valid_transactions;
        public:
                Book();
                void Accept();
                void Display();
                int Search(char[]);
                friend void Display_All(Book[],int);
                void Update();
                void Purchase(int);
                static void Transactions()
                    {
                        cout<<"\nT "<<valid_transactions;       
                    }
     };
int Book::valid_transactions=0;
Book::Book()
{
        Bname=new char[15];
        Author=new char[15];
        Publisher=new char[15];
        Stock=Price=0;
}
void Book::Accept()
    {
        cout<<"\nEnter Book data";
        cout<<"\nBook Name: ";cin>>Bname;
        cout<<"\nAuthor: ";cin>>Author; 
        cout<<"\nPublisher: ";cin>>Publisher;
        cout<<"\nPrice: ";cin>>Price;
        cout<<"\nStock: ";cin>>Stock;
    }
void Book::Display()
    {
        cout<<"\nBook data";
        cout<<"\nBook Name: "<<Bname;
        cout<<"\nAuthor: "<<Author;
        cout<<"\nPublisher: "<<Publisher;
        cout<<"\nPrice: "<<Price;
        cout<<"\nStock: "<<Stock;
    }
int Book::Search(char N[])
   {
        if(strcasecmp(Bname,N)==0)
           return 1;
        return 0;  
   }
void Display_All(Book B[20],int n)
    {
        cout<<"\nBook data";
        cout<<"\nSr. No.\tBookName\tAuthor\tPublisher\tPrice\tStock";
        for(int i=0;i<n;i++)
           {
                cout<<"\n  "<<i+1<<setw(10)<<B[i].Bname<<setw(10)<<B[i].Author<<setw(10)<<B[i].Publisher;
                cout<<setw(10)<<B[i].Price<<setw(10)<<B[i].Stock;
           }
    }
void Book::Update()
    {
        int ch;
        cout<<"\nUpdate: 1:Stock 2:Price";
        cin>>ch;
        if(ch==1)
          {
                cout<<"Enter new stock";
                cin>>ch;
                Stock+=ch;
          } 
        else
            {
                cout<<"Enter new Price";
                cin>>Price;
            }
    } 
void Book::Purchase(int N)
    {
      if(N<=Stock)
        {       
              cout<<"\nTotal Price of Books: "<<N*Price;
              Stock-=N;
              valid_transactions++;
        }
      else cout<<"\nBook out of Stock";
    } 

int main()
   {
        int choice,n,i,No;
        Book B[25];
        char Name[20],ans;
        cout<<"\nAccept Book Data";
        cin>>n;
        for(i=0;i<n;i++)
            B[i].Accept();
        do
         {
                cout<<"\n1:Add New Book 2:Display All Books 3:Search 4:Update 5:Purchase 6: Valid transactions";
                cin>>choice;
                switch(choice)
                      {
                        case 1:  cout<<" Add New Book ";
                                 B[n++].Accept();
                                 break;
                        case 2:
                                 Display_All(B,n);
                                 break;
                        case 3:  cout<<"Enter Book name to Search ";
                                 cin>>Name;
                                 for(i=0;i<n;i++)
                                     if(B[i].Search(Name))
                                       {                                         
                                         B[i].Display();
                                         break;
                                       }
                                 if(i==n) cout<<"\nBook does not present";
                                 break;
                        case 4:  cout<<"Enter Book name to Update ";
                                 cin>>Name;
                                 for(i=0;i<n;i++)
                                     if(B[i].Search(Name))
                                       {
                                         B[i].Display();                                         
                                         B[i].Update();
                                         break;
                                       }
                                 if(i==n) cout<<"\nBook does not present";
                                 break;
                        case 5:  cout<<"Enter Book name to purchase ";
                                 cin>>Name;
                                 cout<<"Enter Number of Books Customer Purchased";
                                 cin>>No;
                                 for(i=0;i<n;i++)
                                     if(B[i].Search(Name))
                                       {                
                                         B[i].Display();                         
                                         B[i].Purchase(No);
                                         break;
                                       }
                                 if(i==n) cout<<"\nBook does not present";
                                 break;
                        case 6: Book::Transactions();
                                break;

                        default: cout<<"Wrong Choice";
                      }
                cout<<"\nMore...(y/n): ";
                cin>>ans;
         }while(ans=='y' || ans=='Y');   
   }
