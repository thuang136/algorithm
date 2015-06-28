#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char** argv)
{
  FILE* fp = NULL;
  const char* INPUTFILE("../res/test-case/sample_input_ok.txt");
  fp = fopen(INPUTFILE,"r");

  int iArr[10];


  int len = fread(iArr,sizeof(int),5,fp);

  cout << "len is " << len << endl;

  for(int i = 0; i < 5; i++)
  {
      cout << iArr[i] << endl;
  }

  fclose(fp);

  if(fp != NULL)
  {
      printf("fp is not null\n");
  }
  return 0;
}
