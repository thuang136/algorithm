
#include <GL/glew.h>
#include <GL/freeglut.h>

#include<iostream>
#include<cstring>

#include<cmath>

using namespace std;

#define BUFFER_OFFSET(offset) ((GLvoid*)NULL + offset)
#define NumberOf(array) (sizeof(array)/sizeof(array[0]))


typedef struct
{
    GLfloat x, y, z;
} vec3;

typedef struct
{
    vec3 xlate;
    GLfloat angle;
    vec3 axis;
} XForm;

enum {Cube,Cone,NumVAOs };
GLuint VAO[NumVAOs];
GLenum PrimType[NumVAOs];
GLsizei NumElements[NumVAOs];

XForm xform[NumVAOs] = {
                         {    {-2.0, 0.0,0.0}, 0.0, {0.0,1.0,0.0} },
                         {    {0.0, 0.0,2.0}, 0.0, {1.0,0.0,0.0} }
                       };

GLfloat Angle = 0.0;

void init()
{
    enum {Vertices,Colors,Elements,NumVBOs};
    GLuint buffers[NumVBOs];
    cout << "init" << endl;


    /*
        ���ų�����������ʹ�ø����ģ�ͣ����߿��ܷ���Ҫ��ÿ��֡�Ķ������֮���л���������Ϊ����ʹ���˶��ٸ��������ԣ�
        ���glVertexPointer()�����ĺ������ô������ܱ�úܴ󣬶���������������˵��õļ��ϣ������ö��������״̬��

    */



    glGenVertexArrays(NumVAOs,VAO);

    cout << "generate vertex array" << endl;

    {
        GLfloat cubeVerts[][3] = {
                        {-1.0,-1.0,-1.0},
                        {1.0,-1.0,-1.0},
                        {1.0,1.0,-1.0},
                        {-1.0,1.0,-1.0},
                        {-1.0,-1.0,1.0},
                        {1.0,-1.0,1.0},
                        {1.0,1.0,1.0},
                        {-1.0,1.0,1.0},

                    };


         GLubyte cubeIndices[] = {
               0,3,2,1,
               4,5,6,7,
               4,0,5,1,
               2,3,7,6,
               7,3,0,4,
               2,6,5,1
         };

         GLfloat cubeColors[][3] = {
                 {0.0,0.0,0.0},
                 {0.0,0.0,1.0},
                 {0.0,1.0,0.0},
                 {0.0,1.0,1.0},

                 {1.0,0.0,0.0},
                 {1.0,0.0,1.0},

                 {1.0,1.0,0.0},
                 {1.0,1.0,1.0}
             };




         /*
          �������Լ��Ķ����������֮����Ҫ��ʼ���µĶ��󣬲���Ҫ��ʹ�õĶ����������ݵļ����뵥���ѷ���Ķ������������ʹ��glBindVertexArray��������һ��

          һ����ʼ�������еĶ���������󣬾Ϳ���ʹ��glBindVertexArray�ڽ����Ĳ�ͬ�Ķ�������֮���л�

         */

         glBindVertexArray(VAO[Cube]);

         glGenBuffers(NumVBOs,buffers);

         /*
             Ϊ�˼��������������Ҫ�����󶨣��󶨻����������ʾѡ��δ���Ĳ���(�����ݽ��г�ʼ������ʹ�û��������������Ⱦ)��Ӱ���ĸ�����������Ҳ����˵Ӧ�ó����ж������������
             ����Ҫ��ε���glBindBuffer()����:һ�����ڳ�ʼ�������������Լ��������ݣ��Ժ�ĵ���Ҫôѡ��������Ⱦ�Ļ���������Ҫô�Ի�������������ݽ��и���

         */
         glBindBuffer(GL_ARRAY_BUFFER,buffers[Vertices]);

         /*
             �����ռ��Դ洢����
         */
         glBufferData(GL_ARRAY_BUFFER,sizeof(cubeVerts),cubeVerts,GL_STATIC_DRAW);

         /*ָ���������������*/

         /*

             glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);

             size :ָ��ÿ�������Ӧ�����������ֻ����2,3,4�е�һ��

             type :ָ��������ÿ������������������ͣ�GL_BYTE, GL_SHORT, GL_FLOAT

             stride : ���Ϊ0�������еĶ���ᱻ��Ϊ���ս��շ�ʽ����

             pointer �����е�һ��������׵�ַ

         */

         glVertexPointer(3,GL_FLOAT,0,BUFFER_OFFSET(0));

         /*

            glEnableClientState and glDisableClientState enable or disable individual client-side capability

            GL_VERTEX_ARRAY,if enabled , the vertex array is enabled for writing and used during rendering when glArrayElement, glDrawArrays, glDrawElements

            GL_COLOR_ARRAY,                  color array

         */

         glEnableClientState(GL_VERTEX_ARRAY);



         glBindBuffer(GL_ARRAY_BUFFER,buffers[Colors]);

         glBufferData(GL_ARRAY_BUFFER,sizeof(cubeColors),cubeColors,GL_STATIC_DRAW);

         glVertexPointer(3,GL_FLOAT,0,BUFFER_OFFSET(0));

         glEnableClientState(GL_COLOR_ARRAY);


         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,buffers[Elements]);

         glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(cubeIndices),cubeIndices,GL_STATIC_DRAW);


         PrimType[Cube] = GL_QUADS;

         NumElements[Cube] = NumberOf(cubeIndices);

         cout << "generate cube" << Cube << " " <<  NumElements[Cube] << endl;
    }


    {
        int i, idx;

        float dTheta;

        #define NumConePoints 36

        GLfloat coneVerts[NumConePoints+1][3] = { {0.0,0.0,1.0} };

        GLfloat coneColors[NumConePoints+1][3] = { {1.0,1.0,1.0} };

        GLfloat coneIndices[NumConePoints+1];

        dTheta = 2 * M_PI /(NumConePoints - 1);

        coneIndices[0] = 0;

        idx = 1;

        for( i = 0; i < NumConePoints; ++i, ++idx)
        {
            float theta = i * dTheta;

            coneVerts[idx][0] = cos(theta);
            coneVerts[idx][1] = sin(theta);
            coneVerts[idx][2] = 0.0;

            coneColors[idx][0] = cos(theta);
            coneColors[idx][1] = sin(theta);
            coneColors[idx][2] = 0.0;

            coneIndices[idx] = idx;

            cout << idx << coneVerts[idx][0] << endl;

        }

        glBindVertexArray(VAO[Cone]);

        glGenBuffers(NumVBOs,buffers);

        glBindBuffer(GL_ARRAY_BUFFER,buffers[Vertices]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(coneVerts),coneVerts,GL_STATIC_DRAW);
        glVertexPointer(3,GL_FLOAT,0,BUFFER_OFFSET(0));

        glEnableClientState(GL_VERTEX_ARRAY);

        glBindBuffer(GL_ARRAY_BUFFER,buffers[Colors]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(coneColors),coneColors,GL_STATIC_DRAW);
        glColorPointer(3,GL_FLOAT,0,BUFFER_OFFSET(0));

        glEnableClientState(GL_COLOR_ARRAY);


        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,buffers[Elements]);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(coneIndices),coneIndices,GL_STATIC_DRAW);

        PrimType[Cone] = GL_TRIANGLE_FAN;
        NumElements[Cone] = NumberOf(coneIndices);

        cout << "generate cone" << endl;

    }


    glEnable(GL_DEPTH_TEST);

}


