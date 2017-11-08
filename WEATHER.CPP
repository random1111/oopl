#include<iostream>
using namespace std;
class Weather_Report
      {
                int Days;
                float Low_temp[31],High_temp[31];
                float Rain_amt[31],Snow_amt[31];
        public:
                Weather_Report();
                void Accept();
                void Display();
                Weather_Report Average(); 
      };
Weather_Report::Weather_Report()
{
        Days=0;
        for(int i=0;i<Days;i++)
           Low_temp[i]=High_temp[i]=Rain_amt[i]=Snow_amt[i]=0;
}
void Weather_Report:: Accept()
     {
        cout<<"\nEnter days of Month :";
        cin>>Days;
        for(int i=0;i<Days;i++)
           {    
                cout<<"\nDay "<<i+1; 
                cout<<"\nEnter low & high temperture ";
                cin>>Low_temp[i]>>High_temp[i];
                cout<<"\nEnter rain & snow amount";             
                cin>>Rain_amt[i]>>Snow_amt[i];
           } 
     }
void Weather_Report:: Display()
     {
        cout<<"\n Day\tLow temp\tHigh temp\tRain Amt \t Snow Amt";
        for(int i=0;i<Days;i++)
            cout<<"\n "<<i+1<<"\t   "<<Low_temp[i]<<"\t   "<<High_temp[i]<<"\t   "<<Rain_amt[i]<<"\t   "<<Snow_amt[i];
     }
Weather_Report Weather_Report:: Average()
     {
        Weather_Report T;       
        cout<<"\nAverage report of Month :";
        for(int i=0;i<Days;i++)
           {     
                T.Low_temp[0]+=Low_temp[i];
                T.High_temp[0]+=High_temp[i];
                T.Rain_amt[0]+=Rain_amt[i];
                T.Snow_amt[0]+=Snow_amt[i];
           } 
        T.Low_temp[0]/=Days;
        T.High_temp[0]/=Days;
        T.Rain_amt[0]/=Days;
        T.Snow_amt[0]/=Days;
        T.Days=1; 
        return T;
     }


int main()
    {
        Weather_Report WR[12],Avg;
        int choice,month; char ans;
        do
         {
        cout<<"\n1:Accept Month data 2: Monthly Average Report";
                cin>>choice;
                switch(choice)
                      {
                        case 1:  
                cout<<" Enter Month number(1:Jan 2:Feb...12:Dec): ";
                                 cin>>month;
                                 WR[month-1].Accept();
                                 WR[month-1].Display();
                                 break;
                        case 2:  
                cout<<" Enter Month number(1:Jan 2:Feb...12:Dec): ";
                                 cin>>month;
                                 Avg=WR[month-1].Average();
                                 Avg.Display();
                                 break;
                        default: cout<<"Wrong Choice";
                      }
                cout<<"\nMore...(y/n): ";
                cin>>ans;
         }while(ans=='y' || ans=='Y');   
       }
