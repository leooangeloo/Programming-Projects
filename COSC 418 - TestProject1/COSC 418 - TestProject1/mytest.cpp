using namespace std;
#include <glut.h>
GLsizei winWidth = 400, winHeight = 300;
void init(void) {
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}
void displayFcn(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(200, 200);
	glVertex2i(150, 200);
	glVertex2i(150, 150);
	glVertex2i(200, 150);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(650, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Triangle Program");
	init();
	glutDisplayFunc(displayFcn);
	glutMainLoop();
}