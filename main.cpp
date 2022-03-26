#include <windows.h>
#include <GL/glut.h>
#include <math.h>>
# define PI           3.14159265358979323846
//GLfloat i = 0.0f;
GLfloat l = 0.0f;
GLfloat m = 0.0f;
GLfloat n = 0.0f;

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}



void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.5);

 glBegin(GL_QUADS);
	glColor3ub(0,23,30);
	glVertex2f(-0.1f,1.0f); //sky2
	glVertex2f(0.3f,1.0f);
	glVertex2f(0.3f,0.6f);
	glVertex2f(-0.1f,0.6f);
	glEnd();

//////////////////////////////////////////////////////////////////////////////////////
	     glPushMatrix();
         glTranslated(0.1,0.8,0);
         glRotatef(n,0.0,0.0,-0.1);

         glBegin(GL_LINES);
	glColor3ub(230,230,230);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.18f, 0.1f);
	glEnd();

	glPopMatrix();//glPopMatrix pops the top matrix off the stack
    n+=.1f;//n=n+.1=.2



    glPushMatrix();
         glTranslated(0.1,0.8,0);
         glRotatef(m,0.0,0.0,-0.1);

         glBegin(GL_LINES);
	glColor3ub(230,230,230);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.12f, 0.1f);
	glEnd();

	glPopMatrix();//glPopMatrix pops the top matrix off the stack
    m+=0.03f;


    glPushMatrix();
         glTranslated(0.1,0.8,0);
         glRotatef(l,0.0,0.0,-0.1);

         glBegin(GL_LINES);
	glColor3ub(230,230,230);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.02f, 0.1f);
	glEnd();

	glPopMatrix();
    l+=0.01f;




	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Setup");
	glutInitWindowSize(320, 320);
	gluOrtho2D(-2,2,-2,2);

	glutDisplayFunc(display);
	    glutIdleFunc(Idle);
	glutMainLoop();
	return 0;
}
