#include<graphics.h>
#include<iostream>

using namespace std;

int main()
{
int x1,y1,x2,y2,dx,dy,length,i=0;
float x,y,xinc,yinc;
int gd=DETECT,gm;

initgraph(&gd,&gm,NULL);

cout<<"Enter the starting coordinates: ";
cin>>x1>>y1;
cout<<"Enter the ending coordinates: ";
cin>>x2>>y2;

dx=x2-x1;
dy=y2-y1;

if(abs(dx)>abs(dy))
length=abs(dx);
else
length=abs(dy);

xinc=dx/(float)length;
yinc=dy/(float)length;
x=x1;
y=y1;
putpixel(x,y,10);
cout<<"i\t"<<"X\t"<<"Y\t"<<endl;
cout<<"--------------------------"<<endl;
cout<<i<<"\t"<<x<<"\t"<<y<<"\t"<<endl;

for(i=1;i<length;i++)
{

x=x+xinc;
y=y+yinc;
putpixel(x,y,10);
cout<<i<<"\t"<<x<<"\t"<<y<<"\t"<<endl;
delay(100);
}

getch();
closegraph();
return 0;
}