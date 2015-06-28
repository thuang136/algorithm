#include<iostream>
using namespace std;

static const int MAX_ATTRIBUTES = 16;
static unsigned int s_attributeFlags = 0;


enum {

       VERTEX_ATTRIB_FLAG_NONE = 0,

       VERTEX_ATTRIB_FLAG_POSITION = 1 << 0,

       VERTEX_ATTRIB_FLAG_COLOR = 1 << 1,

       VERTEX_ATTRIB_FLAG_TEX_COORD = 1 << 2

};


void enableVertexAttribs(unsigned int flags)
{
    for(int i = 0 ; i < MAX_ATTRIBUTES; i++)
    {
        unsigned int bit = 1 << i;

        bool enabled = flags & bit;

        bool enabledBefore = s_attributeFlags & bit;

        if(enabled != enabledBefore)
        {
            if(enabled)
            {
                cout << i << " vertex enable" << endl;
            }
            else
            {
                cout << i << " vertex disable" << endl;
            }
        }

    }

    s_attributeFlags = flags;

}

int main(int argc ,char** argv)
{
  enableVertexAttribs(0xF);
  enableVertexAttribs(0xFF);
  enableVertexAttribs(0xF0);
}



