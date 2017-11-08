#include<iostream.h>
class complex
{
      private:
      float real,img;
      public:
       complex()
      {   img=0;
          real=0;
      }
         void accept();
         void display();      
      friend complex operator+(complex, complex);
      friend complex operator-(complex, complex);
      complex operator*(complex c2);
      complex operator/(complex c2);
};
void complex::accept()
{
   cout<<"\n Enter real & Imaginary value of Complex no:";
   cin>>real>>img;
}
void complex::display()
{
    cout<<"\n Complex no is:"<<real<<"+"<<img<<"i";
}

complex operator+(complex c1, complex c2)
{  complex c3;
   c3.real=c1.real+c2.real;
   c3.img=c1.img+c2.img;
   return(c3);
}
complex operator-(complex c1, complex c2)
{  complex c3;
   c3.real=c1.real-c2.real;
   c3.img=c1.img-c2.img;
   return(c3);
}
complex complex::operator*(complex c2)
{  complex c3;
   c3.real=(real*c2.real)-(img*c2.img);
   c3.img=(real*c2.img)+(img*c2.real);
   return(c3);
}
complex complex::operator/(complex c2)
{  complex c3;
   c3.real=((real*c2.real)+(img*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
   c3.img=(-(real*c2.img)+(img*c2.real))/((c2.real*c2.real)+(c2.img*c2.img));
   return(c3);
}

void main()
{  int ch;
   complex c1,c2,c3,c4,c5,c6;
    c1.accept();
    c2.accept();
    c1.display();
    c2.display();
 do
   {
      cout<<"\n1.+ operation\n2.- operation\n3.* operation\n4./ operation";
      cout<<"\nEnter your choice:";
      cin>>ch;
      switch(ch)
      {
        case 1:c3=c1+c2;
               c3.display();
               break;
        case 2:c4=c1-c2;
               c4.display();
               break;
        case 3:c5=c1*c2;
               c5.display();
               break;
        case 4:c6=c1/c2;
               c6.display();
               break;
      }
   }while(ch<5);

}
