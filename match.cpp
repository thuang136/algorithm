#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

bool palindrome(string target,int f , int r)
{


    bool result = false;

    while(f <= r)
    {
       if(target[f] != target[r])
       {
           break;
       }

       f++;
       r--;
    }

    if( f > r)
    {
        result = true;
    }

    return result;
}

int match(string target, string pattern)
{

    /*

    �������ص��ַ���ƥ��


    */

    int targetSize = target.size();
    int patternSize = pattern.size();

    int targetIdx = 0;   // ��ʾpattern������ĸ��target�е�λ��
    int patternIdx = 0;  // ��ǰƥ�䵽ģʽ���е�ʲôλ��

    // targetIdx����λ�ã������   targetSize - patternSize

    int matchCount = 0;

    for(; targetIdx <= (targetSize - patternSize) ; targetIdx++)
    {
        // ��ǰtargetIdx��patternIdx��0λ�ÿ�ʼƥ��

        patternIdx = 0; //ģʽ����ǰ��λ��

        int curIdx = 0; // ��ǰ���ƥ������У���Ŀ�괮��Կ�ʼλ������

        // ʲô����¿��Լ�����ǰƥ�� ��ĸƥ�䣬������ĸ��Ȼ��ƥ�䣬���ǵ�ǰpattern����ĸΪ#

        while(targetIdx + curIdx < targetSize && patternIdx < patternSize)
        {

            if(target[targetIdx+curIdx] ==  pattern[patternIdx]  || pattern[patternIdx] == '#')
            {

                //��ȫ���ַ�ƥ��
                if(target[targetIdx+curIdx] ==  pattern[patternIdx])
                {

                    // checkһ���Ƿ���ƥ�䵽ģʽ�����һ��λ��
                    if(patternIdx + 1 ==  patternSize)
                    {
                        // ��ʱ���һ��ƥ�䣬��Ҫ����ƥ�䵽�ǵķ��ǻ���
                        if( palindrome(target,targetIdx,targetIdx + curIdx) )
                        {
                            matchCount++;
                        }

                        patternIdx--;


                        continue;
                    }
                    else
                    {
                        curIdx++;
                        patternIdx++;
                    }
                }
                else if(pattern[patternIdx] == '#')
                {
                    // ������ܳ��ֶ������
                    // 1, target����һ��λ�ã���pattern����һ��λ��ƥ��
                    // 2. target����һ��λ�ã���pattern���¸�λ�ò�ƥ��

                    if(targetIdx + curIdx + 1 < targetSize && patternIdx + 1 < patternSize )
                    {
                        if(target[targetIdx + curIdx + 1] == pattern[patternIdx+1])
                        {
                           patternIdx++;
                        }
                    }

                    curIdx++;
                }

            }

            else
            {
                break;
            }

        }

    }


    return matchCount;


}


int matchAll(string target)
{

    // ƥ��target�е����л���

    int count = 0;

    int size = target.size();

    for(int i = 2; i <= size; i++)
    {
        for(int j = 0 ; j <= size - i; j++)
        {
             if(palindrome(target,j,j+i-1))
             {
                 count++;
             }
        }
    }

    return count;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
    The freopen function below opens input.txt in read only mode and
    sets your standard input to work with the opened file.
    When you test your code with the sample data, you can use the function
    below to read in from the sample data file instead of the standard input.
    So. you can uncomment the following line for your local test. But you
    have to comment the following line when you submit for your scores.
    */

    const char* INPUTFILE("../res/test-case/sample_input_match.txt");
    freopen(INPUTFILE,"r",stdin);

    cin>>T;

    /*
       Read each test case from standard input.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
            Please, implement your algorithm from this section.
        */
        /////////////////////////////////////////////////////////////////////////////////////////////

        string pattern, target;

        cin >> pattern >> target;

        int answer = 0;

        if(pattern == "#")
        {
            answer = matchAll(target);
        }
        else
        {
            answer = match(target,pattern);
        }

        // Print the answer to standard output(screen).
        cout << "#" << test_case <<" " <<  answer << endl;
    }
    return 0;//Your program should return 0 on normal termination.
}

