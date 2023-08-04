 #include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include<math.h>>
# define PI           3.14159265358979323846

float _moveb1 = 0.00f; //bus

float _moveSun = 0.00f;

float _movet1= 0.00f;

float _movecar1= 0.00f;
float _movecar2= 0.00f;

float _moveObject =0.0f;
float _movePlane = 0.0f;
float _moveCloud =0.0f;

float _moveCloudleft=0.0f;

float _moveWater=0.0f;


void init()
{

        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
         gluOrtho2D(-0.64,0.64,-0.64,0.64);


}


void updateb1(int value) {
 _moveb1 += .02;
if(_moveb1 > 1.5)
{
_moveb1 = -1.5;
}
glutPostRedisplay();
glutTimerFunc(70, updateb1, 0);
}

void updateSun(int value) {
 _moveSun -= .02;
if(_moveSun > +0.27)
{
_moveSun= +0.64;
}
glutPostRedisplay();
glutTimerFunc(800, updateSun, 0);
}

void updatet1(int value) {
 _movet1 += .02;
if(_movet1 > 1.00)
{
_movet1 = -1.00;
}
glutPostRedisplay();
glutTimerFunc(200, updatet1, 0);
}

void updateObject(int value) {
 _moveObject += .02;
if(_moveObject > 1.00)
{
_moveObject = -1.00;
}
glutPostRedisplay();
glutTimerFunc(400, updateObject, 0);
}


void updateCar1(int value) {
 _movecar1 -= .02;
if(_movecar1 < -1.5)
{
_movecar1 = 1.5;
}
glutPostRedisplay();
glutTimerFunc(5, updateCar1, 0);
}


void updateCar2(int value) {
 _movecar2 += .02;
if(_movecar2 > 1.5)
{
_movecar2 = -1.5;
}
glutPostRedisplay();
glutTimerFunc(80, updateCar2, 0);
}


void updatePlane(int value) {
 _movePlane += .02;
if(_movePlane > 1.5)
{
_movePlane  = -1.5;
}
glutPostRedisplay();
glutTimerFunc(130, updatePlane, 0);
}


void updateCloud(int value) {               //left to right
 _moveCloud += .02;
if(_moveCloud > 1.5)
{
_moveCloud  = -1.5;
}
glutPostRedisplay();
glutTimerFunc(190, updateCloud, 0);
}


void updateCloudleft(int value) {           //right to left
 _moveCloudleft -= .02 ;
if(_moveCloudleft < -1.5)
{
_moveCloudleft  = 1.5;
}


glutTimerFunc(190, updateCloudleft, 0);
}


void updateWater(int value) {
 _moveWater += .01;
if(_moveWater > 0.0)
{
_moveWater  = -0.62;
}

glutPostRedisplay();
    glutTimerFunc(300, updateWater, 0);
}

///...............Rain
GLfloat position8 = 0.0f;
GLfloat Speed8= 0.02f;

GLfloat position9 = 0.0f;
GLfloat Speed9= 0.06f;

GLfloat position10 = 0.0f;
GLfloat Speed10= 0.02f;

///.......................................Rain

void update8 (int value)
{
   if(position8 <-1.0)
      position8 =0.2f;

      position8 -= Speed8;

      glutPostRedisplay();

    if(position9 >1.0)
      position9 =-1.0f;

      position9 += Speed9;

      glutPostRedisplay();


    if(position10 <1.0)
      position10 =-0.1f;

      position10 -= Speed10;

      glutPostRedisplay();

   glutTimerFunc(100,update8,0);
}
/*rain*/






void circleSolid(float x, float y, float radius)
{

    int triangleAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}


void sun()

{
///sun day

glPushMatrix();
    glTranslatef( 0.0f, _moveSun,0.00f);

    glColor3ub( 253, 208, 23);
    circleSolid(0.08f,0.40f,0.07);

     glPopMatrix();
    glutSwapBuffers();

}
void sunN()

{
///sun night
    glColor3ub( 255, 255, 255);
    circleSolid(0.08f,0.40f,0.05);
}




void sky()
{

    glBegin(GL_QUADS);
    glColor3ub(130, 202, 255);
    glVertex2f(-0.64f,0.00f);
    glVertex2f(0.64f,0.00f);
    glVertex2f(0.64f,.64f);
    glVertex2f(-0.64f,.64f);
    glEnd();
}

//void star()
//{
//
//    circleSolid()
//}
void skyN()
{

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-0.64f,0.00f);
    glVertex2f(0.64f,0.00f);
    glVertex2f(0.64f,.64f);
    glVertex2f(-0.64f,.64f);
    glEnd();

    glColor3ub( 255, 255, 255);
    circleSolid(-0.60f,0.38f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.50f,0.43f,0.003);
    glColor3ub( 255, 255, 255);
    circleSolid(-0.55f,0.53f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.40f,0.49f,0.003);



    glColor3ub( 255, 255, 255);
    circleSolid(-0.10f,0.48f,0.003);
    glColor3ub( 255, 255, 255);
    circleSolid(-0.5f,0.55f,0.003);




    glColor3ub( 255, 255, 255);
    circleSolid(-0.30f,0.48f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.21f,0.38f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.10f,0.60f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.21f,0.56f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.35f,0.39f,0.003);

    //***

    glColor3ub( 255, 255, 255);
    circleSolid(0.10f,0.53f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(0.21f,0.48f,0.003);

    glColor3ub( 255, 255, 255);

    circleSolid(0.31f,0.46f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(0.40f,0.50f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(0.50f,0.53f,0.003);


    glColor3ub( 255, 255, 255);
    circleSolid(0.40f,0.40f,0.003);


    glColor3ub( 255, 255, 255);
    circleSolid(0.55f,0.39f,0.003);


    glColor3ub( 255, 255, 255);
    circleSolid(0.31f,0.57f,0.003);

    glColor3ub( 255, 255, 255);
    circleSolid(0.22f,0.55f,0.003);

}

void skyR()
{

    glBegin(GL_QUADS);
    glColor3ub(64, 98, 131);
    glVertex2f(-0.64f,0.00f);
    glVertex2f(0.64f,0.00f);
    glVertex2f(0.64f,.64f);
    glVertex2f(-0.64f,.64f);
    glEnd();
}



void house()
{
    /*left side*/
    /*b1*/
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 255);
    glVertex2f(-0.64f, 0.0f);
    glVertex2f(-0.52f, 0.0f);
    glVertex2f(-0.52f, 0.32f);
    glVertex2f(-0.64f, 0.32f);

    glColor3ub(102, 102, 255);         //window
    glVertex2f(-0.63f, 0.04f);
    glVertex2f(-0.59f, 0.04f);
    glVertex2f(-0.59f, 0.09f);
    glVertex2f(-0.63f, 0.09f);

    glVertex2f(-0.63f, 0.12f);//top left
    glVertex2f(-0.59f, 0.12f);
    glVertex2f(-0.59f, 0.17f);
    glVertex2f(-0.63f, 0.17f);

    glVertex2f(-0.57f, 0.04f);// dowm right
    glVertex2f(-0.53f, 0.04f);
    glVertex2f(-0.53f, 0.09f);
    glVertex2f(-0.57f, 0.09f);


    glVertex2f(-0.57f, 0.20f);//top right
    glVertex2f(-0.53f, 0.20f);
    glVertex2f(-0.53f, 0.25f);
    glVertex2f(-0.57f, 0.25f);

    glVertex2f(-0.57f, 0.12f);//top right
    glVertex2f(-0.53f, 0.12f);
    glVertex2f(-0.53f, 0.17f);
    glVertex2f(-0.57f, 0.17f);
    glEnd();

    /*b2 */
    //change

    glBegin(GL_QUADS);
    glColor3ub(139, 129, 76);
    glVertex2f(-0.50f, 0.0f);
    glVertex2f(-0.32f, 0.0f);
    glVertex2f(-0.32f, 0.31f);
    glVertex2f(-0.50f, 0.31f);

//window
    glColor3ub(0 ,205, 0);
    glVertex2f(-0.49f, 0.04f);
    glVertex2f(-0.45f, 0.04f);
    glVertex2f(-0.45f, 0.11f);
    glVertex2f(-0.49f, 0.11f);

    glVertex2f(-0.37f, 0.04f);
    glVertex2f(-0.33f, 0.04f);
    glVertex2f(-0.33f, 0.11f);
    glVertex2f(-0.37f, 0.11f);

    glVertex2f(-0.43f, 0.04f);
    glVertex2f(-0.39f, 0.04f);
    glVertex2f(-0.39f, 0.11f);
    glVertex2f(-0.43f, 0.11f);


    glVertex2f(-0.49f, 0.14f);
    glVertex2f(-0.45f, 0.14f);
    glVertex2f(-0.45f, 0.20f);
    glVertex2f(-0.49f, 0.20f);

    glVertex2f(-0.43f, 0.14f);
    glVertex2f(-0.39f, 0.14f);
    glVertex2f(-0.39f, 0.20f);
    glVertex2f(-0.43f, 0.20f);

    glVertex2f(-0.37f, 0.14f);
    glVertex2f(-0.33f, 0.14f);
    glVertex2f(-0.33f, 0.20f);
    glVertex2f(-0.37f, 0.20f);// jdcd

    glVertex2f(-0.49f, 0.24f);
    glVertex2f(-0.45f, 0.24f);
    glVertex2f(-0.45f, 0.29f);
    glVertex2f(-0.49f, 0.29f);

    glVertex2f(-0.43f, 0.24f);
    glVertex2f(-0.39f, 0.24f);
    glVertex2f(-0.39f, 0.29f);
    glVertex2f(-0.43f, 0.29f);

    glVertex2f(-0.37f, 0.24f);
    glVertex2f(-0.33f, 0.24f);
    glVertex2f(-0.33f, 0.29f);
    glVertex2f(-0.37f, 0.29f);
    glEnd();
    /*b3 */
    //change

    glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex2f(-0.29f, 0.0f);
    glVertex2f(-0.17f, 0.0f);
    glVertex2f(-0.17f, 0.27f);
    glVertex2f(-0.29f, 0.27f);


    glColor3ub(46,117,182);          // left 1
    glVertex2f(-0.28f, 0.03f);
    glVertex2f(-0.24f, 0.03f);
    glVertex2f(-0.24f, 0.09f);
    glVertex2f(-0.28f, 0.09f);

    glVertex2f(-0.28f, 0.11f);     //left 02
    glVertex2f(-0.24f, 0.11f);
    glVertex2f(-0.24f, 0.17f);
    glVertex2f(-0.28f, 0.17f);

    glVertex2f(-0.28f, 0.19f);  //left 03
    glVertex2f(-0.24f, 0.19f);
    glVertex2f(-0.24f, 0.25f);
    glVertex2f(-0.28f, 0.25f);

    glVertex2f(-0.22f, 0.03f);
    glVertex2f(-0.18f, 0.03f);
    glVertex2f(-0.18f, 0.09f);
    glVertex2f(-0.22f, 0.09f);

    glVertex2f(-0.22f, 0.11f);
    glVertex2f(-0.18f, 0.11f);
    glVertex2f(-0.18f, 0.17f);
    glVertex2f(-0.22f, 0.17f);

    glVertex2f(-0.22f, 0.19f);
    glVertex2f(-0.18f, 0.19f);
    glVertex2f(-0.18f, 0.25f);
    glVertex2f(-0.22f, 0.25f);

    /*glVertex2f(-0.16f, 0.03f);
    glVertex2f(-0.12f, 0.03f);
    glVertex2f(-0.12f, 0.09f);
    glVertex2f(-0.16f, 0.09f);

    glVertex2f(-0.16f, 0.11f);
    glVertex2f(-0.12f, 0.11f);
    glVertex2f(-0.12f, 0.17f);
    glVertex2f(-0.16f, 0.17f);

    glVertex2f(-0.16f, 0.19f);
    glVertex2f(-0.12f, 0.19f);
    glVertex2f(-0.12f, 0.25f);
    glVertex2f(-0.16f, 0.25f);*/
    glEnd();

//**right side

//**b4

    glBegin(GL_QUADS);
    glColor3ub(0, 102, 153);
    glVertex2f(0.64f, 0.0f);
    glVertex2f(0.52f, 0.0f);
    glVertex2f(0.52f, 0.44f);
    glVertex2f(0.64f, 0.44f);


    glColor3ub(0, 33, 51);         //window
    glVertex2f(0.63f, 0.04f);
    glVertex2f(0.59f, 0.04f);
    glVertex2f(0.59f, 0.09f);
    glVertex2f(0.63f, 0.09f);

    glVertex2f(0.63f, 0.12f);
    glVertex2f(0.59f, 0.12f);
    glVertex2f(0.59f, 0.17f);
    glVertex2f(0.63f, 0.17f);

    glVertex2f(0.57f, 0.04f);
    glVertex2f(0.53f, 0.04f);
    glVertex2f(0.53f, 0.09f);
    glVertex2f(0.57f, 0.09f);

    glVertex2f(0.57f, 0.12f);
    glVertex2f(0.53f, 0.12f);
    glVertex2f(0.53f, 0.17f);
    glVertex2f(0.57f, 0.17f);

    //
    glVertex2f(0.63f, 0.20f);
    glVertex2f(0.59f, 0.20f);
    glVertex2f(0.59f, 0.25f);
    glVertex2f(0.63f, 0.25f);

    glVertex2f(0.63f, 0.28f);
    glVertex2f(0.59f, 0.28f);
    glVertex2f(0.59f, 0.33f);
    glVertex2f(0.63f, 0.33f);

    glVertex2f(0.63f, 0.36f);
    glVertex2f(0.59f, 0.36f);
    glVertex2f(0.59f, 0.41f);
    glVertex2f(0.63f, 0.41f);
    //
     glVertex2f(0.57f, 0.20f);
    glVertex2f(0.53f, 0.20f);
    glVertex2f(0.53f, 0.25f);
    glVertex2f(0.57f, 0.25f);

    glVertex2f(0.57f, 0.28f);
    glVertex2f(0.53f, 0.28f);
    glVertex2f(0.53f, 0.33f);
    glVertex2f(0.57f, 0.33f);

    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.53f, 0.36f);
    glVertex2f(0.53f, 0.41f);
    glVertex2f(0.57f, 0.41f);
    //

    glEnd();

    //***b5
    glBegin(GL_QUADS);
    glColor3ub(153, 0, 204);
    glVertex2f(0.50f, 0.0f);
    glVertex2f(0.32f, 0.0f);
    glVertex2f(0.32f, 0.30f);
    glVertex2f(0.50f, 0.30f);


    glColor3ub(56, 0, 77);              // window
    glVertex2f(0.49f, 0.04f);
    glVertex2f(0.45f, 0.04f);
    glVertex2f(0.45f, 0.11f);
    glVertex2f(0.49f, 0.11f);

    glVertex2f(0.37f, 0.04f);
    glVertex2f(0.33f, 0.04f);
    glVertex2f(0.33f, 0.11f);
    glVertex2f(0.37f, 0.11f);

    glVertex2f(0.43f, 0.04f);
    glVertex2f(0.39f, 0.04f);
    glVertex2f(0.39f, 0.11f);
    glVertex2f(0.43f, 0.11f);

    glVertex2f(0.49f, 0.14f);
    glVertex2f(0.45f, 0.14f);
    glVertex2f(0.45f, 0.20f);
    glVertex2f(0.49f, 0.20f);

    glVertex2f(0.43f, 0.14f);
    glVertex2f(0.39f, 0.14f);
    glVertex2f(0.39f, 0.20f);
    glVertex2f(0.43f, 0.20f);

    glVertex2f(0.37f, 0.14f);
    glVertex2f(0.33f, 0.14f);
    glVertex2f(0.33f, 0.20f);
    glVertex2f(0.37f, 0.20f);
    //
    //
    glVertex2f(0.49f, 0.22f);
    glVertex2f(0.45f, 0.22f);
    glVertex2f(0.45f, 0.28f);
    glVertex2f(0.49f, 0.28f);

    glVertex2f(0.43f, 0.22f);
    glVertex2f(0.39f, 0.22f);
    glVertex2f(0.39f, 0.28f);
    glVertex2f(0.43f, 0.28f);

    glVertex2f(0.37f, 0.22f);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.33f, 0.28f);
    glVertex2f(0.37f, 0.28f);
    glEnd();

