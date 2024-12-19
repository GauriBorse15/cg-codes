#include<iostream>
#include<graphics.h>
using namespace std;

void move(int j, int h, int &x,int &y)   
		
{
	if(j==1)       //UPPER
	     y-=h;
	else if(j==2)  //RIGHT
	     x+=h;   
	else if(j==3)  //DOWN
	     y+=h;
	else if(j==4)   //LEFT
	     x-=h;
	
	lineto(x,y);
}

void hilbert(int u, int r,int d ,int l, int i, int h, int &x, int &y)
{              
	if(i>0)   
	{
		i--;  
		
		hilbert(r,u,l,d,i,h,x,y);   
		move(u,h,x,y);    //  |
		delay(1000);
		
		hilbert(u,r,d,l,i,h,x,y);
		move(r,h,x,y);    // __
        		delay(1000);
		
		hilbert(u,r,d,l,i,h,x,y);
        		move(d,h,x,y);   // |
		delay(1000);

		hilbert(l,d,r,u,i,h,x,y);
		delay(1000);
		
	}
}




int main()
{

int n, x=100,y=350,h=30,r=2,d=3,l=4,u=1;
int driver=DETECT,mode=0;
initgraph(&driver,&mode,NULL);

cout<<"Give the value of n: ";
cin>>n;

moveto(x,y);   //move to xpos and ypos
hilbert(u,r,d,l,n,h,x,y);            

delay(1000);
closegraph();

return 0;
}
