 /* 7 Write C++ program to draw man walking in the rain with an umbrella. */
#include <graphics.h>
#include <math.h>

using namespace std;
int main()
{
int gd=DETECT,gm;
int j,i;

initgraph(&gd,&gm,NULL);
for(i=0;i<500;i=i+5)
{
	line(20,380,580,380); //platform
	
	if(i%2==0)
	{
		line(25+i,380,35+i,340); //leftleg
		line(45+i,380,35+i,340);//right leg
		line(35+i,310,25+i,330);//left hand
		delay(20);
	}
	else
	{
		line(35+i,380,35+i,340); //leftleg
		line(35+i,310,40+i,330); //left hand
		delay(20);
	}

	line(35+i,340,35+i,310); //body
	circle(35+i,300,10); //head
	line(35+i,310,50+i,330); // hand
	line(50+i,330,50+i,280); //umbrella stick
	line(15+i,280,85+i,280); //umbrella right

	arc(50+i,280,180,360,35); //umbrella body
	arc(55+i,330,360,180,5);//umbrella handle

         delay(200);
	cleardevice();
	
}
getch();
return 0;

}

