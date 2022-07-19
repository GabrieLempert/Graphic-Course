#define GL_SILENCE_DEPRECATION
#include <OpenGL/glu.h>
#include <iostream>
#include <OpenGL/gl.h>
#include "GLUT/glut.h"
#include "math.h"
#include <time.h>
const int NUM_STARS = 500;
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
        stars[1][i] = ( rand() % 4000) / 2000.0;
        stars[2][i] = 1 + rand() % 3;

    }
    
    for (i = 0; i < NUM_FLOORS; i++)
        for (j = 0; j < NUM_WINDOWS; j++)
            windows[i][j] = rand() % 3;
    

}



void drawBars_1(){
    double x, y;
    int i, j,num_floors,num_windows;
    double dx = 0.0015, dy=0.02;

    for (double x=-0.8; x<=0.6; x+=0.15) {
        double y=fabs(0.7*cos(1.5*x)+0.25*cos(15*x));
        glBegin(GL_POLYGON);
        glColor3d(0, 0, 0);
        glVertex2d(x,y);
        glVertex2d(x+0.1, y);
        glColor3d(0.4, 0.2, 0.8);
        glVertex2d(x+0.1, 0);
        glVertex2d(x, 0);
        glEnd();
        
        
        num_windows = 0.1 / dx;
        if (num_windows > NUM_WINDOWS) num_windows = NUM_WINDOWS;
        num_floors = y / dy;
        if (num_floors > NUM_FLOORS) num_floors = NUM_FLOORS;

        glPointSize(2);
        for(i=0;i<num_floors ;i++)
            for (j = 0; j <num_windows ; j++)
            {
                glColor3d(0.5*windows[i][j], 0.5*windows[i][j], 0); // 3 levels of yellow
                glBegin(GL_POINTS);
                glVertex2d(x + 0.01 + j * dx, y - 0.01 - i * dy);
                glEnd();
            }
    }
    
    for (x = -0.8; x <= 0.6; x += 0.15)
    {
        y = fabs(0.7*cos(2 * x) + 0.25*cos(15 * x));

        glBegin(GL_POLYGON);
        glColor4d(0,0,0,-5);
        glVertex2d(x, -y); // left-top point
        glVertex2d(x + 0.1, -y);// right -top point
        glColor3d(0.4/4, 0.2/4, 0.8/4);
        glVertex2d(x + 0.1, 0);// right -bottom point
        glVertex2d(x, 0);// left - bottom point
        glEnd();
        
        
        num_windows = 0.1 / dx;
        if (num_windows > NUM_WINDOWS) num_windows = NUM_WINDOWS;
        num_floors = y / dy;
        if (num_floors > NUM_FLOORS) num_floors = NUM_FLOORS;

        glPointSize(2);
        for(i=0;i<num_floors ;i++)
            for (j = 0; j <num_windows ; j++)
            {
                glColor3d(0.3*windows[i][j], 0.3*windows[i][j], 0); // 3 levels of yellow
                glBegin(GL_POINTS);
                glVertex2d(x + 0.01 + j * dx,-(y - 0.01 - i * dy));
                glEnd();
            }

    }
}

void DrawSky(){
    glBegin(GL_POLYGON);
    glColor3d(0.4, 0.4, 0.5);
    glVertex2d(-1, 1);
    glVertex2d(1, 1);
    glColor3d(0.1, 0.1, 0.3);
    glVertex2d(1, 0);
    glVertex2d(-1, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3d(0, 0.1, 0.2);
    glVertex2d(-1, -1);
    glVertex2d(1, -1);
    glColor3d(0, 0.2, 0.3);
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

void drawBars_2(){
    double x, y;
    int i, j,num_floors,num_windows;
    double dx = 0.0015, dy=0.02;

    for (x=-1; x<=1; x+=0.15) {
        y=fabs(0.7*cos(1.5*x)+0.2*cos(15*x));
        glBegin(GL_POLYGON);
        glColor3d(0, 0, 0.1);
        glVertex2d(x,y);
        glVertex2d(x+0.1, y);
        glColor3d(0.4, 0.5, 0.8);
        glVertex2d(x+0.1, 0);
        glVertex2d(x, 0);
        glEnd();
        
        num_windows = 0.1 / dx;
        if (num_windows > NUM_WINDOWS) num_windows = NUM_WINDOWS;
        num_floors = y / dy;
        if (num_floors > NUM_FLOORS) num_floors = NUM_FLOORS;

        glPointSize(2);
        for(i=0;i<num_floors ;i++)
            for (j = 0; j <num_windows ; j++)
            {
                glColor3d(0.5*windows[i][j], 0.5*windows[i][j], 0); // 3 levels of yellow
                glBegin(GL_POINTS);
                glVertex2d(x + 0.01 + j * dx,+(y - 0.01 - i * dy));
                glEnd();
            }
    }
    
    for (x = -1; x <= 1; x += 0.15)
    {
        y=fabs(0.7*cos(1.5*x)+0.2*cos(15*x));

        glBegin(GL_POLYGON);
        glColor4d(0,0,0,-5);
        glVertex2d(x, -y); // left-top point
        glVertex2d(x + 0.1, -y);// right -top point
        glColor3d(0.4/4, 0.5/6, 0.8/4);
        glVertex2d(x + 0.1, 0);// right -bottom point
        glVertex2d(x, 0);// left - bottom point
        glEnd();
        
        num_windows = 0.1 / dx;
        if (num_windows > NUM_WINDOWS) num_windows = NUM_WINDOWS;
        num_floors = y / dy;
        if (num_floors > NUM_FLOORS) num_floors = NUM_FLOORS;

        glPointSize(2);
        for(i=0;i<num_floors ;i++)
            for (j = 0; j <num_windows ; j++)
            {
                glColor3d(0.3*windows[i][j], 0.3*windows[i][j], 0); // 3 levels of yellow
                glBegin(GL_POINTS);
                glVertex2d(x + 0.01 + j * dx,-(y - 0.01 - i * dy));
                glEnd();
            }
    }
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        glColor3d(0.99999, 0.999997, 0.9999);

        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}




void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    DrawSky();
    DrawCircle(0.7,0.7,0.2,120);
    drawBars_1();
    drawBars_2();

   
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
    glutInitWindowSize(800,600);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("First Example");
    
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    
    init();
    glutMainLoop();
    
    
    return 1;
}

