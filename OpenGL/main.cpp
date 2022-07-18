#define GL_SILENCE_DEPRECATION
#include <OpenGL/glu.h>
#include <iostream>
#include <OpenGL/gl.h>
#include "GLUT/glut.h"
#include "math.h"
#include <time.h>
const int NUM_STARS = 60;
double gx=0.5;double gy=0.5;
const int NUM_WINDOWS = 50;
const int NUM_FLOORS = 100;
const double PI=3.14;
double stars[3][NUM_STARS]; // X, Y, SIZE
int windows[NUM_FLOORS][NUM_WINDOWS];

void init()
{
    int i, j;
    srand(time(0));
    glClearColor(0, 0, 0.3, 0);// color of window background
    glOrtho(-1, 1, -1, 1, -1, 1); // defines the main axis and their range
    for (int i = 0; i < NUM_STARS; i++)
    {
        stars[0][i] = (-500+rand() % 1000)/500.0;
        stars[1][i] = ( rand() % 1000) / 2000.0;
        stars[2][i] = 1 + rand() % 3;

    }
    
    for (i = 0; i < NUM_FLOORS; i++)
        for (j = 0; j < NUM_WINDOWS; j++)
            windows[i][j] = rand() % 3;
    

}



void drawBars(double space){
    for (double x=-1+space; x<=1-space; x+=0.15) {
        double y=0.7*cos(1.5*x);
        glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x+0.1, y);
        glVertex2d(x+0.1, 0);
        glVertex2d(x, 0);
        glEnd();
    }
}

void DrawSky()
{
    glBegin(GL_POLYGON);
    glColor3d(0.4, 0.4, 0.5);
    glVertex2d(-1, 1);
    glVertex2d(1, 1);
    glColor3d(0.1, 0.1, 0.3);
    glVertex2d(1, 0);
    glVertex2d(-1, 0);
    glEnd();

    glColor3d(1, 1, 0);
    for (int i = 0; i < NUM_STARS; i++)
    {
        glPointSize(1 + rand() % 3);
        glBegin(GL_POINTS);
        glVertex2d(stars[0][i], stars[1][i]);
        glEnd();

    }
    glPointSize(1);

}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //DrawSky();
    for (double ; <#condition#>; <#increment#>) {
        <#statements#>
    }
   

   
    glutSwapBuffers();
}

void idle()
{
    
    int i,j;
    gx += 0.01;
    // change randomly the size of a star
    i = rand() % NUM_STARS;
    stars[2][i] = 1 + rand() % 3;
    // change randomly the light level of a window
    i = rand() % NUM_FLOORS;
    j = rand() % NUM_WINDOWS;
    windows[i][j] = rand() % 3;

    glutPostRedisplay();
}


int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("First Example");
    
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    
    init();
    glutMainLoop();
    
    
    return 1;
}

