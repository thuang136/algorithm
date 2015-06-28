#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(int argc,char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_cryptographic.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    unsigned int matrix[50][4];

    const int code[10] = { 13,25,19,61,35,49,47,59,55,11};
    int t = 0 ;
    for(; t < T; t++)
    {
        memset(matrix,0,sizeof(matrix));
    
        int N,M;

    cin >> N >> M;

    int start = -1;
    int end = -1;

    for(int i = 0 ; i < N ; i++)
    {
            for(int j = 0 ; j < M ; j++)
            {
                char digit;
        cin >> digit;
                matrix[i][j/32] = matrix[i][j/32] | ((digit - '0')<<(j%32));
            }

        // check��ֹ�к�
        if(start == -1)
        {
        for(int k = 0 ; k < 4; k++)
        {
            if(matrix[i][k] != 0)
            {
            start = i;
            end = start;
            break;
            }
        }
        }
        else
        {
             bool same = true;
                 for(int k = 0 ; k < 4; k++)
                 {
                     if(matrix[i][k] != matrix[end][k])
                     {
                         same = false;
             break;
                     }
                 }
         if(same)
         {
                     end = i;
         }
        }
    
    }

    //�����ص��[start,end]֮�������������Ϊ����һ���ģ�ȡ��һ�оͿ����ˣ����綼��start��

    int lineNum = end - start + 1;

    int lastPos = -1;

    int array[8];
    int arrIdx = 7;

    if(lineNum >= 5 && lineNum <= 50)
    {
           //��Щ��������������һλ����1���ҵ���һ��1��Ȼ��ȡ��7λ��
           int val = 0;
       int idx = 0;
       for(int i = M-1 ; i >= 0 ; i--)
           {
               if(lastPos != -1)
               {
                  idx++;
                  if(idx == 7)
                  {
                      idx = 0;
              int resIdx = 0;
              for(; resIdx < 10; resIdx ++)
              {
                          if(val == code[resIdx])
                          {
                              break;
                          }
              }

              array[arrIdx--] = resIdx;
              
              val = 0;
                  }
               }
               if( matrix[start][i/32] & ( 1 << (i %32)) )
               {
                   if( lastPos == -1)
                   {
                       lastPos = i;
               //���˴ӵ�ǰλ��ÿ��7λ����һ����
               idx = 0;
               val = 1;
                   }
           else
           {
                       val = val | ( 1 << idx);
           }
               }
           }

       // �������array

       int checkSum = 0;
       int sum = 0;

       for(int i = 0 ; i < 7; i++)
       {
               if( i % 2 == 0)
               {
                   checkSum += array[i] * 3;
               }
           else
           {
                   checkSum += array[i];
           }

           sum += array[i];
       }

       sum += array[7];
       

       if((checkSum + array[7]) % 10 == 0)
       {
               cout << "#" << t << " " << sum << endl;
       }
       else
       {
               cout << "#" << t << " " << 0 << endl;
       }
       
           
    }

    }

}

