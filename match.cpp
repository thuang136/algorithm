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

    用最朴素的字符串匹配


    */

    int targetSize = target.size();
    int patternSize = pattern.size();

    int targetIdx = 0;   // 表示pattern的首字母在target中的位置
    int patternIdx = 0;  // 当前匹配到模式串中的什么位置

    // targetIdx最后的位置，最多是   targetSize - patternSize

    int matchCount = 0;

    for(; targetIdx <= (targetSize - patternSize) ; targetIdx++)
    {
        // 当前targetIdx与patternIdx的0位置开始匹配

        patternIdx = 0; //模式串当前的位置

        int curIdx = 0; // 当前这次匹配过程中，在目标串相对开始位置索引

        // 什么情况下可以继续往前匹配 字母匹配，或者字母虽然不匹配，但是当前pattern的字母为#

        while(targetIdx + curIdx < targetSize && patternIdx < patternSize)
        {

            if(target[targetIdx+curIdx] ==  pattern[patternIdx]  || pattern[patternIdx] == '#')
            {

                //完全是字符匹配
                if(target[targetIdx+curIdx] ==  pattern[patternIdx])
                {

                    // check一下是否是匹配到模式的最后一个位置
                    if(patternIdx + 1 ==  patternSize)
                    {
                        // 此时完成一次匹配，需要检验匹配到是的否是回文
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
                    // 这里可能出现二种情况
                    // 1, target的下一个位置，和pattern的下一个位置匹配
                    // 2. target的下一个位置，和pattern的下个位置不匹配

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

    // 匹配target中的所有回文

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

