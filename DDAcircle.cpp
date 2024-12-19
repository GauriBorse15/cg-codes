#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
 int gdriver=DETECT,gmode,tmp,n=0,r;
 float st_x,st_y,x1,x2,y1,y2,ep;

 initgraph(&gdriver,&gmode,NULL);

 cout<<"Enter Radius: ";
 cin>>r;

 while(r > pow(2,n))
 {	
  n++;
 } 
  ep = 1 / pow(2,n);


 st_x = 0; st_y = r;
 x1 = st_x;  y1 = st_y;

 do
 { 
 	x2 = x1 + (ep * y1);
  	y2 = y1 - (ep * x2);

  	putpixel(x2+200,y2+200,10);
  	

  	x1 = x2;
  	y1 = y2;

 }while((y1-st_y)<ep || (st_x-x1)>ep);

 	
    getch();
    return 0;

}
