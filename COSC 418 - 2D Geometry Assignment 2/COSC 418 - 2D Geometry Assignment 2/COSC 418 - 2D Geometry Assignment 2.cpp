// COSC 418 - 2D Geometry Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Midpoint Circle Algorithm

#include <iostream>
using namespace std;
#include <glut.h>
GLsizei winWidth = 250, winHeight = 250;
void init(void) {
	glClearColor(255.0, 255.0, 255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-250.0, winWidth, -250.0, winHeight);
}
void displayFcn(void) {
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0);
	float r = 100;
	float x = 0, y = r;
	float p = 1 - r;
	glBegin(GL_POINTS);
	while (x != y)
	{
		x++;
		if (p < 0) {
			p += 2 * (x + 1) + 1;
		}
		else {
			y--;
			p += 2 * (x + 1) + 1 - 2 * (y - 1);
		}
		glVertex2i(x, y);
		glVertex2i(-x, y);
		glVertex2i(x, -y);
		glVertex2i(-x, -y);

		glVertex2i(y, x);
		glVertex2i(-y, x);
		glVertex2i(y, -x);
		glVertex2i(-y, -x);

	}
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("2D Geometry Assignment 2");
	init();
	glutDisplayFunc(displayFcn);
	glutMainLoop();
}