//**b6
//change

    glBegin(GL_QUADS);
    glColor3ub(255, 153, 51);
    glVertex2f(0.29f, 0.0f);
    glVertex2f(0.17f, 0.0f);
    glVertex2f(0.17f, 0.27f);
    glVertex2f(0.29f, 0.27f);


    glColor3ub(204, 51, 0);          // left 1
    glVertex2f(0.28f, 0.03f);
    glVertex2f(0.24f, 0.03f);
    glVertex2f(0.24f, 0.09f);
    glVertex2f(0.28f, 0.09f);

    glVertex2f(0.28f, 0.11f);     //left 02
    glVertex2f(0.24f, 0.11f);
    glVertex2f(0.24f, 0.17f);
    glVertex2f(0.28f, 0.17f);

    glVertex2f(0.28f, 0.19f);  //left 03
    glVertex2f(0.24f, 0.19f);
    glVertex2f(0.24f, 0.25f);
    glVertex2f(0.28f, 0.25f);

    glVertex2f(0.22f, 0.03f);
    glVertex2f(0.18f, 0.03f);
    glVertex2f(0.18f, 0.09f);
    glVertex2f(0.22f, 0.09f);

    glVertex2f(0.22f, 0.11f);
    glVertex2f(0.18f, 0.11f);
    glVertex2f(0.18f, 0.17f);
    glVertex2f(0.22f, 0.17f);

    glVertex2f(0.22f, 0.19f);
    glVertex2f(0.18f, 0.19f);
    glVertex2f(0.18f, 0.25f);
    glVertex2f(0.22f, 0.25f);

    /*glVertex2f(0.16f, 0.03f);
    glVertex2f(0.12f, 0.03f);
    glVertex2f(0.12f, 0.09f);
    glVertex2f(0.16f, 0.09f);

    glVertex2f(0.16f, 0.11f);
    glVertex2f(0.12f, 0.11f);
    glVertex2f(0.12f, 0.17f);
    glVertex2f(0.16f, 0.17f);

    glVertex2f(0.16f, 0.19f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.12f, 0.25f);
    glVertex2f(0.16f, 0.25f);*/
    glEnd();

    /* end of building */
}






