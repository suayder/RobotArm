#include "robotarm.h"

RobotArm::RobotArm()
{
    this->arm.base = 0.03;
    this->arm.top = 0.03;
    this->arm.angle = 0.0;

    this->foreArm1.base = 0.03;
    this->foreArm1.top = 0.03;
    this->foreArm1.angle = 70.0;

    this->foreArm2.base = 0.03;
    this->foreArm2.top = 0.03;
    this->foreArm2.angle = 40.0;

    this->radiusJoin = 0.05;
}

void RobotArm::drawArm(GLfloat angle)
{
    glPushMatrix();
        //Object
        glPushMatrix();
            glColor3f(0.1,0.5,0.5);
            glTranslatef(this->posObject[0],this->posObject[1],this->posObject[2]);
            glutSolidSphere(this->radiusJoin-0.01, this->arm.slices, this->arm.stacks);
        glPopMatrix();
        //***************************
        glColor3f(0.5,0.5,0.5);
        glutSolidCube(0.35);

        glPushMatrix();

            glPushMatrix();
                this->drawBase();
                glTranslatef(0.0, 0.0,0.15);

                this->drawJoin();

                glPushMatrix();
                    glColor3f(0.5,0.5,0.5);
                    glRotatef(this->arm.angle, 0.0, 0.0, 1.0);

                    gluCylinder(gluNewQuadric(), this->arm.base, this->arm.top, this->arm.size, this->arm.slices, this->arm.stacks);
                    glTranslatef(0, 0, this->arm.size);

                    this->drawJoin();

                    glPushMatrix();
                        this->drawForeArm(this->foreArm1);

                        glTranslatef(0, 0, this->foreArm1.size);

                        this->drawJoin();

                        glPushMatrix();
                            this->drawForeArm(this->foreArm2);

                            glTranslatef(0, 0, this->foreArm2.size);

                            this->drawJoin();
                            this->drawHand(angle);
                        glPopMatrix();

                    glPopMatrix();

                glPopMatrix();

            glPopMatrix();

        glPopMatrix();

    glPopMatrix();

    this->calcPosHand();
}

void RobotArm::drawForeArm(typeArm &arm)
{
    glColor3f(0.5,0.5,0.5);
    glRotatef(arm.angle, 0.0, 1.0, 0.0);

    gluCylinder(gluNewQuadric(), arm.base, arm.top, arm.size, arm.slices, arm.stacks);

}

void RobotArm::drawBase()
{
    glColor3f(0.1,0.3,0.6);
    glutSolidCube(0.3);
}

void RobotArm::drawJoin()
{
    glColor3f(0.5,0.0,0.0);
    glTranslatef(0, 0, this->radiusJoin/2);
    glutSolidSphere(this->radiusJoin, this->arm.slices, this->arm.stacks);
}

void RobotArm::drawHand(GLfloat angle)
{
    glColor3f(0.5,0.5,0.5);
    glRotatef(60,0,1,0);
    gluCylinder(gluNewQuadric(), 0.008, 0.008, 0.1, this->arm.slices, this->arm.stacks);
    glTranslatef(0,0,0.1);

    glRotatef(-angle,0,1,0);
    glutSolidCone(0.008, 0.1,this->arm.slices,this->arm.stacks);
    glRotatef(angle,0,1,0);

    glTranslatef(0,0,-0.1);

    glRotatef(-120,0,1,0);
    gluCylinder(gluNewQuadric(), 0.008, 0.008, 0.1, this->arm.slices, this->arm.stacks);
    glTranslatef(0,0,0.1);
    glRotatef(angle,0,1,0);
    glutSolidCone(0.008, 0.1,this->arm.slices,this->arm.stacks);
    glRotatef(-angle,0,1,0);
    glTranslatef(0,0,-0.1);
}

void RobotArm::moveObject(GLfloat angle)
{
    glPushMatrix();

        glutSolidCube(0.35);
        glPushMatrix();
            glPushMatrix();

                this->drawBase();
                glTranslatef(0.0, 0.0,0.15);
                glRotatef(0, 0, 0, 1);
                this->drawJoin();

                glPushMatrix();
                    glColor3f(0.5,0.5,0.5);
                    glRotatef(this->arm.angle, 0.0, 0.0, 1.0);
                    gluCylinder(gluNewQuadric(), this->arm.base, this->arm.top, this->arm.size, this->arm.slices, this->arm.stacks);
                    glTranslatef(0, 0, this->arm.size);
                    this->drawJoin();

                    glPushMatrix();
                        this->drawForeArm(this->foreArm1);
                        glTranslatef(0, 0, this->foreArm1.size);
                        this->drawJoin();

                        glPushMatrix();
                        this->drawForeArm(this->foreArm2);
                        glTranslatef(0, 0, this->foreArm2.size);
                        this->drawJoin();
                        this->moveDrawHand(angle);

                        glPopMatrix();

                    glPopMatrix();

                glPopMatrix();

            glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        this->calcPosHand();
}