void display()
{
    cout << "display" << endl;

    int i ;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    glRotatef(Angle,0.0,1.0,0.0);

    for( i = 0; i < NumVAOs; ++i)
    {
        glPushMatrix();

        glTranslatef(xform[i].xlate.x,xform[i].xlate.y,xform[i].xlate.z);

        (xform[i].angle,xform[i].axis.x,xform[i].axis.y,xform[i].axis.z);

        cout << i << endl;

        glBindVertexArray(VAO[i]);

        glDrawElements(PrimType[i],NumElements[i],GL_UNSIGNED_BYTE,BUFFER_OFFSET(0) );

        cout << i << endl;

        glPopMatrix();

    }

    glPopMatrix();

    glutSwapBuffers();


}


void myReshape(GLsizei w, GLsizei h)
{
    cout << "myReshape" << endl;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(-5.0, 5.0, -5.0, 5.0,-5.0,5.0);

    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(400,400);

    glutInitWindowPosition(200,200);

    glutCreateWindow("vertex Array");

    GLenum err = glewInit();

    if(GLEW_OK != err)
    {
        cout << "GLEW_OK not ok" << endl;
    }

    if(GLEW_ARB_vertex_program)
    {
        cout << "vertex program available" << endl;
    }


    init();

    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);



    glutMainLoop();

    return 0;
}