void houseN()
{
    /*left side*/
    /*b1*/
    glBegin(GL_QUADS);
    glColor3ub(105, 105, 105);
    glVertex2f(-0.64f, 0.0f);
    glVertex2f(-0.52f, 0.0f);
    glVertex2f(-0.52f, 0.22f);
    glVertex2f(-0.64f, 0.22f);

    glColor3ub(123,140,136); //pipe
    glVertex2f(-0.62f, 0.22f);
    glVertex2f(-0.62f, 0.24f);
    glVertex2f(-0.60f, 0.24f);
    glVertex2f(-0.60f, 0.22f);

    glVertex2f(-0.63f, 0.25f); //pipe Cap
    glVertex2f(-0.63f, 0.24f);
    glVertex2f(-0.59f, 0.24f);
    glVertex2f(-0.59f, 0.25f);

    glColor3ub(102, 102, 255);         //window
    glVertex2f(-0.63f, 0.04f);
    glVertex2f(-0.59f, 0.04f);
    glVertex2f(-0.59f, 0.09f);
    glVertex2f(-0.63f, 0.09f);

    glVertex2f(-0.63f, 0.12f);
    glVertex2f(-0.59f, 0.12f);
    glVertex2f(-0.59f, 0.17f);
    glVertex2f(-0.63f, 0.17f);

    glVertex2f(-0.57f, 0.04f);
    glVertex2f(-0.53f, 0.04f);
    glVertex2f(-0.53f, 0.09f);
    glVertex2f(-0.57f, 0.09f);

    glVertex2f(-0.57f, 0.12f);
    glVertex2f(-0.53f, 0.12f);
    glVertex2f(-0.53f, 0.17f);
    glVertex2f(-0.57f, 0.17f);
    glEnd();

    /*b2 */
    glBegin(GL_QUADS);
    glColor3ub(105, 105, 105);
    glVertex2f(-0.50f, 0.0f);
    glVertex2f(-0.32f, 0.0f);
    glVertex2f(-0.32f, 0.24f);
    glVertex2f(-0.50f, 0.24f);

    glColor3ub(123,140,136); //pipe
    glVertex2f(-0.48f, 0.24f);
    glVertex2f(-0.48f, 0.27f);
    glVertex2f(-0.46f, 0.27f);
    glVertex2f(-0.46f, 0.24f);

    glVertex2f(-0.49f, 0.28f); //pipe Cap
    glVertex2f(-0.49f, 0.27f);
    glVertex2f(-0.45f, 0.27f);
    glVertex2f(-0.45f, 0.28f);

    glColor3ub(0, 0, 0);    //window
    glVertex2f(-0.49f, 0.04f);
    glVertex2f(-0.45f, 0.04f);
    glVertex2f(-0.45f, 0.11f);
    glVertex2f(-0.49f, 0.11f);

    glVertex2f(-0.37f, 0.04f);
    glVertex2f(-0.33f, 0.04f);
    glVertex2f(-0.33f, 0.11f);
    glVertex2f(-0.37f, 0.11f);

    glVertex2f(-0.43f, 0.04f);
    glVertex2f(-0.39f, 0.04f);
    glVertex2f(-0.39f, 0.11f);
    glVertex2f(-0.43f, 0.11f);


    glVertex2f(-0.49f, 0.14f);
    glVertex2f(-0.45f, 0.14f);
    glVertex2f(-0.45f, 0.20f);
    glVertex2f(-0.49f, 0.20f);

    glVertex2f(-0.43f, 0.14f);
    glVertex2f(-0.39f, 0.14f);
    glVertex2f(-0.39f, 0.20f);
    glVertex2f(-0.43f, 0.20f);

    glVertex2f(-0.37f, 0.14f);
    glVertex2f(-0.33f, 0.14f);
    glVertex2f(-0.33f, 0.20f);
    glVertex2f(-0.37f, 0.20f);
    glEnd();


    /*b3 */

    glBegin(GL_QUADS);
    glColor3ub(64,64, 0);
    glVertex2f(-0.29f, 0.0f);
    glVertex2f(-0.11f, 0.0f);
    glVertex2f(-0.11f, 0.27f);
    glVertex2f(-0.29f, 0.27f);


    glColor3ub(123,140,136); //pipe
    glVertex2f(-0.27f, 0.30f);
    glVertex2f(-0.27f, 0.27f);
    glVertex2f(-0.25f, 0.27f);
    glVertex2f(-0.25f, 0.30f);

    glVertex2f(-0.28f, 0.31f); //pipe Cap
    glVertex2f(-0.28f, 0.30f);
    glVertex2f(-0.24f, 0.30f);
    glVertex2f(-0.24f, 0.31f);

    glColor3ub(46,117,182);          // left 1
    glVertex2f(-0.28f, 0.03f);
    glVertex2f(-0.24f, 0.03f);
    glVertex2f(-0.24f, 0.09f);
    glVertex2f(-0.28f, 0.09f);

    glVertex2f(-0.28f, 0.11f);     //left 02
    glVertex2f(-0.24f, 0.11f);
    glVertex2f(-0.24f, 0.17f);
    glVertex2f(-0.28f, 0.17f);

    glVertex2f(-0.28f, 0.19f);  //left 03
    glVertex2f(-0.24f, 0.19f);
    glVertex2f(-0.24f, 0.25f);
    glVertex2f(-0.28f, 0.25f);

    glVertex2f(-0.22f, 0.03f);
    glVertex2f(-0.18f, 0.03f);
    glVertex2f(-0.18f, 0.09f);
    glVertex2f(-0.22f, 0.09f);

    glVertex2f(-0.22f, 0.11f);
    glVertex2f(-0.18f, 0.11f);
    glVertex2f(-0.18f, 0.17f);
    glVertex2f(-0.22f, 0.17f);

    glVertex2f(-0.22f, 0.19f);
    glVertex2f(-0.18f, 0.19f);
    glVertex2f(-0.18f, 0.25f);
    glVertex2f(-0.22f, 0.25f);

    glVertex2f(-0.16f, 0.03f);
    glVertex2f(-0.12f, 0.03f);
    glVertex2f(-0.12f, 0.09f);
    glVertex2f(-0.16f, 0.09f);

    glVertex2f(-0.16f, 0.11f);
    glVertex2f(-0.12f, 0.11f);
    glVertex2f(-0.12f, 0.17f);
    glVertex2f(-0.16f, 0.17f);

    glVertex2f(-0.16f, 0.19f);
    glVertex2f(-0.12f, 0.19f);
    glVertex2f(-0.12f, 0.25f);
    glVertex2f(-0.16f, 0.25f);
    glEnd();

//**right side

//**b4

    glBegin(GL_QUADS);
    glColor3ub(34, 32, 0);
    glVertex2f(0.64f, 0.0f);
    glVertex2f(0.52f, 0.0f);
    glVertex2f(0.52f, 0.22f);
    glVertex2f(0.64f, 0.22f);

    glColor3ub(123,140,136); //pipe
    glVertex2f(0.62f, 0.22f);
    glVertex2f(0.62f, 0.24f);
    glVertex2f(0.60f, 0.24f);
    glVertex2f(0.60f, 0.22f);

    glVertex2f(0.63f, 0.25f); //pipe Cap
    glVertex2f(0.63f, 0.24f);
    glVertex2f(0.59f, 0.24f);
    glVertex2f(0.59f, 0.25f);

    glColor3ub(0, 33, 51);         //window
    glVertex2f(0.63f, 0.04f);
    glVertex2f(0.59f, 0.04f);
    glVertex2f(0.59f, 0.09f);
    glVertex2f(0.63f, 0.09f);

    glVertex2f(0.63f, 0.12f);
    glVertex2f(0.59f, 0.12f);
    glVertex2f(0.59f, 0.17f);
    glVertex2f(0.63f, 0.17f);

    glVertex2f(0.57f, 0.04f);
    glVertex2f(0.53f, 0.04f);
    glVertex2f(0.53f, 0.09f);
    glVertex2f(0.57f, 0.09f);

    glVertex2f(0.57f, 0.12f);
    glVertex2f(0.53f, 0.12f);
    glVertex2f(0.53f, 0.17f);
    glVertex2f(0.57f, 0.17f);
    glEnd();

    //***b5
    glBegin(GL_QUADS);
    glColor3ub(28, 14, 0);
    glVertex2f(0.50f, 0.0f);
    glVertex2f(0.32f, 0.0f);
    glVertex2f(0.32f, 0.24f);
    glVertex2f(0.50f, 0.24f);

    glColor3ub(123,140,136); //pipe
    glVertex2f(0.48f, 0.24f);
    glVertex2f(0.48f, 0.27f);
    glVertex2f(0.46f, 0.27f);
    glVertex2f(0.46f, 0.24f);

    glVertex2f(0.49f, 0.28f); //pipe Cap
    glVertex2f(0.49f, 0.27f);
    glVertex2f(0.45f, 0.27f);
    glVertex2f(0.45f, 0.28f);

    glColor3ub(56, 0, 77);              // window
    glVertex2f(0.49f, 0.04f);
    glVertex2f(0.45f, 0.04f);
    glVertex2f(0.45f, 0.11f);
    glVertex2f(0.49f, 0.11f);

    glVertex2f(0.37f, 0.04f);
    glVertex2f(0.33f, 0.04f);
    glVertex2f(0.33f, 0.11f);
    glVertex2f(0.37f, 0.11f);

    glVertex2f(0.43f, 0.04f);
    glVertex2f(0.39f, 0.04f);
    glVertex2f(0.39f, 0.11f);
    glVertex2f(0.43f, 0.11f);

    glVertex2f(0.49f, 0.14f);
    glVertex2f(0.45f, 0.14f);
    glVertex2f(0.45f, 0.20f);
    glVertex2f(0.49f, 0.20f);

    glVertex2f(0.43f, 0.14f);
    glVertex2f(0.39f, 0.14f);
    glVertex2f(0.39f, 0.20f);
    glVertex2f(0.43f, 0.20f);

    glVertex2f(0.37f, 0.14f);
    glVertex2f(0.33f, 0.14f);
    glVertex2f(0.33f, 0.20f);
    glVertex2f(0.37f, 0.20f);
    glEnd();

//**b6

    glBegin(GL_QUADS);
    glColor3ub(0, 34, 51);
    glVertex2f(0.29f, 0.0f);
    glVertex2f(0.11f, 0.0f);
    glVertex2f(0.11f, 0.27f);
    glVertex2f(0.29f, 0.27f);

    glColor3ub(123,140,136); //pipe
    glVertex2f(0.27f, 0.30f);
    glVertex2f(0.27f, 0.27f);
    glVertex2f(0.25f, 0.27f);
    glVertex2f(0.25f, 0.30f);

    glVertex2f(0.28f, 0.31f); //pipe Cap
    glVertex2f(0.28f, 0.30f);
    glVertex2f(0.24f, 0.30f);
    glVertex2f(0.24f, 0.31f);

    glColor3ub(204, 51, 0);          // left 1
    glVertex2f(0.28f, 0.03f);
    glVertex2f(0.24f, 0.03f);
    glVertex2f(0.24f, 0.09f);
    glVertex2f(0.28f, 0.09f);

    glVertex2f(0.28f, 0.11f);     //left 02
    glVertex2f(0.24f, 0.11f);
    glVertex2f(0.24f, 0.17f);
    glVertex2f(0.28f, 0.17f);

    glVertex2f(0.28f, 0.19f);  //left 03
    glVertex2f(0.24f, 0.19f);
    glVertex2f(0.24f, 0.25f);
    glVertex2f(0.28f, 0.25f);

    glVertex2f(0.22f, 0.03f);
    glVertex2f(0.18f, 0.03f);
    glVertex2f(0.18f, 0.09f);
    glVertex2f(0.22f, 0.09f);

    glVertex2f(0.22f, 0.11f);
    glVertex2f(0.18f, 0.11f);
    glVertex2f(0.18f, 0.17f);
    glVertex2f(0.22f, 0.17f);

    glVertex2f(0.22f, 0.19f);
    glVertex2f(0.18f, 0.19f);
    glVertex2f(0.18f, 0.25f);
    glVertex2f(0.22f, 0.25f);

    glVertex2f(0.16f, 0.03f);
    glVertex2f(0.12f, 0.03f);
    glVertex2f(0.12f, 0.09f);
    glVertex2f(0.16f, 0.09f);

    glVertex2f(0.16f, 0.11f);
    glVertex2f(0.12f, 0.11f);
    glVertex2f(0.12f, 0.17f);
    glVertex2f(0.16f, 0.17f);

    glVertex2f(0.16f, 0.19f);
    glVertex2f(0.12f, 0.19f);
    glVertex2f(0.12f, 0.25f);
    glVertex2f(0.16f, 0.25f);
    glEnd();

    /* end of building */
}



