#include<iostream>
#include<graphics.h>

using namespace std;

int main()
{

   int gd=DETECT,gm, ch;
   initgraph(&gd,&gm,NULL);
    setbkcolor(WHITE);
    setcolor(BLACK); 
    
    for (int i=0; i<350; i++)
    {
      
      
    /***CAR BODY ******/
    line(50+i,370,90+i,370);  // void line(int x1, int y1, int x2, int y2);
    arc(110+i,370,180,360,20);  //void arc(int x, int y, int start_angle, int end_angle, int radius);
   /**Wheels**/
    circle(110+i,370,17);
    circle(240+i,370,17);

    line(130+i,370,220+i,370);
    arc(240+i,370,180,360,20);

    line(260+i,370,300+i,370);
    line(300+i,370,300+i,350);
    line(300+i,350,240+i,330);
    line(240+i,330,200+i,300);
    line(200+i,300,110+i,300);
    line(110+i,300,80+i,330);
    line(80+i,330,50+i,340);
    line(50+i,340,50+i,370);

    /***CAR Windows***/
    line(165+i,305,165+i,330);
    line(165+i,330,230+i,330);
    line(230+i,330,195+i,305);
    line(195+i,305,165+i,305);

    line(160+i,305,160+i,330);
    line(160+i,330,95+i,330);
    line(95+i,330,120+i,305);
    line(120+i,305,160+i,305);
     delay(10);
    cleardevice();  //clears the screen in graphics mode 
    line(0,390,639,390);  //ROAD
   	
   }  //ends of for loop
  
  getch();
  return 0;
} //ends of main function