void RobotArm::moveDrawHand(GLfloat angle)
{
    glPushMatrix();
        glColor3f(0.1,0.5,0.5);
        glTranslatef(0.0,0.0,0.1);
        glutSolidSphere(this->radiusJoin-0.01, this->arm.slices, this->arm.stacks);
    glPopMatrix();
    glColor3f(0.5,0.5,0.5);
    glRotatef(60,0,1,0);
    gluCylinder(gluNewQuadric(), 0.008, 0.008, 0.1, this->arm.slices, this->arm.stacks);
    glTranslatef(0,0,0.1);

    glRotatef(-angle,0,1,0);
    glutSolidCone(0.008, 0.1,this->arm.slices,this->arm.stacks);
    glRotatef(angle,0,1,0);

    glTranslatef(0,0,-0.1);

    glRotatef(-120,0,1,0);
    gluCylinder(gluNewQuadric(), 0.008, 0.008, 0.1, this->arm.slices, this->arm.stacks);
    glTranslatef(0,0,0.1);
    glRotatef(angle,0,1,0);
    glutSolidCone(0.008, 0.1,this->arm.slices,this->arm.stacks);
    glRotatef(-angle,0,1,0);
    glTranslatef(0,0,-0.1);
}

void RobotArm::calcPosHand()
{
    GLfloat aux, aux1;

    this->posHand[0] = 0;
    this->posHand[1] = 0;
    this->posHand[2] = (0.15+this->radiusJoin/2+this->arm.size+this->radiusJoin/2);

    aux = 0;
    aux1 = this->foreArm1.size+this->radiusJoin/2;

    this->posHand[0] = aux*cos(-this->foreArm1.angle*PI/180)-aux1*sin(-this->foreArm1.angle*PI/180)+this->posHand[0];
    this->posHand[2] = aux*sin(-this->foreArm1.angle*PI/180)+aux1*cos(-this->foreArm1.angle*PI/180)+this->posHand[2];

    aux = 0;
    aux1 = this->foreArm2.size+this->radiusJoin/2;

    GLfloat t1,t2;

    this->posHand[0] = aux*cos(-(this->foreArm2.angle+this->foreArm1.angle)*PI/180)-aux1*sin(-(this->foreArm2.angle+this->foreArm1.angle)*PI/180)+this->posHand[0];
    this->posHand[2] = aux*sin(-(this->foreArm2.angle+this->foreArm1.angle)*PI/180)+aux1*cos(-(this->foreArm2.angle+this->foreArm1.angle)*PI/180)+this->posHand[2];
    this->posHand[1] += this->posHand[1];

    if(this->arm.angle!=0){
        aux = this->posHand[0];
        aux1 = this->posHand[1];
        this->posHand[0] = (aux*cos(this->arm.angle*PI/180)-(aux1*sin(this->arm.angle*PI/180)));
        this->posHand[1] = (aux*sin(this->arm.angle*PI/180)+aux1*cos(this->arm.angle*PI/180));
    }

}

GLfloat RobotArm::calcDistanceHandToObject()
{
    GLfloat x = this->posHand[0]-this->posObject[0];
    GLfloat y = this->posHand[1]-this->posObject[1];
    GLfloat z = this->posHand[2]-this->posObject[2];

    return sqrt(x*x+y*y+z*z);

}

void RobotArm::dropObject()
{
    this->posObject[0] = this->posHand[0];
    this->posObject[1] = this->posHand[1];
    this->posObject[2] = this->posHand[2];

    while(this->posObject[2]>0){
        glClear(GL_COLOR_BUFFER_BIT);
        this->drawArm(70.0);
        this->posObject[2]-=0.01;
    }
    while(this->posObject[2]<=0){
        glClear(GL_COLOR_BUFFER_BIT);
        this->drawArm(70.0);
        this->posObject[2]+=0.01;
    }

}

typeArm& RobotArm::getArm()
{
    return arm;
}

typeArm& RobotArm::getForeArm1()
{
    return this->foreArm1;
}

typeArm &RobotArm::getForeArm2()
{
    return foreArm2;
}
