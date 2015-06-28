#include<iostream>
#include<cstring>

using namespace std;

/*

��֪���ڵ��ʾ���������ĸ߶ȣ�ÿ�����㶼��һ���������ľ���

*/

int findHeight(int index, int*height,int* parent);


int treeHeight(int* parent, int size)
{
    int* height = new int[size];


    for(int i = 0 ; i < size ; i++)
    {
        height[i] = -1;
    }

    int maxHeight = 0;

    for(int i = 0; i < size; i++)
    {
       int curHeight = findHeight(i,height,parent);
       if(curHeight > maxHeight)
       {
           maxHeight = curHeight;
       }
    }

    return maxHeight;
}


int findHeight(int index, int*height,int* parent)
{
    if(height[index] != -1)
    {
        return height[index];
    }
    if(parent[index] == -1)
    {
        height[index] = 1;
    }
    else
    {
       height[index] = 1 + findHeight(parent[index],height,parent);
    }

    return height[index];
}

int main(int argc, char** argv)
{

    int parent[9] = {-1,0,0,2,1,1,1,2,7};
    cout << treeHeight(parent,sizeof(parent)/sizeof(int)) << endl;
}

