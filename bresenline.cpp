#include<iostream>
#include<graphics.h>
using namespace std;
 
void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<x1)
	{
		if(p>=0)
		{
			y=y+1;
			p=p+2*dy-2*dx;
			putpixel(x,y,7);
			delay(500);

		}
		else
		{
			p=p+2*dy;
			putpixel(x,y,7);
			delay(500);
		}
		x=x+1;
	}
}
 
int main()
{
	int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
	initgraph(&gdriver, &gmode, NULL);
 
	cout<<"Enter co-ordinates of first point: ";
	cin>>x0>>y0;
 
	cout<<"Enter co-ordinates of second point: ";
	cin>>x1>>y1;
	drawline(x0, y0, x1, y1);
 
	return 0;
}