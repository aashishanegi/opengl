// C program for implementing
// Mid-Point Ellipse Drawing Algorithm
#include<iostream>
#include <stdio.h>
#include <GL/glut.h>
using namespace std;
int rx, ry;//semi-Major axis & semi Minor Axis 100,150 
int xc, yc;//center of ellipse 300,300
void myinit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void midptellipse()
{

	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	// Initial decision parameter of region 1
	d1 = (ry * ry)
		- (rx * rx * ry)
		+ (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	printf("REGION 1: \n");
  	while (dx < dy)
	{
		setPixel(xc + x, yc + y);
		setPixel(xc - x, yc + y);
		setPixel(xc + x, yc - y);
		setPixel(xc - x, yc - y);



		// Print points based on 4-way symmetry
		printf("(%f, %f)\n", x + xc, y + yc);
		printf("(%f, %f)\n", -x + xc, y + yc);
		printf("(%f, %f)\n", x + xc, -y + yc);
		printf("(%f, %f)\n", -x + xc, -y + yc);

		// Checking and updating value of
		// decision parameter based on algorithm
		if (d1 < 0) {
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
      }
		else {
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
	}

	// Decision parameter of region 2
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))
		+ ((rx * rx) * ((y - 1) * (y - 1)))
		- (rx * rx * ry * ry);

	printf("REGION 2: \n");
	while (y >= 0)
	{
		setPixel(xc + x, yc + y);
		setPixel(xc - x, yc + y);
		setPixel(xc + x, yc - y);
		setPixel(xc - x, yc - y);

		// printing points based on 4-way symmetry
    printf("(%f, %f)\n", x + xc, y + yc);
		printf("(%f, %f)\n", -x + xc, y + yc);
		printf("(%f, %f)\n", x + xc, -y + yc);
		printf("(%f, %f)\n", -x + xc, -y + yc);

		// Checking and updating parameter
		// value based on algorithm
		if (d2 > 0) {
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else {
			y--;
			x++;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (rx * rx);
		}
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
	glColor3f(1.0, 0.0, 0.0);          // red foreground
	glPointSize(2.0);               // size of points to be drawin (in pixel)

	//establish a coordinate system for the image

	midptellipse();
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "\n\nEnter Center Of Ellipse  \n\n";
	cout << "\n x = ";
	cin >> xc;

	cout << "\n y = ";
	cin >> yc;

	cout << " Enter a Semi Major Axix : ";
	cin >> rx;
	cout << " \nEnter a Semi Minor Axis: ";
	cin >> ry;
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480); // set the size of the window
	glutInitWindowPosition(10, 10); // the position of the top-left of window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
	myinit();
	glutDisplayFunc(display); // set the gl display callback function
	glutMainLoop(); // enter the GL event loop

}
