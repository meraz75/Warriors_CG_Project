#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>> // For cos & sin

# define PI           3.14159265358979323846 // For circle


/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	// Draw a Red 1x1 Square centered at origin


	glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3ub(187, 241, 250); // Red
	glVertex2f(-1.0f, 0.0f);    // x, y
	glVertex2f(-1.0f, 1.0f);    // x, y
	glVertex2f(1.0f, 1.0f);    // x, y
	glVertex2f(1.0f, 0.0f);    // x, y

	glEnd();

	glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f); // Red
	glVertex2f(-0.8f, 0.0f);    // x, y
	glVertex2f(-0.8f, 0.5f);    // x, y
	glVertex2f(-0.4f, 0.5f);    // x, y
	glVertex2f(-0.4f, 0.0f);    // x, y

	glEnd();

	glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3f (0.0f, 1.0f, 0.0f); // Red
	glVertex2f(0.8f, 0.0f);    // x, y
	glVertex2f(0.8f, 0.5f);    // x, y
	glVertex2f(0.4f, 0.5f);    // x, y
	glVertex2f(0.4f, 0.0f);    // x, y

	glEnd();


	// Circle
	int i;

	GLfloat x=-.7f; GLfloat y=.8f; GLfloat radius =.2f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(252, 139, 40);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop



	return 0;
}
