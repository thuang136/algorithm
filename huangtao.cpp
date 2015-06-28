#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MAX_HEIGHT 2000
#define MAX_WIDTH 500


 
struct Block
{
    char row[MAX_WIDTH];
    int width;
    int height;
};


const string hex_binary[16] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};


int codeDataMap[10][4] = {

    {3,2,1,1},
    {2,2,2,1},
    {2,1,2,2},
    {1,4,1,1},
    {1,1,3,2},
    {1,2,3,1},
    {1,1,1,4},
    {1,3,1,2},
    {1,2,1,3},
    {3,1,1,2}

};


/*
    ����ģʽ��ȥƥ��õ�����
*/
int match(int pattern[4],int codeIdx)
{
    int resultIdx = -1;

    int checkIdx = 0;

    if(codeIdx == 0)  //���ƥ�䵽8������������ǰλ��ֻcheckģʽ�ĺ���λ
    {
        checkIdx = 1;
    }

    for(int k = 0 ; k < 10 ; k++)
    {
        float div[4];
        bool match = true;
        for(int idx = 0 ; idx < 4; idx++)
        {
            div[idx] = 1.0f * pattern[idx]/ codeDataMap[k][idx];
            if(idx > checkIdx && div[idx] != div[idx-1])
            {
                match = false;
                break;
            }
        }
        if(match)
        {
            if(checkIdx == 1)
            {
                //��Ҫcheckһ����ǰ��0��λ��������
                if(pattern[0] >= codeDataMap[k][0] * div[1])
                {
                    resultIdx = k;
                }
            }
            else
            {
                resultIdx = k;
            }
            break;
        }
    }

    return resultIdx;

}

/*
    ��ô����ÿ��Block?

    ����16����ת��Ϊ2���ƣ�������1,0�ĸ���������Щ������ֵ


*/

int  convert(const Block& block)
{
    int sum = 0;
    string hex_binary_str = "";
    for(int i = 0 ; i < block.width; i++)
    {
        int idx;
        if(block.row[i] >= 'A' && block.row[i] <= 'F')
        {
            idx = block.row[i] - 'A' + 10;
        }
        else if( block.row[i] >= '0' && block.row[i] <= '9')
        {
            idx = block.row[i] - '0';
        }

        hex_binary_str += hex_binary[idx];
    }

    cout << "01 string: " << hex_binary_str << endl;

    //�Ӻ���ǰ�ҵ���һ��1��ʼ��
    bool firstFlag = false; //�Ƿ������˵�һ��1
    int right = -1; // 1 ���� 0���ұ߽�
    int countGroup[4]; //ÿ�ĸ�һ��������
    int countIdx = 3; //��ǰgroupIdx�±�
    int code[8]; //��8�������ɵļ����
    int codeIdx = 7;
    for(int i = hex_binary_str.length() - 1; i >= 0 ; i--)
    {
        if(!firstFlag && hex_binary_str[i] == '1')
        {
            firstFlag = true;
            right = i;
        }
        else
        {
            if(firstFlag)
            {
                if(hex_binary_str[i] != hex_binary_str[right] || i== 0)
                {
                    int count = 0;
                    if( i != 0)
                    {
                         count = right - i;
                    }
                    else
                    {
                         count = right + 1;
                    }

                    right = i;
                    countGroup[countIdx--] = count;
                    //cout << endl << "count : " << count << endl;
                    if(countIdx < 0)
                    {
                        countIdx = 3;
                        //һ����Ԫ����װ��
                        code[codeIdx] = match(countGroup,codeIdx);
                        cout << code[codeIdx] << " ";
                        codeIdx--;
                        if(codeIdx < 0)
                        {
                            codeIdx = 7;
                            //ƥ���һ������룬checkһ��
                            int codeSum = 0;
                            int actualSum = 0;
                            for(int k = 0 ; k < 8 ; k++)
                            {
                                if( k % 2 == 0)
                                {
                                    codeSum += code[k] * 3;
                                }
                                else
                                {
                                    codeSum += code[k];
                                }
                                actualSum += code[k];
                            }

                            if(codeSum % 10 == 0)
                            {
                                sum += actualSum;
                                cout << endl << actualSum << endl;
                            }

                            

                            firstFlag = false;
                        
                        }
                    }
                }
            }
        }

    }
    cout << endl;
    return sum;
}


int main(int argc, char** argv)
{

   const char* INPUTFILE("../res/test-case/sample_input_cryptographics2.txt");
   freopen(INPUTFILE,"r",stdin);

   const char* OUTPUTFILE("sample_output_cryptographicsExt.txt");
   freopen(OUTPUTFILE,"w",stdout);

   int T;
   cin >> T;

   

   for(int t = 0 ; t < T; t++)
   {
       char array[MAX_HEIGHT][MAX_WIDTH+1];
       int N,M;
       cin >> N >> M;
       vector<Block> blockVec;

       int prevRow = 0;

       //��ȡ���ݣ���ȡ����Ϣ

       for(int i = 0 ; i < N; i++)
       {
           int j = 0;
           for(; j < M; j++)
           {
               cin >> array[i][j];
           }
           array[i][j] = '\0';
           if( i == 0)
           {
               prevRow = 0;
               Block block;
               strcpy(block.row,array[i]);
               block.width = M;
               block.height = 1;
               blockVec.push_back(block);
           }
           else
           {
               if(strcmp(blockVec[prevRow].row,array[i]) == 0)
               {
                   blockVec[prevRow].height++;
               }
               else
               {
                   Block block;
                   strcpy(block.row,array[i]);
                   block.width = M;
                   block.height = 1;
                   blockVec.push_back(block);
                   prevRow++;
               }
           }
       }

       /*
       for(int i = 0 ; i < blockVec.size(); i++)
       {
           cout << blockVec[i].row << endl;
       }
       cout << endl;
       */

       int countSum = 0;
       for(int i = 0 ; i < blockVec.size(); i++)
       {
           countSum += convert(blockVec[i]);
       }
        cout << "#" << t+1 << " " << countSum << endl;
       
   }


}
