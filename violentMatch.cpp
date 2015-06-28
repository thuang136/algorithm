#include<iostream>
#include<cstring>
using namespace std;


int violentMatch(const char* target, const char* pattern)
{

    int targetLen = strlen(target);

    int patternLen = strlen(pattern);

    for(int targetPos = 0; targetPos <= (targetLen - patternLen); targetPos++)
    {
        int patternPos = 0;

    }

}


int main(int argc, char** argv)
{
   const char* target = "huangtao";
   const char* pattern = "tao";

   violentMatch(target,pattern);

}

