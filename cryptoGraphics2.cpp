#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

#define MAX_HEIGHT 2000
#define MAX_WIDTH 500

struct Block
{
    int left;
    int top;
    int width;
    int height;
    char code[MAX_WIDTH];
};

struct CodeDataMap
{
    int crypto[4];
    int num;
};

string hex_binary[16] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};

CodeDataMap codeDataMap[10] = {

{{3,2,1,1},0},
{{2,2,2,1},1},
{{2,1,2,2},2},
{{1,4,1,1},3},
{{1,1,3,2},4},
{{1,2,3,1},5},
{{1,1,1,4},6},
{{1,3,1,2},7},
{{1,2,1,3},8},
{{3,1,1,2},9}

};

string binaryStr(const Block& block)
{
    string result = "";

    for(int i = 0 ; i < block.width; i++)
    {
        int idx;
        if(block.code[i] >= 'A' && block.code[i] <= 'F')
        {
            idx = block.code[i] - 'A' + 10;
        }
        else if( block.code[i] >= '0' && block.code[i] <= '9')
        {
            idx = block.code[i] - '0';
        }

        result += hex_binary[idx];
    }

    return result;
}

int match(vector<int> countVec)
{
    //每隔4个取一组去匹配
    vector<int> resultVec;

    for(int i = 0 ; i < countVec.size(); )
    {
        if( i % 4 == 0)
        {
             int array[4];
             for(int j = 0 ; j < 4; j++)
             {
                 array[3 - j] = countVec[i+j];
             }

             
             int checkIdx = 0;

             
             if( i + 4 == countVec.size())
             {
                 checkIdx = 1;
             }
             

             for(int k = 0 ; k < 10 ; k++)
             {
                 int div[4];
                 bool match = true;
                 for(int idx = 0 ; idx < 4; idx++)
                 {
                     div[idx] = array[idx]/codeDataMap[k].crypto[idx];
                     if(idx > checkIdx && div[idx] != div[idx-1])
                     {
                         match = false;
                     }
                 }
                 if(match)
                 {
                     resultVec.push_back(k);
                     cout << k << " ";
                     break;
                 }
             }

             i = i + 4;
        }
    }

    cout << endl;
    int sum = 0;
    int retSum = 0;
    int resultSize = resultVec.size();
    for(int i = 0 ; i < resultSize ; i++)
    {
        if( i % 2 == 0)
        {
            sum = sum + resultVec[resultSize - 1 - i] * 3;
        }
        else
        {
            sum += resultVec[resultSize - 1 - i];
        }
        retSum += resultVec[i];
    }

    if( sum % 10 == 0)
    {
        //cout << retSum << endl;
        return retSum;
    }
    else
    {
        return 0;
    }
    

}


int  encode(string& pattern)
{
    int idx = pattern.size() - 1;
    while( pattern[idx] == '0')
    {
        idx--;
    }

    vector<int> countVec;
    //从idx起交替记录1,0个数
    int recentCode = '1';
    int count = 0;
    while(idx >= 0)
    {
        if(recentCode == pattern[idx])
        {
             count++;
        }
        else
        {
            //此时遇到一个不同，把上面的数记录下来
            if(recentCode == '1')
            {
                recentCode = '0';
            }
            else
            {
                recentCode = '1';
            }

            countVec.push_back(count);
            count = 1;
        }
        idx--;
    }

    countVec.push_back(count);
    
    int countVecSize = countVec.size();

    if(countVecSize % 4 == 3)
    {
         int matArr[4];
         //该补多少个0
         for(int matIdx = 0 ; matIdx < 3 ; matIdx++)
         {
             matArr[matIdx+1] = countVec[countVecSize-1-matIdx];
         }

         //用这三位去匹配
         
         for(int k = 0 ; k < 10 ; k++)
         {
             int div[4];
             bool match = true;
             for(int idx = 1 ; idx < 4; idx++)
             {
                 div[idx] = matArr[idx]/codeDataMap[k].crypto[idx];
                 if(idx > 1 && div[idx] != div[idx-1])
                 {
                     match = false;
                 }
             }
             if(match)
             {
                 countVec.push_back(codeDataMap[k].crypto[0] * div[1]);
                 break;
             }
         }

    }

    cout << countVecSize << endl;

    for(int i = 0 ; i < countVec.size(); i++)
    {
        cout << countVec[i] ;
    }
    cout << endl;
    
    int resultCode = match(countVec);

    return resultCode;
}





int main(int argc, char** argv)
{
    const char* INPUTFILE("../res/test-case/sample_input_cryptographics2.txt");
    freopen(INPUTFILE,"r",stdin);

    const char* OUTPUTFILE("sample_output_cryptographics2.txt");
    freopen(OUTPUTFILE,"w",stdout);

    int T;
    cin >> T;

    

    for(int t = 0 ; t < T; t++)
    {
        char array[MAX_HEIGHT][MAX_WIDTH];
        int N,M;
        cin >> N >> M;
        vector<Block> blockVec;

        for(int i = 0 ; i < N; i++)
        {
            for(int j = 0 ; j < M; j++)
            {
                cin >> array[i][j];
            }
        }

        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M; j++)
            {
                if(array[i][j] != '0')
                {
                     //以该点为左上点，取出块信息
                     Block block;
                     block.left = j;
                     block.top = i;

                     int width = 0;
                     int height = 0;
                     while( array[i][j+width] != '0')
                     {
                         block.code[width] = array[i][j+width];
                         width++;
                     }

                     while( array[i+height][j] != '0')
                     {
                         height++;
                     }

                     block.width = width;
                     block.height = height;

                     for(int m = 0 ; m < height; m++)
                     {
                         for(int n = 0 ; n < width; n++)
                         {
                             array[i+m][j+n] = '0';
                         }
                     }

                     blockVec.push_back(block);
                     
                }
            }
        }


        
        
        int retCode =  0;

        for(int block_Idx = 0 ; block_Idx < blockVec.size(); block_Idx++)
        {

            
            for(int codeIdx = 0 ; codeIdx < blockVec[block_Idx].width; codeIdx++)
            {
              cout << blockVec[block_Idx].code[codeIdx];
            }
            cout << endl;
           
            string result = binaryStr(blockVec[block_Idx]);

            cout << result << endl;
       

            //从后往前交替数1,0的个数，每数出4个数放到一个4元组
            retCode += encode(result);
        }



        cout << "#" << t+1 << " " << retCode << endl;

           
        

        //cout << endl;
    }

}