void houseStair()
{

    /* b1 */
    glBegin(GL_QUADS);
    glColor3ub(0, 50, 77);
    glVertex2f(-0.64f, 0.0f);
    glVertex2f(-0.64f, -0.02f);
    glVertex2f(-0.52f, -0.02f);
    glVertex2f(-0.52f, 0.0f);

    glColor3ub(0, 149, 230);
    glVertex2f(-0.64f, -0.02f);
    glVertex2f(-0.64f, -0.03f);
    glVertex2f(-0.52f, -0.03f);
    glVertex2f(-0.52f, -0.02f);

    /*b2 */
    glColor3ub(0, 50, 77);
    glVertex2f(-0.50f, 0.0f);
    glVertex2f(-0.32f, 0.0f);
    glVertex2f(-0.32f, -0.02f);
    glVertex2f(-0.50f, -0.02f);

    glColor3ub(0, 149, 230);
    glVertex2f(-0.50f, -0.02f);
    glVertex2f(-0.32f, -0.02f);
    glVertex2f(-0.32f, -0.03f);
    glVertex2f(-0.50f, -0.03f);

    /*b3 */
    //change
    glColor3ub(0, 50, 77);
    glVertex2f(-0.29f, 0.0f);
    glVertex2f(-0.17f, 0.0f);
    glVertex2f(-0.17f, -0.02f);
    glVertex2f(-0.29f, -0.02f);

    glColor3ub(0, 149, 230);
    glVertex2f(-0.29f, -0.02f);
    glVertex2f(-0.17f, -0.02f);
    glVertex2f(-0.17f, -0.03f);
    glVertex2f(-0.29f, -0.03f);

    //**b4
    glColor3ub(179, 204, 230);
    glVertex2f(0.64f, 0.0f);
    glVertex2f(0.52f, 0.0f);
    glVertex2f(0.52f, -0.02f);
    glVertex2f(0.64f, -0.02f);

    glColor3ub(0, 149, 230);
    glVertex2f(0.64f, -0.02f);
    glVertex2f(0.52f, -0.02f);
    glVertex2f(0.52f, -0.03f);
    glVertex2f(0.64f, -0.03f);

    //***b5
    glColor3ub(0, 102, 153);
    glVertex2f(0.50f, 0.0f);
    glVertex2f(0.32f, 0.0f);
    glVertex2f(0.32f, -0.02f);
    glVertex2f(0.50f, -0.02f);

    glColor3ub(0, 149, 230);
    glVertex2f(0.50f, -0.02f);
    glVertex2f(0.32f, -0.02f);
    glVertex2f(0.32f, -0.03f);
    glVertex2f(0.50f, -0.03f);

    //**b6
    //chang
    glColor3ub(0, 102, 153);
    glVertex2f(0.29f, 0.0f);
    glVertex2f(0.17f, 0.0f);
    glVertex2f(0.17f, -0.02f);
    glVertex2f(0.29f, -0.02f);

    glColor3ub(0, 149, 230);
    glVertex2f(0.29f, -0.02f);
    glVertex2f(0.17f, -0.02f);
    glVertex2f(0.17f, -0.03f);
    glVertex2f(0.29f, -0.03f);
    glEnd();

}

void grass()
{

    /* grass part */
    glBegin(GL_QUADS);
    glColor3ub(0, 204, 0);
    glVertex2f(-0.64f,0.0f);
    glVertex2f(0.64f,0.0f);
    glVertex2f(0.64f,-0.12f);
    glVertex2f(-0.64f,-0.12f);
    glEnd();
    /*end of grass part */
}


void grassN()
{

    /* grass part */
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 51);
    glVertex2f(-0.64f,0.0f);
    glVertex2f(0.64f,0.0f);
    glVertex2f(0.64f,-0.12f);
    glVertex2f(-0.64f,-0.12f);
    glEnd();
    /*end of grass part */
}





void tree()
{

    /*starting Tree */

    glBegin(GL_QUADS);
    glColor3ub(92, 92, 61);
    glVertex2f(-0.05f,-0.01f);
    glVertex2f(-0.03f,-0.01f);
    glVertex2f(-0.03f,0.24f);
    glVertex2f(-0.05f,0.24f);
    glEnd();


    glLineWidth(8);
    glBegin(GL_LINES);        //left
    glColor3ub(92, 92, 61);
    glVertex2f(-0.04f, 0.23f);
    glVertex2f(-0.09f, 0.27f);

    glVertex2f(-0.04f, 0.23f);    //right
    glVertex2f(0.01f, 0.27f);

    glVertex2f(-0.04f, 0.24f);     //middle
    glVertex2f(-0.04f, 0.32f);
    glEnd();

    glColor3ub(0, 102, 0);
    circleSolid(-0.10f, 0.28f, 0.03);  //1
    glColor3ub(0, 204, 0);
    circleSolid(-0.11f, 0.31f, 0.03);         //2
    glColor3ub(0, 153, 51);
    circleSolid(-0.09f, 0.33f, 0.03);         //3

    glColor3ub( 0, 153, 0);

    circleSolid(-0.04f, 0.33f, 0.03);      //4

    circleSolid(0.0f, 0.33f, 0.03);     //5

    circleSolid(0.02f, 0.31f, 0.03);        //6

    glColor3ub( 0, 77, 0 );
    circleSolid(0.03f, 0.28f, 0.03);      //7





    /*End of  Tree */
}




void treeN()
{

    /*starting Tree */

    glBegin(GL_QUADS);
    glColor3ub(17, 51, 61);
    glVertex2f(-0.05f,-0.01f);
    glVertex2f(-0.03f,-0.01f);
    glVertex2f(-0.03f,0.24f);
    glVertex2f(-0.05f,0.24f);
    glEnd();


    glLineWidth(8);
    glBegin(GL_LINES);        //left
    glColor3ub(92, 92, 61);
    glVertex2f(-0.04f, 0.23f);
    glVertex2f(-0.09f, 0.27f);

    glVertex2f(-0.04f, 0.23f);    //right
    glVertex2f(0.01f, 0.27f);

    glVertex2f(-0.04f, 0.24f);     //middle
    glVertex2f(-0.04f, 0.32f);
    glEnd();

    glColor3ub(0, 102, 0);
    circleSolid(-0.10f, 0.28f, 0.03);  //1
    glColor3ub(0, 204, 0);
    circleSolid(-0.11f, 0.31f, 0.03);         //2
    glColor3ub(0, 153, 51);
    circleSolid(-0.09f, 0.33f, 0.03);         //3

    glColor3ub( 0, 153, 0);

    circleSolid(-0.04f, 0.33f, 0.03);      //4


    circleSolid(0.0f, 0.33f, 0.03);     //5

    circleSolid(0.02f, 0.31f, 0.03);        //6

    glColor3ub( 0, 77, 0 );
    circleSolid(0.03f, 0.28f, 0.03);      //7





    /*End of  Tree */
}

void bench(){
    glLineWidth(5.0);
    glBegin(GL_LINES);

    glColor3ub(214,171,119);
    glVertex2f(-0.01f,0.04f);
     glVertex2f(0.06f,0.04f);
     glEnd();

     glBegin(GL_LINES);

    glColor3ub(214,171,119);
    glVertex2f(-0.01f,0.0f);
     glVertex2f(-0.01f,0.04f);
     glEnd();

     glBegin(GL_LINES);

   glColor3ub(214,171,119);
    glVertex2f(0.06f,0.0f);
     glVertex2f(0.06f,0.04f);
     glEnd();


}





