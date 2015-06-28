
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutCreateWindow("GLEW test");

    GLenum err = glewInit();

    if(GLEW_OK != err)
    {
        cout << "GLEW_OK not ok" << endl;
    }

    if(GLEW_ARB_vertex_program)
    {
        cout << "vertex program available" << endl;
    }


    glutMainLoop();

}

