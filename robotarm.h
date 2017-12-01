#ifndef ROBOTARM_H
#define ROBOTARM_H

#include <iostream>

#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>

#include <QDebug>

#define PI 3.14159265

typedef struct{
    float base; //radio of the base at z axis
    float top; //radio of the top at z axis
    const float size = 0.35;
    const float slices = 50.0; //number of subdivisions around z axis
    const float stacks = 50.0; //number of subdivisions along z axis
    GLfloat angle;
    void sumAngle(GLfloat value){
        //std::cout<<"Angle:"<<angle<<std::endl;
        angle +=value;
    }
    void subAngle(GLfloat value){
        //std::cout<<"Angle:"<<angle<<std::endl;
        angle-=value;
    }
}typeArm;


class RobotArm
{
public:
    RobotArm();
    void drawArm(GLfloat angle);
    void drawForeArm(typeArm& arm);
    void drawBase();
    void drawJoin();
    void drawHand(GLfloat angle);
    void moveObject(GLfloat angle);
    void moveDrawHand(GLfloat angle);

    typeArm &getArm();

    typeArm &getForeArm1();

    typeArm &getForeArm2();

private:
    typeArm arm;
    typeArm foreArm1;
    typeArm foreArm2;
    GLfloat radiusJoin;
    GLfloat posObject[3] = {0.6,0.0,0.0};
    GLfloat posHand[3] = {0.0,0.0,0.0};

};

#endif // ROBOTARM_H
