#include<windows.h>
#include <GL/glut.h>
#include<iostream>
using namespace std;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

float x=-0.8f;
float y=0.8f;
int counter=1;
int k;

void glHelper()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0,k=counter;j<8;j++)
        {

            glBegin(GL_POLYGON);
            if(k%2==0){
                glColor3f(0.0f,0.0f,0.0f);
                cout<<"BLACK"<<endl;
            }
            else{
                glColor3f(1.0f,1.0f,1.0f);
                cout<<"WHITE"<<endl;
            }
            glVertex2f(x+0.2,y-0.2);
            glVertex2f(x+0.2,y);
            glVertex2f(x,y);

            glVertex2f(x+0.2,y-0.2);
            glVertex2f(x,y);
            glVertex2f(x,y-0.2);
            glEnd();
            cout<<(x+0.2)<<","<<y-0.2<<endl;
            cout<<x<<","<<y<<endl;
            cout<<x<<","<<y-0.2<<endl;
            cout<<k<<endl;
            cout<<endl;
            x=x+0.2f;
            k++;
        }
        counter++;
        x=-0.8f;
        y=y-0.2;
    }
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.8,0.8);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.8,0.8f);
    glVertex2f(0.8f,-0.8f);
    glVertex2f(0.8f,-0.8f);
    glVertex2f(-0.8f,-0.8f);
    glVertex2f(-0.8f,-0.8f);
    glVertex2f(-0.8f,0.8f);
    glEnd();
}

static void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glHelper();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("GLUT Shapes");
    //glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