void roadside()
{

    /* Road Side */
    glBegin(GL_QUADS);
    glColor3ub(161,161,161); //white
    glVertex2f(-0.64f,-0.13f);
    glVertex2f(-0.64f,-0.12f);
    glVertex2f(-0.54f,-0.12f);
    glVertex2f(-0.54f,-0.13f);

    glColor3ub(0,0,0);                //black
    glVertex2f(-0.54f,-0.13f);
    glVertex2f(-0.54f,-0.12f);
    glVertex2f(-0.44f,-0.12f);
    glVertex2f(-0.44f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(-0.44f,-0.13f);
    glVertex2f(-0.44f,-0.12f);
    glVertex2f(-0.34f,-0.12f);
    glVertex2f(-0.34f,-0.13f);

    glColor3ub(0,0,0);
    glVertex2f(-0.34f,-0.13f);
    glVertex2f(-0.34f,-0.12f);
    glVertex2f(-0.24f,-0.12f);
    glVertex2f(-0.24f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(-0.24f,-0.13f);
    glVertex2f(-0.24f,-0.12f);
    glVertex2f(-0.14f,-0.12f);
    glVertex2f(-0.14f,-0.13f);

    glColor3ub(0,0,0);
    glVertex2f(-0.14f,-0.13f);
    glVertex2f(-0.14f,-0.12f);
    glVertex2f(-0.04f,-0.12f);
    glVertex2f(-0.04f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(-0.04f,-0.13f);
    glVertex2f(-0.04f,-0.12f);
    glVertex2f(0.06f,-0.12f);
    glVertex2f(0.06f,-0.13f);

    glColor3ub(161,161,161); //white
    glVertex2f(0.64f,-0.13f);
    glVertex2f(0.64f,-0.12f);
    glVertex2f(0.54f,-0.12f);
    glVertex2f(0.54f,-0.13f);

    glColor3ub(0,0,0);                //black
    glVertex2f(0.54f,-0.13f);
    glVertex2f(0.54f,-0.12f);
    glVertex2f(0.44f,-0.12f);
    glVertex2f(0.44f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(0.44f,-0.13f);
    glVertex2f(0.44f,-0.12f);
    glVertex2f(0.34f,-0.12f);
    glVertex2f(0.34f,-0.13f);

    glColor3ub(0,0,0);
    glVertex2f(0.34f,-0.13f);
    glVertex2f(0.34f,-0.12f);
    glVertex2f(0.24f,-0.12f);
    glVertex2f(0.24f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(0.24f,-0.13f);
    glVertex2f(0.24f,-0.12f);
    glVertex2f(0.14f,-0.12f);
    glVertex2f(0.14f,-0.13f);

    glColor3ub(0,0,0);
    glVertex2f(0.14f,-0.13f);
    glVertex2f(0.14f,-0.12f);
    glVertex2f(0.04f,-0.12f);
    glVertex2f(0.04f,-0.13f);

    glColor3ub(161,161,161);
    glVertex2f(0.04f,-0.13f);
    glVertex2f(0.04f,-0.12f);
    glVertex2f(0.06f,-0.12f);
    glVertex2f(0.06f,-0.13f);

    glEnd();

///* End of Road Side */



}

void railing()
{

    /*starting Railing */
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);        //red part
    glVertex2f(-0.64f,-0.09f);
    glVertex2f(0.64f,-0.09f);


    glColor3ub(146, 208, 80);    //green part
    glVertex2f(-0.62f,-0.09f);
    glVertex2f(-0.62f,-0.12f);

    glVertex2f(-0.60f,-0.09f);
    glVertex2f(-0.60f,-0.12f);

    glVertex2f(-0.58f,-0.09f);
    glVertex2f(-0.58f,-0.12f);

    glVertex2f(-0.56f,-0.09f);
    glVertex2f(-0.56f,-0.12f);

    glVertex2f(-0.54f,-0.09f);
    glVertex2f(-0.54f,-0.12f);

    glVertex2f(-0.52f,-0.09f);
    glVertex2f(-0.52f,-0.12f);

    glVertex2f(-0.50f,-0.09f);
    glVertex2f(-0.50f,-0.12f);

    glVertex2f(-0.48f,-0.09f);
    glVertex2f(-0.48f,-0.12f);

    glVertex2f(-0.46f,-0.09f);
    glVertex2f(-0.46f,-0.12f);

    glVertex2f(-0.44f,-0.09f);
    glVertex2f(-0.44f,-0.12f);

    glVertex2f(-0.42f,-0.09f);
    glVertex2f(-0.42f,-0.12f);

    glVertex2f(-0.40f,-0.09f);
    glVertex2f(-0.40f,-0.12f);

    glVertex2f(-0.38f,-0.09f);
    glVertex2f(-0.38f,-0.12f);

    glVertex2f(-0.36f,-0.09f);
    glVertex2f(-0.36f,-0.12f);

    glVertex2f(-0.34f,-0.09f);
    glVertex2f(-0.34f,-0.12f);

    glVertex2f(-0.32f,-0.09f);
    glVertex2f(-0.32f,-0.12f);

    glVertex2f(-0.30f,-0.09f);
    glVertex2f(-0.30f,-0.12f);

    glVertex2f(-0.28f,-0.09f);
    glVertex2f(-0.28f,-0.12f);

    glVertex2f(-0.26f,-0.09f);
    glVertex2f(-0.26f,-0.12f);

    glVertex2f(-0.24f,-0.09f);
    glVertex2f(-0.24f,-0.12f);

    glVertex2f(-0.22f,-0.09f);
    glVertex2f(-0.22f,-0.12f);

    glVertex2f(-0.20f,-0.09f);
    glVertex2f(-0.20f,-0.12f);

    glVertex2f(-0.18f,-0.09f);
    glVertex2f(-0.18f,-0.12f);

    glVertex2f(-0.16f,-0.09f);
    glVertex2f(-0.16f,-0.12f);

    glVertex2f(-0.14f,-0.09f);
    glVertex2f(-0.14f,-0.12f);

    glVertex2f(-0.12,-0.09f);
    glVertex2f(-0.12f,-0.12f);

    glVertex2f(-0.10f,-0.09f);
    glVertex2f(-0.10f,-0.12f);

    glVertex2f(-0.08f,-0.09f);
    glVertex2f(-0.08f,-0.12f);

    glVertex2f(-0.06f,-0.09f);
    glVertex2f(-0.06f,-0.12f);

    glVertex2f(-0.04f,-0.09f);
    glVertex2f(-0.04f,-0.12f);

    glVertex2f(-0.09f,-0.09f);
    glVertex2f(-0.09f,-0.12f);

    glVertex2f(0.00f,-0.09f);
    glVertex2f(0.00f,-0.12f);

    glVertex2f(-0.09f,-0.09f);
    glVertex2f(-0.09f,-0.12f);

    glVertex2f(0.04f,-0.09f);
    glVertex2f(0.04f,-0.12f);

    glVertex2f(0.06f,-0.09f);
    glVertex2f(0.06f,-0.12f);

    glVertex2f(0.08f,-0.09f);
    glVertex2f(0.08f,-0.12f);

    glVertex2f(0.10f,-0.09f);
    glVertex2f(0.10f,-0.12f);

    glVertex2f(0.12f,-0.09f);
    glVertex2f(0.12f,-0.12f);

    glVertex2f(0.14f,-0.09f);
    glVertex2f(0.14f,-0.12f);

    glVertex2f(0.16f,-0.09f);
    glVertex2f(0.16f,-0.12f);

    glVertex2f(0.18f,-0.09f);
    glVertex2f(0.18f,-0.12f);

    glVertex2f(0.20f,-0.09f);
    glVertex2f(0.20f,-0.12f);

    glVertex2f(0.22f,-0.09f);
    glVertex2f(0.22f,-0.12f);

    glVertex2f(0.24f,-0.09f);
    glVertex2f(0.24f,-0.12f);

    glVertex2f(0.26f,-0.09f);
    glVertex2f(0.26f,-0.12f);

    glVertex2f(0.28f,-0.09f);
    glVertex2f(0.28f,-0.12f);

    glVertex2f(0.30f,-0.09f);
    glVertex2f(0.30f,-0.12f);

    glVertex2f(0.32f,-0.09f);
    glVertex2f(0.32f,-0.12f);

    glVertex2f(0.34f,-0.09f);
    glVertex2f(0.34f,-0.12f);

    glVertex2f(0.36f,-0.09f);
    glVertex2f(0.36f,-0.12f);

    glVertex2f(0.38f,-0.09f);
    glVertex2f(0.38f,-0.12f);

    glVertex2f(0.40f,-0.09f);
    glVertex2f(0.40f,-0.12f);

    glVertex2f(0.42f,-0.09f);
    glVertex2f(0.42f,-0.12f);

    glVertex2f(0.44f,-0.09f);
    glVertex2f(0.44f,-0.12f);

    glVertex2f(0.46f,-0.09f);
    glVertex2f(0.46f,-0.12f);

    glVertex2f(0.48f,-0.09f);
    glVertex2f(0.48f,-0.12f);

    glVertex2f(0.50f,-0.09f);
    glVertex2f(0.50f,-0.12f);

    glVertex2f(0.52f,-0.09f);
    glVertex2f(0.52f,-0.12f);

    glVertex2f(0.54f,-0.09f);
    glVertex2f(0.54f,-0.12f);

    glVertex2f(0.56f,-0.09f);
    glVertex2f(0.56f,-0.12f);

    glVertex2f(0.58f,-0.09f);
    glVertex2f(0.58f,-0.12f);

    glVertex2f(0.60f,-0.09f);
    glVertex2f(0.60f,-0.12f);

    glVertex2f(0.62f,-0.09f);
    glVertex2f(0.62f,-0.12f);

    glVertex2f(0.64f,-0.09f);
    glVertex2f(0.64f,-0.12f);

    glEnd();

}





void railingN()
{

    /*starting Railing */
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(179, 0, 0);        //red part
    glVertex2f(-0.64f,-0.09f);
    glVertex2f(0.64f,-0.09f);


    glColor3ub(146, 208, 80);    //green part
    glVertex2f(-0.62f,-0.09f);
    glVertex2f(-0.62f,-0.12f);

    glVertex2f(-0.60f,-0.09f);
    glVertex2f(-0.60f,-0.12f);

    glVertex2f(-0.58f,-0.09f);
    glVertex2f(-0.58f,-0.12f);

    glVertex2f(-0.56f,-0.09f);
    glVertex2f(-0.56f,-0.12f);

    glVertex2f(-0.54f,-0.09f);
    glVertex2f(-0.54f,-0.12f);

    glVertex2f(-0.52f,-0.09f);
    glVertex2f(-0.52f,-0.12f);

    glVertex2f(-0.50f,-0.09f);
    glVertex2f(-0.50f,-0.12f);

    glVertex2f(-0.48f,-0.09f);
    glVertex2f(-0.48f,-0.12f);

    glVertex2f(-0.46f,-0.09f);
    glVertex2f(-0.46f,-0.12f);

    glVertex2f(-0.44f,-0.09f);
    glVertex2f(-0.44f,-0.12f);

    glVertex2f(-0.42f,-0.09f);
    glVertex2f(-0.42f,-0.12f);

    glVertex2f(-0.40f,-0.09f);
    glVertex2f(-0.40f,-0.12f);

    glVertex2f(-0.38f,-0.09f);
    glVertex2f(-0.38f,-0.12f);

    glVertex2f(-0.36f,-0.09f);
    glVertex2f(-0.36f,-0.12f);

    glVertex2f(-0.34f,-0.09f);
    glVertex2f(-0.34f,-0.12f);

    glVertex2f(-0.32f,-0.09f);
    glVertex2f(-0.32f,-0.12f);

    glVertex2f(-0.30f,-0.09f);
    glVertex2f(-0.30f,-0.12f);

    glVertex2f(-0.28f,-0.09f);
    glVertex2f(-0.28f,-0.12f);

    glVertex2f(-0.26f,-0.09f);
    glVertex2f(-0.26f,-0.12f);

    glVertex2f(-0.24f,-0.09f);
    glVertex2f(-0.24f,-0.12f);

    glVertex2f(-0.22f,-0.09f);
    glVertex2f(-0.22f,-0.12f);

    glVertex2f(-0.20f,-0.09f);
    glVertex2f(-0.20f,-0.12f);

    glVertex2f(-0.18f,-0.09f);
    glVertex2f(-0.18f,-0.12f);

    glVertex2f(-0.16f,-0.09f);
    glVertex2f(-0.16f,-0.12f);

    glVertex2f(-0.14f,-0.09f);
    glVertex2f(-0.14f,-0.12f);

    glVertex2f(-0.12,-0.09f);
    glVertex2f(-0.12f,-0.12f);

    glVertex2f(-0.10f,-0.09f);
    glVertex2f(-0.10f,-0.12f);

    glVertex2f(-0.08f,-0.09f);
    glVertex2f(-0.08f,-0.12f);

    glVertex2f(-0.06f,-0.09f);
    glVertex2f(-0.06f,-0.12f);

    glVertex2f(-0.04f,-0.09f);
    glVertex2f(-0.04f,-0.12f);

    glVertex2f(-0.09f,-0.09f);
    glVertex2f(-0.09f,-0.12f);

    glVertex2f(0.00f,-0.09f);
    glVertex2f(0.00f,-0.12f);

    glVertex2f(-0.09f,-0.09f);
    glVertex2f(-0.09f,-0.12f);

    glVertex2f(0.04f,-0.09f);
    glVertex2f(0.04f,-0.12f);

    glVertex2f(0.06f,-0.09f);
    glVertex2f(0.06f,-0.12f);

    glVertex2f(0.08f,-0.09f);
    glVertex2f(0.08f,-0.12f);

    glVertex2f(0.10f,-0.09f);
    glVertex2f(0.10f,-0.12f);

    glVertex2f(0.12f,-0.09f);
    glVertex2f(0.12f,-0.12f);

    glVertex2f(0.14f,-0.09f);
    glVertex2f(0.14f,-0.12f);

    glVertex2f(0.16f,-0.09f);
    glVertex2f(0.16f,-0.12f);

    glVertex2f(0.18f,-0.09f);
    glVertex2f(0.18f,-0.12f);

    glVertex2f(0.20f,-0.09f);
    glVertex2f(0.20f,-0.12f);

    glVertex2f(0.22f,-0.09f);
    glVertex2f(0.22f,-0.12f);

    glVertex2f(0.24f,-0.09f);
    glVertex2f(0.24f,-0.12f);

    glVertex2f(0.26f,-0.09f);
    glVertex2f(0.26f,-0.12f);

    glVertex2f(0.28f,-0.09f);
    glVertex2f(0.28f,-0.12f);

    glVertex2f(0.30f,-0.09f);
    glVertex2f(0.30f,-0.12f);

    glVertex2f(0.32f,-0.09f);
    glVertex2f(0.32f,-0.12f);

    glVertex2f(0.34f,-0.09f);
    glVertex2f(0.34f,-0.12f);

    glVertex2f(0.36f,-0.09f);
    glVertex2f(0.36f,-0.12f);

    glVertex2f(0.38f,-0.09f);
    glVertex2f(0.38f,-0.12f);

    glVertex2f(0.40f,-0.09f);
    glVertex2f(0.40f,-0.12f);

    glVertex2f(0.42f,-0.09f);
    glVertex2f(0.42f,-0.12f);

    glVertex2f(0.44f,-0.09f);
    glVertex2f(0.44f,-0.12f);

    glVertex2f(0.46f,-0.09f);
    glVertex2f(0.46f,-0.12f);

    glVertex2f(0.48f,-0.09f);
    glVertex2f(0.48f,-0.12f);

    glVertex2f(0.50f,-0.09f);
    glVertex2f(0.50f,-0.12f);

    glVertex2f(0.52f,-0.09f);
    glVertex2f(0.52f,-0.12f);

    glVertex2f(0.54f,-0.09f);
    glVertex2f(0.54f,-0.12f);

    glVertex2f(0.56f,-0.09f);
    glVertex2f(0.56f,-0.12f);

    glVertex2f(0.58f,-0.09f);
    glVertex2f(0.58f,-0.12f);

    glVertex2f(0.60f,-0.09f);
    glVertex2f(0.60f,-0.12f);

    glVertex2f(0.62f,-0.09f);
    glVertex2f(0.62f,-0.12f);

    glVertex2f(0.64f,-0.09f);
    glVertex2f(0.64f,-0.12f);

    glEnd();

}






void lamppost()
{
    /* starting LampPost  */
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 204); //Bar
    glVertex2f(0.09f,-0.12f);
    glVertex2f(0.08f,-0.12f);
    glVertex2f(0.08f,0.17f);
    glVertex2f(0.09f,0.17f);

    glColor3ub(255, 255, 204); //upSide
    glVertex2f(0.09f,0.17f);
    glVertex2f(0.09f,0.15f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.00f,0.22f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);
    glVertex2f(0.04f,0.18f);
    glVertex2f(0.04f,0.16f);
    glVertex2f(0.00f,0.18f);
    glVertex2f(0.00f,0.20f);
    glEnd();


    /* starting LampPost  2  */
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 204); //Bar
    glVertex2f(-0.14f,-0.12f);
    glVertex2f(-0.13f,-0.12f);
    glVertex2f(-0.13f,0.17f);
    glVertex2f(-0.14f,0.17f);

    glColor3ub(255, 255, 204); //upSide
    glVertex2f(0.14f,0.17f);
    glVertex2f(0.13f,0.15f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.00f,0.22f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);
    glVertex2f(0.09f,0.18f);
    glVertex2f(0.09f,0.16f);
    glVertex2f(0.00f,0.18f);
    glVertex2f(0.00f,0.20f);
    glEnd();
    /* End of  LampPost  */


}



void lamppostN()
{
    /* starting LampPost  */
    glBegin(GL_QUADS);
    glColor3ub(186,186,149); //Bar
    glVertex2f(0.09f,-0.12f);
    glVertex2f(0.08f,-0.12f);
    glVertex2f(0.08f,0.17f);
    glVertex2f(0.09f,0.17f);

    glColor3ub(186,186,149); //upSide
    glVertex2f(0.09f,0.17f);
    glVertex2f(0.09f,0.15f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.00f,0.22f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(0.04f,0.18f);
    glVertex2f(0.04f,0.16f);
    glVertex2f(0.00f,0.18f);
    glVertex2f(0.00f,0.20f);
    glEnd();
    /* End of  LampPost  */
}






void road()
{

    glBegin(GL_QUADS);
    glColor3ub(16, 16, 10);          //color part
    glVertex2f(-0.64f,-0.13f);
    glVertex2f(0.64f,-0.13f);
    glVertex2f(0.64f,-0.58f);
    glVertex2f(-0.64f,-0.58f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); //white
    glVertex2f(-0.64f,-0.32f);
    glVertex2f(-0.64f,-0.34f);
    glVertex2f(-0.54f,-0.34f);
    glVertex2f(-0.54f,-0.32f);

    glVertex2f(-0.44f,-0.32f);
    glVertex2f(-0.44f,-0.34f);
    glVertex2f(-0.34f,-0.34f);
    glVertex2f(-0.34f,-0.32f);

    glVertex2f(-0.24f,-0.32f);
    glVertex2f(-0.24f,-0.34f);
    glVertex2f(-0.14f,-0.34f);
    glVertex2f(-0.14f,-0.32f);

    glVertex2f(-0.04f,-0.32f);
    glVertex2f(-0.04f,-0.34f);
    glVertex2f(0.04f,-0.34f);
    glVertex2f(0.04f,-0.32f);


    glVertex2f(0.64f,-0.32f);
    glVertex2f(0.64f,-0.34f);
    glVertex2f(0.54f,-0.34f);
    glVertex2f(0.54f,-0.32f);

    glVertex2f(0.44f,-0.32f);
    glVertex2f(0.44f,-0.34f);
    glVertex2f(0.34f,-0.34f);
    glVertex2f(0.34f,-0.32f);

    glVertex2f(0.24f,-0.32f);
    glVertex2f(0.24f,-0.34f);
    glVertex2f(0.14f,-0.34f);
    glVertex2f(0.14f,-0.32f);

    glVertex2f(0.04f,-0.32f);
    glVertex2f(0.04f,-0.34f);
    glVertex2f(0.04f,-0.34f);
    glVertex2f(0.04f,-0.32f);
    glEnd();

    /*End of  road white part */
}

void car1()
{
         glPushMatrix();
    glTranslatef(_movecar1,0.0f,0.00f);

    glBegin(GL_POLYGON);
    glColor3ub(139, 0, 200);
    glVertex2f(0.36f,-0.14f);
    glVertex2f(0.36f,-0.16f);
    glVertex2f(0.47f,-0.16f);
    glVertex2f(0.47f,-0.14f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(139, 255, 200);
    glVertex2f(0.38f,-0.12f);
    glVertex2f(0.36f,-0.14f);
    glVertex2f(0.47f,-0.14f);
    glVertex2f(0.47f,-0.12f);
    glEnd();
    glColor3ub(128, 128, 128);///chaka
    circleSolid(0.38f,-0.16f,0.01);
    circleSolid(0.45f,-0.16f,0.01);
    glColor3ub( 255, 255, 255);///chaka
    circleSolid(0.38f,-0.16f,0.006);
    circleSolid(0.45f,-0.16f,0.006);
    ///border
    glBegin(GL_LINES);///borders
    glColor3ub(222,0,0);
    glVertex2f(0.36f,-0.14f);
    glVertex2f(0.47f,-0.14f);
    glEnd();
    glBegin(GL_LINES);///borders
    glColor3ub(222,0,0);
    glVertex2f(0.38f,-0.12f);
    glVertex2f(0.47f,-0.12f);

    glVertex2f(0.38f,-0.12f);
    glVertex2f(0.36f,-0.14f);

    glVertex2f(0.39f,-0.12f);
    glVertex2f(0.39f,-0.16f);

    glVertex2f(0.45f,-0.12f);
    glVertex2f(0.45f,-0.15f);

    glVertex2f(0.47f,-0.12f);
    glVertex2f(0.47f,-0.14f);

    glVertex2f(0.36f,-0.14f);
    glVertex2f(0.47f,-0.14f);
    glEnd();

    glBegin(GL_POLYGON);///light
    glColor3ub(139, 255, 200);
    glVertex2f(0.36f,-0.14f);
    glVertex2f(0.36f,-0.15f);
    glVertex2f(0.37f,-0.15f);
    glVertex2f(0.37f,-0.14f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(0.47f,-0.14f);
    glVertex2f(0.47f,-0.15f);
    glVertex2f(0.46f,-0.15f);
    glVertex2f(0.46f,-0.14f);
    glEnd();
                glPopMatrix();
    glutSwapBuffers();



    /*end of car01 */
}

void car2()
{

//     glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);


     glPushMatrix();
    glTranslatef(_movecar2, 0.0f,0.00f);


    glBegin(GL_POLYGON);
    glColor3ub(25,25,112);

    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.38f, -0.26f);
    glVertex2f(-0.35f, -0.31f);
    glVertex2f(-0.61f, -0.31f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.62f, -0.25f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.55f, -0.19f);
    glVertex2f(-0.45f, -0.19f);
    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.50f, -0.19f);
	glVertex2f(-0.50f, -0.25f);

	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.55f, -0.19f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex2f(-0.55f, -0.19f);
    glVertex2f(-0.45f, -0.19f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex2f(-0.45f, -0.19f);
    glVertex2f(-0.42f, -0.25f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3ub(204,0,0);
	glVertex2f(-0.62f, -0.29f);
    glVertex2f(-0.62f, -0.26f);
	glEnd();

   glColor3ub(0,0,0);
    circleSolid(-0.55f,-0.31f, 0.03);   //2
    glColor3ub(255, 255, 255);
    circleSolid(-0.55f,-0.31f, 0.015);      //2.1

   glColor3ub(0,0,0);
    circleSolid(-0.42f,-0.31f, 0.03);   //2
    glColor3ub(255, 255, 255);
    circleSolid(-0.42f,-0.31f, 0.015);

            glPopMatrix();
    glutSwapBuffers();

}

void car2F()
{

//     glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);


     glPushMatrix();
    glTranslatef(_movecar2, 0.0f,0.00f);


    glBegin(GL_POLYGON);
    glColor3ub(25,25,112);

    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.38f, -0.26f);
    glVertex2f(-0.35f, -0.31f);
    glVertex2f(-0.61f, -0.31f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.62f, -0.25f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.55f, -0.19f);
    glVertex2f(-0.45f, -0.19f);
    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.50f, -0.19f);
	glVertex2f(-0.50f, -0.25f);

	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.55f, -0.19f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex2f(-0.55f, -0.19f);
    glVertex2f(-0.45f, -0.19f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex2f(-0.45f, -0.19f);
    glVertex2f(-0.42f, -0.25f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3ub(204,0,0);
	glVertex2f(-0.62f, -0.29f);
    glVertex2f(-0.62f, -0.26f);
	glEnd();


            glPopMatrix();
    glutSwapBuffers();

}

void truck()
{
//      glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);


     glPushMatrix();
    glTranslatef(_movet1,0.0f,0.00f);



    glBegin(GL_QUADS);
    glColor3ub(0, 122, 204);
    glVertex2f(-0.01f,-0.41f);
    glVertex2f(-0.01f, -0.35f);
    glVertex2f(0.10f, -0.35f);
    glVertex2f(0.10f, -0.41f);
    glEnd();
    // base of the truck

    glBegin(GL_POLYGON);         //shadow
    glColor3ub(51,  51, 0);
    glVertex2f(-0.01f,-0.39f);
    glVertex2f(0.13f, -0.39f);
    glVertex2f(0.13f, -0.41f);
    glVertex2f(-0.01f,-0.41f);
    glEnd();

    glBegin(GL_POLYGON);                 //font
    glColor3ub(153, 153, 0);
    glVertex2f(0.24f, -0.41f);
    glVertex2f(0.11f,-0.41f);
    glVertex2f(0.11f,-0.36f);
    glVertex2f(0.20f,-0.36f);
    glVertex2f(0.24f,-0.40f);
    glVertex2f(0.24f, -0.41f);
    glEnd();


    glBegin(GL_POLYGON);           //  font red part
    glColor3ub(255, 0, 0);
    glVertex2f(0.23f, -0.40f);
    glVertex2f(0.11f,-0.40f);
    glVertex2f(0.11f,-0.37f);
    glVertex2f(0.20f,-0.37f);
    glVertex2f(0.23f,-0.39f);
    glVertex2f(0.23f, -0.40f);
    glEnd();





    glColor3ub(0, 0, 0);
    circleSolid(0.01f,-0.41f, 0.02);   //1

    glColor3ub(255, 255, 255);
    circleSolid(0.01f,-0.41f, 0.01);   //1.1

    glColor3ub(0, 0, 0);
    circleSolid(0.15f,-0.42f, 0.02);   //2
    glColor3ub(255, 255, 255);
    circleSolid(0.15f,-0.42f, 0.01);   //2.1

    glPopMatrix();
    glutSwapBuffers();

}


void truckF()
{
//      glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);


     glPushMatrix();
    glTranslatef(_movet1,0.0f,0.00f);



    glBegin(GL_QUADS);
    glColor3ub(0, 122, 204);
    glVertex2f(-0.01f,-0.41f);
    glVertex2f(-0.01f, -0.35f);
    glVertex2f(0.10f, -0.35f);
    glVertex2f(0.10f, -0.41f);
    glEnd();
    // base of the truck

    glBegin(GL_POLYGON);         //shadow
    glColor3ub(51,  51, 0);
    glVertex2f(-0.01f,-0.39f);
    glVertex2f(0.13f, -0.39f);
    glVertex2f(0.13f, -0.41f);
    glVertex2f(-0.01f,-0.41f);
    glEnd();

    glBegin(GL_POLYGON);                 //font
    glColor3ub(153, 153, 0);
    glVertex2f(0.24f, -0.41f);
    glVertex2f(0.11f,-0.41f);
    glVertex2f(0.11f,-0.36f);
    glVertex2f(0.20f,-0.36f);
    glVertex2f(0.24f,-0.40f);
    glVertex2f(0.24f, -0.41f);
    glEnd();


    glBegin(GL_POLYGON);           //  font red part
    glColor3ub(255, 0, 0);
    glVertex2f(0.23f, -0.40f);
    glVertex2f(0.11f,-0.40f);
    glVertex2f(0.11f,-0.37f);
    glVertex2f(0.20f,-0.37f);
    glVertex2f(0.23f,-0.39f);
    glVertex2f(0.23f, -0.40f);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();

}


void bus()
{

//    glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_moveb1,0.0f,0.00f);
    glBegin(GL_QUADS);
    glColor3ub(0, 204, 0);
    glVertex2f(-0.60f,-0.47f);
    glVertex2f(-0.60f, -0.39f);
    glVertex2f(-0.40f, -0.39f);
    glVertex2f(-0.40f, -0.47f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);

    glVertex2f(-0.60f, -0.42f);
    glVertex2f(-0.45f, -0.42f);

    glVertex2f(-0.45f, -0.42f);
    glVertex2f(-0.40f, -0.41f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.60f, -0.44f);
    glVertex2f(-0.45f, -0.44f);

    glVertex2f(-0.45f, -0.44f);
    glVertex2f(-0.40f, -0.43f);
    glEnd();



    glColor3ub(0, 0, 0); //wheel 1
    circleSolid(-0.465f,-0.475f, 0.02);   //2
    glColor3ub(255, 255, 255);
    circleSolid(-0.465f,-0.475f, 0.01);      //2.1

        glColor3ub(0, 0, 0); //wheel 2
    circleSolid(-0.425f,-0.475f, 0.02);   //2
    glColor3ub(255, 255, 255);
    circleSolid(-0.425f,-0.475f, 0.01);      //2.1

    glColor3ub(0, 0, 0);   //wheel 3
    circleSolid(-0.565f,-0.475f, 0.02);   //2
    glColor3ub(255, 255, 255);
    circleSolid(-0.565f,-0.475f, 0.01);      //2.1

        glColor3ub(0, 0, 0);  //wheel 4
    circleSolid(-0.525f,-0.475f, 0.02);   //2
    glColor3ub(255, 255, 255);
    circleSolid(-0.525f,-0.475f, 0.01);      //2.1

        glPopMatrix();
    glutSwapBuffers();

}


void busF()
{

//    glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_moveb1,0.0f,0.00f);
    glBegin(GL_QUADS);
    glColor3ub(0, 204, 0);
    glVertex2f(-0.60f,-0.47f);
    glVertex2f(-0.60f, -0.39f);
    glVertex2f(-0.40f, -0.39f);
    glVertex2f(-0.40f, -0.47f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);

    glVertex2f(-0.60f, -0.42f);
    glVertex2f(-0.45f, -0.42f);

    glVertex2f(-0.45f, -0.42f);
    glVertex2f(-0.40f, -0.41f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.60f, -0.44f);
    glVertex2f(-0.45f, -0.44f);

    glVertex2f(-0.45f, -0.44f);
    glVertex2f(-0.40f, -0.43f);
    glEnd();

        glPopMatrix();
    glutSwapBuffers();

}


void plane()
{
glPushMatrix();
    glTranslatef(_movePlane,0.0f,0.00f);

    /* base */
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-0.03f,0.55f);
    glVertex2f(-0.20f,0.55f);
    glVertex2f(-0.20f,0.51f);
    glVertex2f(-0.01f,0.51f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.01f,0.51f);
    glVertex2f(-0.03f,0.47f);
    glVertex2f(-0.20f,0.47f);
    glVertex2f(-0.20f,0.51f);
    glEnd();
    /*base */

    /* down turbine*/
        glBegin(GL_POLYGON);
            glColor3ub(204, 255, 51);
    glVertex2f(-0.05f,0.51f);
    glVertex2f(-0.10f,0.51f);
    glVertex2f(-0.12f,0.43f);
    glVertex2f(-0.09f,0.43f);
    glEnd();
        /* up turbine*/
            glBegin(GL_POLYGON);
    glColor3ub(204, 255, 51);
    glVertex2f(-0.06f,0.55f);
    glVertex2f(-0.10f,0.55f);
    glVertex2f(-0.12f,0.59f);
    glVertex2f(-0.10f,0.59f);
    glEnd();
            /* back turbine*/
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.15f,0.55f);
    glVertex2f(-0.20f,0.55f);
    glVertex2f(-0.20f,0.61f);
    glVertex2f(-0.18f,0.61f);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();

}


void fontroad()
{
    /* screen font road */
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 255);   //black part 2axis
    glVertex2f(-0.64f,-0.61f);
    glVertex2f(0.64f,-0.61f);
    glVertex2f(0.64f,-0.64f);
    glVertex2f(-0.64f,-0.64f);

    glColor3ub(0, 204, 0);  //green part 1axis
    glVertex2f(-0.64f,-0.60f);
    glVertex2f(0.64f,-0.60f);
    glVertex2f(0.64f,-0.61f);
    glVertex2f(-0.64f,-0.61f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0); //yellow
    glVertex2f(-0.64f,-0.58f);
    glVertex2f(-0.64f,-0.60f);
    glVertex2f(-0.44f,-0.60f);
    glVertex2f(-0.44f,-0.58f);

    glColor3ub(204, 0, 0); //red
    glVertex2f(-0.44f,-0.58f);
    glVertex2f(-0.44f,-0.60f);
    glVertex2f(-0.24f,-0.60f);
    glVertex2f(-0.24f,-0.58f);

    glColor3ub(255, 255, 0); //yellow
    glVertex2f(-0.24f,-0.58f);
    glVertex2f(-0.24f,-0.60f);
    glVertex2f(-0.04f,-0.60f);
    glVertex2f(-0.04f,-0.58f);

    glColor3ub(204, 0, 0); //yellow
    glVertex2f(-0.04f,-0.58f);
    glVertex2f(-0.04f,-0.60f);
    glVertex2f(0.14f,-0.60f);
    glVertex2f(0.14f,-0.58f);

    glColor3ub(255, 255, 0); //yellow
    glVertex2f(0.14f,-0.58f);
    glVertex2f(0.14f,-0.60f);
    glVertex2f(0.34f,-0.60f);
    glVertex2f(0.34f,-0.58f);

    glColor3ub(204, 0, 0); //red
    glVertex2f(0.34f,-0.58f);
    glVertex2f(0.34f,-0.60f);
    glVertex2f(0.54f,-0.60f);
    glVertex2f(0.54f,-0.58f);

    glColor3ub(255, 255, 0); //yellow
    glVertex2f(0.54f,-0.58f);
    glVertex2f(0.54f,-0.60f);
    glVertex2f(0.64f,-0.60f);
    glVertex2f(0.64f,-0.58f);
    glEnd();
    /*End of  screen font road*/
}



void clouds()
{
glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_moveCloud,0.0f,0.00f);



    glColor3ub( 255, 255, 255);
    circleSolid(0.23f,0.43f,0.04);
    circleSolid(0.21f,0.42f,0.04);
    circleSolid(0.21f,0.40f,0.04);
    circleSolid(0.23f,0.41f,0.04);
    circleSolid(0.19f,0.43f,0.04);
    circleSolid(0.19f,0.40f,0.04);
    circleSolid(0.17f,0.42f,0.04);
    circleSolid(0.18f,0.41f,0.04);
    circleSolid(0.16f,0.41f,0.04);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.43f,0.38f,0.04);
    circleSolid(-0.41f,0.37f,0.04);
    circleSolid(-0.41f,0.36f,0.04);
    circleSolid(-0.43f,0.37f,0.04);
    circleSolid(-0.39f,0.38f,0.04);
    circleSolid(-0.39f,0.36f,0.04);
    circleSolid(-0.37f,0.37f,0.04);
    circleSolid(-0.38f,0.36f,0.04);
    circleSolid(-0.36f,0.37f,0.04);

           glPopMatrix();

     glPushMatrix();
    glTranslatef(_moveCloudleft,0.0f,0.00f);

    glColor3ub( 255, 255, 255);
    circleSolid(0.43f,0.38f,0.04);
    circleSolid(0.41f,0.37f,0.04);
    circleSolid(0.41f,0.36f,0.04);
    circleSolid(0.43f,0.37f,0.04);
    circleSolid(0.39f,0.38f,0.04);
    circleSolid(0.39f,0.36f,0.04);
    circleSolid(0.37f,0.37f,0.04);
    circleSolid(0.38f,0.36f,0.04);
    circleSolid(0.36f,0.37f,0.04);

    glColor3ub( 255, 255, 255);
    circleSolid(-0.13f,0.43f,0.04);
    circleSolid(-0.11f,0.42f,0.04);
    circleSolid(-0.11f,0.40f,0.04);
    circleSolid(-0.13f,0.41f,0.04);
    circleSolid(-0.09f,0.43f,0.04);
    circleSolid(-0.09f,0.40f,0.04);
    circleSolid(-0.07f,0.42f,0.04);
    circleSolid(-0.04f,0.41f,0.04);
    circleSolid(-0.06f,0.41f,0.04);
   glPopMatrix();
    glutSwapBuffers();


}

