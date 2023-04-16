#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

//minX = 200, minY = 250, maxX = 300, maxY = 350;

// Both in
//fstX = 205, fstY = 255, sndX = 295, sndY = 345;

// Both out
//fstX = 180, fstY = 355, sndX = 295, sndY = 355;

// One out
//fstX = 205, fstY = 255, sndX = 295, sndY = 355;
//fstX = 150, fstY = 300, sndX = 350, sndY = 300;

int minX, minY, maxX, maxY;
int fstX, fstY, sndX, sndY;

int code1[4] = { 0, 0, 0, 0 };
int code2[4] = { 0, 0, 0, 0 };

bool isReject = false;

int getcode1(int x, int y) {
	if (y > maxY)
	{
		code1[0] = 1;
	}

	if (y < minY)
	{
		code1[1] = 1;
	}

	if (x > maxX)
	{
		code1[2] = 1;
	}

	if (x < minX)
	{
		code1[3] = 1;
	}

	int codeRes1 = code1[0] * 1000 + code1[1] * 100 + code1[2] * 10 + code1[3];

	return codeRes1;
}

int getcode2(int x, int y) {
	if (y > maxY)
	{
		code2[0] = 1;
	}

	if (y < minY)
	{
		code2[1] = 1;
	}

	if (x > maxX)
	{
		code2[2] = 1;
	}

	if (x < minX)
	{
		code2[3] = 1;
	}

	int codeRes2 = code2[0] * 1000 + code2[1] * 100 + code2[2] * 10 + code2[3];

	return codeRes2;
}

void generateCodeForPoints()
{
	getcode1(fstX, fstY);
	getcode2(sndX, sndY);
}


void drawLine(int x0, int y0, int x1, int y1)
{
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
}

void cohenSuth()
{
	// Is both point accepted
	if (getcode1(fstX, fstY) == 0 && getcode2(sndX, sndY) == 0 && isReject == false)
	{
		drawLine(fstX, fstY, sndX, sndY);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			// Is both point rejected
			if (code1[i] == code2[i] && code1[i] == 1)
			{
				isReject = true;
				break;
			}


		}

		if (isReject)
		{
			cout << "Both point rejected" << endl;
		}
		else
		{
			//cout << "Not rejected" << endl;

			for (int i = 0; i < 4; i++)
			{
				if (code1[i] == 1)
				{
					switch (i)
					{

					case 0:
						fstY = maxY;
						break;

					case 1:
						fstY = minY;
						break;

					case 2:
						fstX = maxX;
						break;

					case 3:
						fstX = minX;
						break;
					}
				}

				if (code2[i] == 1)
				{
					switch (i)
					{

					case 0:
						sndY = maxY;
						break;

					case 1:
						sndY = minY;
						break;

					case 2:
						sndX = maxX;
						break;

					case 3:
						sndX = minX;
						break;
					}
				}



			}

			drawLine(fstX, fstY, sndX, sndY);
		}
	}
}


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 0.0);
	glRecti(minX, minY, maxX, maxY);

	glColor3f(0.0, 0.0, 0.0);
	cohenSuth();

	glFlush();
}

void main(int argc, char** argv)
{


	cout << "Enter Minimum window co-ordinates: "; cin >> minX >> minY;
	cout << "Enter Maximum window co-ordinates: "; cin >> maxX >> maxY;

	cout << "Enter co-ordinates of first point of line: "; cin >> fstX >> fstY;
	cout << "Enter co-ordinates of second point of line: "; cin >> sndY >> sndX;

	// 4 digit code generator
	generateCodeForPoints();

	cout << "First  point code: " << code1[0] << code1[1] << code1[2] << code1[3] << endl;
	cout << "Second point code: " << code2[0] << code2[1] << code2[2] << code2[3] << endl;



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Clipping with Cohen-Sutherland algorithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}
