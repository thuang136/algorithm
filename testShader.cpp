#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <cstdio>
using namespace std;

GLuint ProgramObject = 0;
GLuint VertexShaderObject = 0;
GLuint FragmentShaderObject = 0;

const char* Temp_vs[] = {
" uniform float CoolestTemp;"
" uniform float TempRange;"
" attribute float VertexTemp;"
" varying float Temperature;"

"void main()"
"{ "
"    Temperature = (VertexTemp - CoolestTemp) / TempRange;"
"     gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;"
"}"
};

const char* Temp_fs[] = {

"uniform vec3 CoolestColor;"
"uniform vec3 HottestColor;"
"varying float Temperature;"

"void main()"
"{ "
"    vec3 color = mix(CoolestColor,HottestColor,Temperature);"
"    gl_FragColor = vec4(color,1.0);"
"}"

};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    GLint tempLoc = glGetAttribLocation(ProgramObject,"VertexTemp");

    glBegin(GL_TRIANGLES);
    glVertexAttrib1f(tempLoc,0.0f);
    glVertex3f(1.0f,0.0f,0.0f);

    glVertexAttrib1f(tempLoc,0.5f);
    glVertex3f(-1.0f,0.0f,0.0f);

    glVertexAttrib1f(tempLoc,1.0f);
    glVertex3f(0.0f,1.0f,0.0f);

    glEnd();

    glFlush();

    glutSwapBuffers();

}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0,1.0,-1.0,1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

int installShaders(const GLchar* vertex[], const GLchar* fragment[])
{
    GLint vertCompiled, fragCompiled;

    GLint linked;

    VertexShaderObject = glCreateShader(GL_VERTEX_SHADER);
    FragmentShaderObject = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(VertexShaderObject,1,vertex,NULL);
    glShaderSource(FragmentShaderObject,1,fragment,NULL);

    glCompileShader(VertexShaderObject);
    glGetShaderiv(VertexShaderObject,GL_COMPILE_STATUS,&vertCompiled);

    glCompileShader(FragmentShaderObject);
    glGetShaderiv(FragmentShaderObject,GL_COMPILE_STATUS,&fragCompiled);

    if(!vertCompiled || !fragCompiled)
    {
        cout << "shader compile fail" << endl;
        cout << "vertex :" << vertCompiled << endl;
        cout << "fragment:" << fragCompiled << endl;
        GLint length;
        GLchar* log;
        glGetShaderiv(FragmentShaderObject,GL_INFO_LOG_LENGTH,&length);
        log = (GLchar*)malloc(length);
        glGetShaderInfoLog(FragmentShaderObject,length,&length,log);
        cout << "the log :" << log << endl;
        free(log);
        return 0;
    }

    ProgramObject = glCreateProgram();
    glAttachShader(ProgramObject,VertexShaderObject);
    glAttachShader(ProgramObject,FragmentShaderObject);


    glLinkProgram(ProgramObject);
    glGetProgramiv(ProgramObject,GL_LINK_STATUS,&linked);

    if(!linked)
    {
        cout << "link program fail" << endl;
        return 0;
    }

    glUseProgram(ProgramObject);

    glUniform1f(glGetUniformLocation(ProgramObject,"CoolestTemp"),0.0f);
    glUniform1f(glGetUniformLocation(ProgramObject,"TempRange"),1.0f);

    glUniform3f(glGetUniformLocation(ProgramObject,"CoolestColor"),0.0,0.0,1.0);
    glUniform3f(glGetUniformLocation(ProgramObject,"HottestColor"),1.0,0.0,0.0);

    return 1;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(500,500);

    glutCreateWindow("Temperature Shader");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    GLenum err = glewInit();

    if(GLEW_OK != err)
    {
        cout << "GLEW_OK not ok" << endl;
    }

    if(GLEW_ARB_vertex_program)
    {
        cout << "vertex program available" << endl;
    }

    const GLubyte* openglVersion = glGetString(GL_VERSION);

    cout << "GL_VERSION : " << openglVersion << endl;

    installShaders(Temp_vs,Temp_fs);

    glutMainLoop();

}