void cloudsR()
{



glColor3ub( 41, 64, 86);
    circleSolid(0.23f,0.43f,0.04);
    circleSolid(0.21f,0.42f,0.04);
    circleSolid(0.21f,0.40f,0.04);
    circleSolid(0.23f,0.41f,0.04);
    circleSolid(0.19f,0.43f,0.04);
    circleSolid(0.19f,0.40f,0.04);
    circleSolid(0.17f,0.42f,0.04);
    circleSolid(0.18f,0.41f,0.04);
    circleSolid(0.16f,0.41f,0.04);

    glColor3ub( 41, 64, 86);
    circleSolid(-0.43f,0.38f,0.04);
    circleSolid(-0.41f,0.37f,0.04);
    circleSolid(-0.41f,0.36f,0.04);
    circleSolid(-0.43f,0.37f,0.04);
    circleSolid(-0.39f,0.38f,0.04);
    circleSolid(-0.39f,0.36f,0.04);
    circleSolid(-0.37f,0.37f,0.04);
    circleSolid(-0.38f,0.36f,0.04);
    circleSolid(-0.36f,0.37f,0.04);

    glColor3ub( 41, 64, 86);
    circleSolid(0.43f,0.38f,0.04);
    circleSolid(0.41f,0.37f,0.04);
    circleSolid(0.41f,0.36f,0.04);
    circleSolid(0.43f,0.37f,0.04);
    circleSolid(0.39f,0.38f,0.04);
    circleSolid(0.39f,0.36f,0.04);
    circleSolid(0.37f,0.37f,0.04);
    circleSolid(0.38f,0.36f,0.04);
    circleSolid(0.36f,0.37f,0.04);

    glColor3ub( 41, 64, 86);
    circleSolid(-0.13f,0.43f,0.04);
    circleSolid(-0.11f,0.42f,0.04);
    circleSolid(-0.11f,0.40f,0.04);
    circleSolid(-0.13f,0.41f,0.04);
    circleSolid(-0.09f,0.43f,0.04);
    circleSolid(-0.09f,0.40f,0.04);
    circleSolid(-0.07f,0.42f,0.04);
    circleSolid(-0.04f,0.41f,0.04);
    circleSolid(-0.06f,0.41f,0.04);


}




