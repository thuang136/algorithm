#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include <cstdio>
using namespace std;

#define checkImageWidth 64

#define checkImageHeight 64

GLubyte checkImage [checkImageWidth][checkImageHeight][4];

static GLuint texName;


GLuint ProgramObject = 0;
GLuint VertexShaderObject = 0;
GLuint FragmentShaderObject = 0;

const char* Temp_vs[] = {

"void main()"
"{ "
"     gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;"
"}"
};

const char* Temp_fs[] = {
"uniform sampler2D tex;"
"void main()"
"{ "
"    gl_FragColor = gl_Color * texture2D(tex,gl_TexCoord[0].st) ;"
"}"

};

/*
Ê×ÏÈÊÇ glActiveTexture(GL_TEXTURE0 + i)



*/

void makeCheckImage()
{
    int i,j,c;

    for(i = 0 ; i < checkImageHeight; i++)
    {
       for(j = 0 ; j < checkImageWidth; j++)
       {
           c = ((( i & 0x8) == 0 ) ^ (( j & 0x8) == 0 )) * 255;

           checkImage[i][j][0] = (GLubyte)c;
           checkImage[i][j][1] = (GLubyte)c;
           checkImage[i][j][2] = (GLubyte)c;
           checkImage[i][j][3] = (GLubyte)255;
       }
    }

}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);

    glEnable(GL_DEPTH_TEST);
    makeCheckImage();

    glPixelStorei(GL_UNPACK_ALIGNMENT,1);

    glGenTextures(1,&texName);

    cout << texName << endl;

    glBindTexture(GL_TEXTURE_2D,texName);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    cout << "set Tex Parameter end" << endl;

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,checkImageWidth,checkImageHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,checkImage);

    cout << "init end" << endl;


}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    GLint texSampler ;
    texSampler = glGetUniformLocation(ProgramObject,"tex");

    cout << "texSampler:" << texSampler << endl;

    glActiveTexture(GL_TEXTURE0);

    glBindTexture(GL_TEXTURE_2D,texName);

    glUniform1i(texSampler,texName);


    glBegin(GL_QUADS);
    glTexCoord2f(1.0,0.0);glVertex3f(1.0f,-1.0f,0.0f);
    glTexCoord2f(0.0,0.0);glVertex3f(-1.0f,-1.0f,0.0f);
    glTexCoord2f(0.0,1.0);glVertex3f(-1.0f,1.0f,0.0f);
    glTexCoord2f(1.0,1.0);glVertex3f(1.0f,1.0f,0.0f);
    glEnd();

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

    init();

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


