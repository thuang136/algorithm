/*


Description
The French author Georges Perec (1936-1982) once wrote a book, La disparition, without the letter 'e'. He was a member of the Oulipo group. A quote from the book:
Tout avait Pair normal, mais tout s'affirmait faux. Tout avait Fair normal, d'abord, puis surgissait l'inhumain, l'affolant. Il aurait voulu savoir où s'articulait l'association qui l'unissait au roman : stir son tapis, assaillant à tout instant son imagination, l'intuition d'un tabou, la vision d'un mal obscur, d'un quoi vacant, d'un non-dit : la vision, l'avision d'un oubli commandant tout, où s'abolissait la raison : tout avait l'air normal mais…
Perec would probably have scored high (or rather, low) in the following contest. People are asked to write a perhaps even meaningful text on some subject with as few occurrences of a given "word" as possible. Our task is to provide the jury with a program that counts these occurrences, in order to obtain a ranking of the competitors. These competitors often write very long texts with nonsense meaning; a sequence of 500,000 consecutive 'T's is not unusual. And they never use spaces.
So we want to quickly find out how often a word, i.e., a given string, occurs in a text. More formally: given the alphabet {'A', 'B', 'C', …, 'Z'} and two finite strings over that alphabet, a word W and a text T, count the number of occurrences of W in T. All the consecutive characters of W must exactly match consecutive characters of T. Occurrences may overlap.
Input
The first line of the input file contains a single number: the number of test cases to follow. Each test case has the following format:
"    One line with the word W, a string over {'A', 'B', 'C', …, 'Z'}, with 1 ≤ |W| ≤ 10,000 (here |W| denotes the length of the string W). 
"    One line with the text T, a string over {'A', 'B', 'C', …, 'Z'}, with |W| ≤ |T| ≤ 1,000,000.
Output
For every test case in the input file, the output should contain a single number, on a single line: the number of occurrences of the word W in the text T.
Sample Input
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
Sample Output
1
3
0


*/

/*
void GetNext(string pattern, int next[])
{
    int patternSize = pattern.size();

    int j, k;

    next[0] = 0;

    k = 0;

    for( j = 1 ; j < patternSize; j++)
    {
        while( k > 0 && pattern[j] != pattern[k])
        {
            k = next[k];
        }

        if(pattern[j] == pattern[k])
        {
            k++;
        }

        next[j] = k;

    }
}
*/


#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;


void  GetNext(string pattern, int next[])
{
    int patternSize = pattern.size();

    next[0] = -1;

    int k = -1;

    int j = 0;

    while( j < patternSize)
    {
         if( k == -1 || pattern[j] == pattern[k])
         {
             ++k;
             ++j;
             next[j] = k;
         }
         else
         {
             k = next[k];
         }

    }



}


int matchCount(string text, string pattern)
{
    int textSize = text.size();
    int patternSize = pattern.size();

    int textIdx = 0;  //模式串的0下标，在正文串中的位置
    int patternIdx = 0; //模式串当前匹配到的索引

    int* next = new int[patternSize+1];
    GetNext(pattern,next);

    int count = 0;
    while(textIdx < textSize)
    {
        if(patternIdx <= patternSize)
        {
            if(text[textIdx] == pattern[patternIdx] || patternIdx == -1)
            {
                patternIdx++;
                textIdx++;
                if(patternIdx == patternSize)
                {
                    count++;
                }
            }
    
            else
            {
                patternIdx = next[patternIdx];
            }
        }

    }

    return count;

}





/*
int matchCount(string text, string pattern)
{
    int textSize = text.size();
    int patternSize = pattern.size();

    int textIdx = 0;  //模式串的0下标，在正文串中的位置
    int patternIdx = 0; //模式串当前匹配到的索引

    int count = 0;
    while(textIdx < textSize)
    {
        if(patternIdx < patternSize)
        {
            if(text[textIdx + patternIdx] == pattern[patternIdx])
            {
                patternIdx++;
            }
    
            else
            {
                textIdx++;
                patternIdx = 0;
            }
        }
        else
        {
            count++;
            patternIdx = 0;
            textIdx++;
        }

    }

    return count;

}

*/


int main(int argc, char** argv)
{
    
    const char* INPUTFILE("../res/test-case/sample_input_strtest.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    for(int i = 0 ; i < T; i++)
    {
        string pattern, text;
        cin >> pattern;
        cin >> text;

        cout << matchCount(text,pattern) << endl;
    }


}