void objects()
{



     glPushMatrix();
    glTranslatef(_moveObject,0.0f,0.00f);

    glBegin(GL_QUADS);
    glColor3ub(92, 90, 59);
    glVertex2f(-0.50f,-0.40f);
    glVertex2f(-0.48f,-0.43f);
    glVertex2f(-0.37f,- 0.28f);
    glVertex2f(-0.41f, -0.27f);
     glEnd();
 ///start

glBegin(GL_POLYGON);
    glColor3ub(92, 90, 59);
    glVertex2f(-0.31f,-0.24f);
    glVertex2f(-0.31f,-0.26f);
    glVertex2f(-0.15f,- 0.26f);
    glVertex2f(-0.15f, -0.24f);
    glVertex2f(-0.24f,-0.20f);
    glVertex2f(-0.21f,-0.20f);
     glEnd();
    glColor3ub(92, 90, 59);
    glBegin(GL_POLYGON);
    glVertex2f(-0.27f,-0.38f);
    glVertex2f(-0.30f,-0.46f);
    glVertex2f(0.21f,- 0.28f);
    glVertex2f(0.19f, -0.25f);
    glVertex2f(-0.23f,-0.42f);
    glVertex2f(-0.24f,-0.36f);
     glEnd();

    glColor3ub(92, 90, 59);
    glBegin(GL_POLYGON);
    glVertex2f(0.10f,-0.44f);
    glVertex2f(0.10f,-0.46f);
    glVertex2f(0.30f,- 0.46f);
    glVertex2f(0.30f, -0.44f);
    glVertex2f(0.24f,-0.39f);
    glVertex2f(0.17f,-0.39f);
      glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.38f,-0.26f);
    glVertex2f(0.46f,-0.21f);
    glVertex2f(0.43f,- 0.18f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.43f,-0.29f);
    glVertex2f(0.43f,-0.31f);
    glVertex2f(0.60f,- 0.31f);
    glVertex2f(0.60f, -0.31f);
    glVertex2f(0.55f,-0.26f);
    glVertex2f(0.48f,-0.26f);
      glEnd();
          glPopMatrix();
    glutSwapBuffers();

}
void rain()
{
    glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///685


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,216,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///701


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///709


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0); ///717


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);  ///741


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0); ///749


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///757


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0); ///781


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///790


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0); ///814


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glLoadIdentity();

     glPopMatrix();


    glTranslatef(0,0.2,0);

    glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///685


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,216,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///701


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///709


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0); ///717


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);  ///741


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0); ///749


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///757


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0); ///781


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///790


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0); ///814


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glLoadIdentity();

     glPopMatrix();


