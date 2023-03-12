#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

int xc, yc, radius;

void plotCirclePoints(int x, int y) {
    // plot circle points
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
    glEnd();

    // output circle points to console
    cout << "Point: (" << xc + x << ", " << yc + y << ")\n";
    cout << "Point: (" << xc - x << ", " << yc + y << ")\n";
    cout << "Point: (" << xc + x << ", " << yc - y << ")\n";
    cout << "Point: (" << xc - x << ", " << yc - y << ")\n";
    cout << "Point: (" << xc + y << ", " << yc + x << ")\n";
    cout << "Point: (" << xc - y << ", " << yc + x << ")\n";
    cout << "Point: (" << xc + y << ", " << yc - x << ")\n";
    cout << "Point: (" << xc - y << ", " << yc - x << ")\n";
}

void bresenhamCircle(int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y) {
        plotCirclePoints(x, y);
        x++;
        if (d < 0) {
            d = d + 4 * x + 6;
        }
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    bresenhamCircle(radius);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    cout << "Enter circle center (x, y): ";
    cin >> xc >> yc;

    cout << "Enter radius: ";
    cin >> radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
