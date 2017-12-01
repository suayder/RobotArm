#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "robotarm.h"

RobotArm object;
GLdouble obsX=0.5, obsY=0.5, obsZ=0.5;
bool flagAux = true;

void render(void){

    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(-90,1.0f,0.0f,0.0f);

    object.drawArm(70.0);

    glutSwapBuffers();

    glFlush();

}

void initGL(void) {


    glClearColor(1,1,1,1);

    glEnable(GL_BUFFER);
    glEnable(GL_TEXTURE_3D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMatrixMode(GL_PROJECTION);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(45,(GLfloat)640/(GLfloat)480,0.2,0.2);
    gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
    //glScalef(0.7,0.7,0.7);


}

void SpecialKeys(int key, int x, int y);
void KeyBoard(unsigned char key, int x, int y);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(400,200);
        glutInitWindowSize(640,480);
        glutCreateWindow("OpenGl Application");
        
        initGL();
        
        glutSpecialFunc(SpecialKeys);
        glutKeyboardFunc(KeyBoard);

        glutDisplayFunc(render);
    glutMainLoop();

    return 0;
}

void SpecialKeys(int key, int x, int y){

    glClear(GL_COLOR_BUFFER_BIT);
    switch (key) {
        case GLUT_KEY_LEFT :
                        glRotatef(5,0.0f,0.0f,1.0f);
                        break;
        case GLUT_KEY_RIGHT :
                        glRotatef(-5,0.0f,0.0f,1.0f);
                        break;
        case GLUT_KEY_UP :
                        glRotatef(5,1.0f,0.0f,0.0f);
                        break;
        case GLUT_KEY_DOWN :
                        glRotatef(-5,1.0f,0.0f,0.0f);
                        break;

        case GLUT_KEY_HOME:
                        glRotatef(5,0.0f,1.0f,0.0f);
                        break;
        case GLUT_KEY_END :
                        glRotatef(-5,0.0f,1.0f,0.0f);
                        break;
    }

    (flagAux)?object.drawArm(70):object.moveObject(100);

    glutSwapBuffers();

    glFlush();
}


void KeyBoard(unsigned char key, int x, int y){
    switch (key) {
    case 'a':
        if(object.getForeArm1().angle>2)
            object.getForeArm1().subAngle(3);
        break;
    case 'd':
        if(object.getForeArm1().angle<358)
            object.getForeArm1().sumAngle(3);
        break;
    case 'w':
        if(object.getForeArm2().angle>2)
            object.getForeArm2().subAngle(3);
        break;
    case 's':
        if(object.getForeArm2().angle<358)
            object.getForeArm2().sumAngle(3);
        break;
    case '2':
        object.getArm().sumAngle(3);
        break;
    case '1':
        object.getArm().subAngle(3);
        break;
    case 32:
        flagAux = !flagAux;

    default:
        break;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    (flagAux)?object.drawArm(70):object.moveObject(100);

    glutSwapBuffers();

    glFlush();
}