///,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
///2222222
 glTranslatef(0,0.4,0);

glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///685


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,216,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///877


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);  ///909


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0); ///917


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///925


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///941


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0); ///949


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///790


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0); ///982


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glLoadIdentity();

     glPopMatrix();


  glTranslatef(0,-0.4,0);

  ///;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///685


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,216,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0); ///877


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);  ///909


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0); ///917


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///925


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///941


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0); ///949


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0); ///790


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0); ///982


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glLoadIdentity();

     glPopMatrix();




///'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

    glTranslatef(0,-0.8,0);

    glPushMatrix();
    glTranslatef(position9,position8,0.0f);
    glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);

     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(-0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();
     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();

     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,-0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();



     glTranslatef(0.2,0.1,0);


     glColor3ub(174,214,241);
    glBegin(GL_LINES);
    glVertex2f(-0.4,0.47);
    glVertex2f(-0.35,0.28);
     glEnd();


     glLoadIdentity();

     glPopMatrix();



}


void display()
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

//     gluOrtho2D(-0.64,0.64,-0.64,0.64);
    init();

    sky();
    plane();
    sun();
    clouds();
    grass();
    tree();
    bench();
    house();
    houseStair();
    roadside();
    railing();
    lamppost();
    road();
    fontroad();
    car1();
    car2();

    truck();
    bus();

    glFlush();
}


void display2()
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

     //gluOrtho2D(-0.64,0.64,-0.64,0.64);
     init();

    skyN();
    sunN();
    //plane();
   // sun();
    //clouds();
    grassN();
    tree();
    bench();
    houseN();
    houseStair();
    roadside();
    railingN();
    lamppostN();
    road();
    fontroad();
    car1();
    car2();
    truck();
    bus();


    glFlush();
}


void display3()     //flood
{



     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

     //gluOrtho2D(-0.64,0.64,-0.64,0.64);

    init();


    skyR();
   // plane();
   // sun();
    cloudsR();
  grassN();
    tree();
    bench();
    house();
   houseStair();
//    roadside();
railing();
    lamppost();
road();
 fontroad();
  car1();
          car2();

   truck();
    bus();



    rain();



    glFlush();
}


void display4()     //flood
{
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

     //gluOrtho2D(-0.64,0.64,-0.64,0.64);

    init();


    skyR();
   // plane();
   // sun();
    cloudsR();
  grassN();
    tree();
    bench();
    house();
   houseStair();
//    roadside();
railing();
    lamppost();
road();
 fontroad();


    objects();
        car2F();
           truckF();
    busF();
    rain();



    glFlush();
}



//
//void handleMouse(int button, int state, int x, int y) {
//	if (button == GLUT_LEFT_BUTTON)
//	{	_speedcarright += 0.01f;
//			}
//if (button == GLUT_RIGHT_BUTTON)
//	{_speedcarright -= 0.01f;   }
//glutPostRedisplay();}


void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {

case 'n':
            glutDestroyWindow(1);
//glutInit(&argc, argv);
glutInitWindowSize(1386, 788); // Initialize GLUT
glutInitWindowPosition(50, 50);
glutCreateWindow("Night "); // Create a window with the given title
glutDisplayFunc(display2);
           glutKeyboardFunc(handleKeypress);
          // glutMouseFunc(handleMouse);
           glutMainLoop();
break;
case 'd':
    glutDestroyWindow(1);
//glutInit(&argc, argv);
//glutInitWindowSize(600, 600); // Initialize GLUT
//glutInitWindowPosition(50, 50);
glutCreateWindow("Day"); // Create a window with the given title

glutDisplayFunc(display);
           glutKeyboardFunc(handleKeypress);
          // glutMouseFunc(handleMouse);
           glutMainLoop();
           break;

           case 'r':
            glutDestroyWindow(1);

glutInitWindowSize(1386, 788); // Initialize GLUT
glutInitWindowPosition(50, 50);
glutCreateWindow("flood "); // Create a window with the given title
glutDisplayFunc(display3);
           glutKeyboardFunc(handleKeypress);
          // glutMouseFunc(handleMouse);
        //glutMainLoop();
break;


	}
}



int main(int argc, char** argv)
{


    glutInit(&argc, argv);
        glutInitWindowSize(1386, 788); // Initialize GLUT
glutInitWindowPosition(50, 50);


    glutCreateWindow("Test");

   // init();


    //glutInitWindowSize(320, 320);
    //gluOrtho2D(-0.64,0.64,-0.64,0.64);
    glutDisplayFunc(display);

    glutTimerFunc(20, updateb1, 0);
    glutTimerFunc(300, updateSun, 0);

    glutTimerFunc(20, updatet1, 0);
    glutTimerFunc(400, updateObject, 0);

    glutTimerFunc(5, updateCar1, 0);

    glutTimerFunc(70, updateCar2, 0);
    glutTimerFunc(70, updatePlane, 0);

    glutTimerFunc(70, updateCloud, 0);

    glutTimerFunc(100, updateCloudleft, 0);

    glutTimerFunc(300, updateWater, 0);

    glutTimerFunc(100,update8,0);





    glutKeyboardFunc(handleKeypress);
  // glutMouseFunc(handleMouse);


    glutMainLoop();
    return 0;
}

