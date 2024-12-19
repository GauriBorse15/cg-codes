#include <graphics.h>  
#include <stdlib.h>  
#include <iostream>    
#include <math.h> 
using namespace std; 
  
    void EightWaySymmetricPlot(int xc,int yc,int x,int y)  
   {  
    putpixel(x+xc,y+yc,1); 
    putpixel(y+xc,x+yc,5); 

    putpixel(x+xc,-y+yc,2);
    putpixel(y+xc,-x+yc,6); 
       
    putpixel(-x+xc,-y+yc,3);    
    putpixel(-y+xc,-x+yc,7);  

    putpixel(-x+xc,y+yc,4); 
    putpixel(-y+xc,x+yc,8);  
    
    delay(1000);
   }  
  
    void BresenhamCircle(int xc,int yc,int r)  
   {  
    int x = 0,y = r, d;

    d = 3 -(2*r);  
    
    EightWaySymmetricPlot(xc,yc,x,y);  
  
    while(x<=y)  
     {  
      if(d <= 0)  
      {  
        d = d + (4*x) + 6;  
      }  
     else  
      {  
        d = d + (4*x) - (4*y) + 10;  
        y = y - 1;  
      }  

       x = x + 1;

       EightWaySymmetricPlot(xc,yc,x,y);  
      }  
    }  
  
    int main()  
   {  
    /* request auto detection */  
    int xc,yc,r,gdriver = DETECT, gmode;  
    /* initialize graphics and local variables */  
     initgraph(&gdriver, &gmode, NULL);  
  
     
       cout<<"Enter the values of xc and yc :";  
       cin>>xc>>yc;  
       cout<<"Enter the value of radius  :";  
       cin>>r;  
       BresenhamCircle(xc,yc,r);  
  
     getch();  
     closegraph();  
     return 0;  
    }  