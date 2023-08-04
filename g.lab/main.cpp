#include <windows.h>

#include <GL/glut.h>



GLfloat a = 0.0f;
GLfloat b= 0.0f;


void initGL()

{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque

}



void Idle()

{

    glutPostRedisplay();//// marks the current window as needing to be redisplayed

}

void display()

{

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();//Reset the current matrix



    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack

    glRotatef(a,0.1,0.0,0.1);//i=how many degree you want to rotate around an axis





    glTranslatef(+0.5f, 0.0f, 0.0f);

   glBegin(GL_QUADS);               // Each set of 4 vertices form a quad

      glColor3f(1.0f, 1.f, 0.0f);  // Red

      glVertex2f(-0.1f, -0.1f);     // Define vertices in counter-clockwise (CCW) order

      glVertex2f( 0.1f, -0.1f);     //  so that the normal (front-face) is facing you

      glVertex2f( 0.1f,  0.01f);

      glVertex2f(-0.1f,  0.01f);

   glEnd();


      glLoadIdentity();                // Reset the model-view matrix

glRotatef(b,0.1,0.0,0.1);

glTranslatef(-0.3f, -0.f, 0.0f); // Translate x left and y down

   glBegin(GL_QUADS);               // Each set of 4 vertices form a quad

      glColor3f(1.0f, 0.0f, 1.0f);  // Red

      glVertex2f(-0.1f, -0.1f);     // Define vertices in counter-clockwise (CCW) order

      glVertex2f( 0.1f, -0.1f);     //  so that the normal (front-face) is facing you

      glVertex2f( 0.1f,  0.01f);

      glVertex2f(-0.1f,  0.01f);

   glEnd();
    glPopMatrix();





    a+=0.5f;
    b+=0.5f;


    glFlush();

}



int main(int argc, char** argv)

{

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitWindowSize(320, 320);

    glutCreateWindow("Model Transform");

    glutDisplayFunc(display);//

    initGL();

    glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.

    glutMainLoop();

    return 0;}
