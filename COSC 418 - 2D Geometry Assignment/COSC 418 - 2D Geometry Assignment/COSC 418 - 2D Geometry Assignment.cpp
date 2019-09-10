//  COSC 418 - 2D Geometry Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <glut.h>
GLsizei winWidth = 400, winHeight = 300;
void init(void) {
	glClearColor(255.0, 255.0, 255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}
void displayFcn(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);



	//F. Use GL_QUADS to draw the doors of the two houses
	glBegin(GL_QUADS);
	glVertex2i(130, 0);
	glVertex2i(130, 80);
	glVertex2i(170, 80);
	glVertex2i(170, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2i(140, 50);
	glVertex2i(140, 90);
	glVertex2i(160, 90);
	glVertex2i(160, 50);
	glEnd();
	
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(650, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("2D Geometry Assignment");
	init();
	glutDisplayFunc(displayFcn);
	glutMainLoop();
}
