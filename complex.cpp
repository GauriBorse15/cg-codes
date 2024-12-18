#include<iostream>
using namespace std;
class Complex{
    public:
    float img, real;
    Complex(){real=0.0; img=0.0;}


    Complex operator +(Complex);
    Complex operator *(Complex);
    friend istream &operator>>(istream&,Complex&);
    friend ostream &operator>>(ostream&, Complex&);
};
Complex Complex :: operator + (Complex obj)
{
    Complex temp;
    temp.real = real+obj.real;
    temp.img = img+obj.img;
    return temp;
}
Complex Complex :: operator * (Complex obj)
{
    Complex temp;
    temp.real = real*obj.real - img*obj.img;
    temp.img = real*obj.img + img*obj.real;
    return temp;
}
// Defination of istream
istream &operator>>(istream& is, Complex& obj)
{
    is>>obj.real;
    is>>obj.img;
    return is;
}
ostream &operator<<(ostream& os, Complex& obj)
{
    os<<obj.real;
    os<<"+"<<obj.img<<"i";
    return os;
}
int main()
{
    Complex a,b,c,d;
    cout<<"Enter 1st no:"<<endl;
    cout<<"Enter real and img parts"<<endl;
    cin>>a;
    cout<<"Enter 2nd no:"<<endl;
    cout<<"Enter real and img parts: "<<endl;
    cin>>b;
    cout<<"*****Arithmetic operations *****"<<endl;
    c = a+b;
    cout<<"Addition is"<<c<<endl;
    d = a*b;
    cout<<"the multiplication is"<<d<<endl;
}