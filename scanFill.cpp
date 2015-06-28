#include<GL/freeglut.h>

#define WINDOW_HEIGHT 400

struct POINT
{
    int x;
    int y;
};

typedef struct tEdge
{
    int ymax;
    float x, dx;
    struct  tEdge *next;
}Edge;

void insertEdge(Edge* list, Edge* edge)
{
    Edge* p, *q = list;
    p = q->next;

    while( p != NULL)
    {
        if(edge->x < p->x)
        {
            p = NULL;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }

    edge->next = q->next;

    q->next = edge;
}

int yNext(int k, int cnt, POINT* pts)
{
    int j;
    if( (k+1) > (cnt-1))
    {
        j = 0;
    }
    else
    {
        j = k + 1;
    }

    while( pts[k].y == pts[j].y)
    {
        if((j+1) > (cnt-1))
        {
            j = 0;
        }
        else
        {
            j++;
        }
    }

    return pts[j].y;
}

void makeEdgeRec(POINT lower, POINT upper,int yComp,Edge* edge,Edge* edges[])
{
    edge->dx = (float)(upper.x - lower.x)/(upper.y - lower.y);
    edge->x = lower.x;
    if(upper.y < yComp)
    {
        edge->ymax = upper.y - 1;
    }
    else
    {
        edge->ymax = upper.y;
    }

    insertEdge(edges[lower.y],edge);
}

void buildEdgeList(int cnt, POINT* pts, Edge* edges[] )
{

   Edge *edge;
   POINT v1, v2;

   int i, yPrev = pts[cnt-2].y;

   v1.x = pts[cnt - 1].x;
   v1.y = pts[cnt - 1].y;

   for( i = 0; i < cnt; i++)
   {
       v2 = pts[i];
       if(v1.y != v2.y)
       {
           edge = new Edge;
           if( v1.y < v2.y)
           {
               makeEdgeRec(v1,v2,yNext(i,cnt,pts),edge,edges);
           }
           else
           {
               makeEdgeRec(v2,v1,yPrev,edge,edges);
           }

       }

       yPrev = v1.y;
       v1 = v2;
   }
}

void buildActiveList(int scan, Edge* active, Edge* edges[])
{
    Edge *p,*q;

    p = edges[scan]->next;

    while(p)
    {
       q = p->next;
       insertEdge(active,p);
       p = q;
    }


}

void fillScan(int scan, Edge* active, int color)
{
    Edge* p1, *p2;
    int i;
    p1 = active->next;
    while(p1)
    {
        p2 = p1->next;

        int r = (color & 0xff000000) >> 24;
        int g = (color & 0xff0000) >> 16;
        int b = (color & 0x00ff00) >> 8;

        for( i = p1->x; i < p2->x; i++)
        {
            glBegin(GL_POINTS);
            glColor3f(r,g,b);
            glVertex2i(i,scan);
            glEnd();
        }

        p1 = p2->next;

    }


}

void deleteAfter(Edge* q)
{
   Edge *p = q->next;
   q->next = p->next;
   delete p;
}

void updateActiveList(int scan, Edge* active)
{
    Edge* q = active, *p = active->next;
    while(p)
    {
        if( scan >= p->ymax)
        {
            p = p->next;
            deleteAfter(q);
        }
        else
        {
            p->x = p->x + p->dx;
            q = p;
            p = p->next;
        }
    }


}

void resortActiveList(Edge* active)
{
    Edge* q, *p = active->next;
    active->next = NULL;
    while(p)
    {
        q = p->next;
        insertEdge(active,p);
        p = q;
    }
}

void scanFill(int cnt, POINT* pts, int color)
{
    Edge *edges[WINDOW_HEIGHT], *active;

    int i, scan, scanmax = 0, scanmin = WINDOW_HEIGHT;

    for( i = 0; i < cnt - 1; i++)
    {
        if(scanmax < pts[i].y ) scanmax = pts[i].y;
        if(scanmin > pts[i].y ) scanmin = pts[i].y;
    }

    for( scan = scanmin; scan <= scanmax; scan++)
    {
        edges[scan] = new Edge;
        edges[scan]->next = NULL;
    }

    buildEdgeList(cnt,pts,edges);

    active = new Edge;
    active->next = NULL;

    for( scan = scanmin; scan <= scanmax; scan++)
    {
        buildActiveList(scan,active,edges);
        if(active->next)
        {
            fillScan(scan,active,color);
            updateActiveList(scan,active);
            resortActiveList(active);
        }

    }

}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if( w <= h)
    {
        gluOrtho2D( -400.0 , 400 , -400 * (GLfloat)h/(GLfloat)w, 400 * (GLfloat)h/(GLfloat)w );
    }
    else
    {
        gluOrtho2D( -400.0 * (GLfloat)w/(GLfloat)h, 400.0 * (GLfloat)w/(GLfloat)h, -400.0,400.0);
    }

    glMatrixMode(GL_MODELVIEW);

}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    POINT pts[7];

    pts[0].x = 100; pts[0].y = 40;
    pts[1].x = 220; pts[1].y = 140;
    pts[2].x = 280; pts[2].y = 80;
    pts[3].x = 350; pts[3].y = 300;
    pts[4].x = 20; pts[4].y = 380;
    pts[5].x = 50; pts[5].y = 280;
    pts[6].x = 100; pts[6].y = 40;

    scanFill(7,pts,12587);

    glFlush();
}

int main(int argc ,char** argv)
{
   //circleMidpoint(100,100,50);
   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

   glutInitWindowSize(400,400);

   glutInitWindowPosition(200,200);

   glutCreateWindow("mid point circle");



   init();

   glutReshapeFunc(myReshape);

   glutDisplayFunc(myDisplay);

   glutMainLoop();

   return 0;
}




















