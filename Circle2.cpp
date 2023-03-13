#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

int centerX, centerY, radius;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void plot(int x, int y) {
    cout << "(" << x << "," << y << ")" << endl;
    glVertex2i(x, y);
}

void midpoint_circle() {
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    glBegin(GL_POINTS);
    while (x <= y) {
        plot(x + centerX, y + centerY);
        plot(y + centerX, x + centerY);
        plot(-x + centerX, y + centerY);
        plot(-y + centerX, x + centerY);
        plot(-x + centerX, -y + centerY);
        plot(-y + centerX, -x + centerY);
        plot(x + centerX, -y + centerY);
        plot(y + centerX, -x + centerY);
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        }
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    midpoint_circle();
}

int main(int argc, char** argv) {
    cout << "Enter the center point (x,y): ";
    cin >> centerX >> centerY;
    cout << "Enter the radius: ";
    cin >> radius;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint Circle Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
