#include<iostream>
#include<graphics.h>

using namespace std;
static int x_max, y_max, x_min, y_min;

// Defining region codes
static int INSIDE = 0; // 0000
static int LEFT = 1; // 0001
static int RIGHT = 2; // 0010
static int BOTTOM = 4; // 0100
static int TOP = 8; // 1000

// Defining x_max, y_max and x_min, y_min for
// clipping rectangle. Since diagonal points are
// enough to define a rectangle
// Function to compute region code for a point(x, y)
int binaryCode(double x, double y)
{
	// initialized as being inside
	int code = INSIDE;

	if (x < x_min) // to the left of rectangle
		code |= LEFT;
	else if (x > x_max) // to the right of rectangle
		code |= RIGHT;
	if (y < y_min) // below the rectangle
		code |= BOTTOM;
	else if (y > y_max) // above the rectangle
		code |= TOP;

	return code;
}

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x1, y1) to P2 = (x2, y2)

void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
	// Compute region codes for P1, P2
	int code1 = binaryCode(x1, y1);
	int code2 = binaryCode(x2, y2);

	// Initialize line as outside the rectangular window
	bool accept = false;
	

	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
		// If both endpoints lie within rectangle
			accept = true;
			break;
		}
		else if (code1 & code2) {
		// If both endpoints are outside rectangle,
			break;
		}
		else {
		// Some segment of line lies within the
		// rectangle
			int code_out;
			double x, y;

			// At least one endpoint is outside the
			// rectangle, pick it.
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

		// Find intersection point;
		// using formulas y = y1 + slope * (x - x1),
		// x = x1 + (1 / slope) * (y - y1)
			if (code_out & TOP) {
		// point is above the clip rectangle
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				// point is below the rectangle
			x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
			y = y_min;
			}
			else if (code_out & RIGHT) {
			// point is to the right of rectangle
			y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);			x = x_max;
			}
			else if (code_out & LEFT) {
			// point is to the left of rectangle
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			// Now intersection point x, y is found
			// We replace point outside rectangle
			// by intersection point
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = binaryCode(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = binaryCode(x2, y2);
			}
		}
	}
	if (accept) {
	delay(2000);
	rectangle(x_min,y_min,x_max,y_max);
	line(x1,y1,x2,y2);  
	}
}
// Driver code
int main()
{
	int gdriver = DETECT,gmode =VGAMAX;
	initgraph(&gdriver,&gmode,NULL);
	
            cout<<"Enter left, top and right, bottom of window: ";
	cin>>x_min>>y_min>>x_max>>y_max;
	rectangle(x_min,y_min,x_max,y_max);
	int x1,y1,x2,y2;
	cout<<"Enter the endpoints of the line: ";
	cin>>x1>>y1>>x2>>y2;
	line(x1,y1,x2,y2);  
	cleardevice();
	
	cohenSutherlandClip(x1,y1,x2,y2); 
	
	getch();
	return 0;
	
}
