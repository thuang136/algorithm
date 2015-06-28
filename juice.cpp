/*



Mr. Kim has made healthy juice for his colleagues.

This has been made of 100% natural vitamin C especially for overcoming fatigue.

With powder from various natural fruits in it, it has diverse colors, prices and weights.

Mr. Kim has poured various kinds of powder in a cup to make a special colored cup of juice.

If you know the price and weight of each bag of powder and the weight of the filled cup of juice,

create a calculation program to find out the lowest cost used for making the cup of juice.

Time limits : 1 second (java: 2 seconds)

Input Format

Input may include many test cases. The number of test cases, T, is given on the first line of input and then the amount of T of test cases is given in a line. (T ¡Ü 20)
The weight of the empty cup, E, and the weight of the filled cup of juice, F, are given separately as blanks for the first line of each test case. (1 ¡Ü E ¡Ü F ¡Ü 10,000)
The number of kinds of juice that is used, N, is given for the next line. (1 ¡Ü N ¡Ü 500)
From the next line through to the amount of N lines,
the unit price and weight of each juice is given separately as blanks.

The unit price of juice is positive number ¡Ü 50,000; and the weight is positive number ¡Ü 10,000.

Output Format

Output the minimum cost of cases for the first line of each test case. If you can not make it, output "impossible".

Input Example

3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 5
2
10 3
20 4

Output Example

60
100
20




*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct JUICE
{
     int price;
     int weight;
};

JUICE* juices = NULL;
int N;

const int MAX = 10000;
int price[MAX];

int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_juice.txt");
    freopen(INPUTFILE,"r",stdin);

    int T;
    cin >> T;

    const int INFINIT = 999999;

    for(int t = 0 ; t < T ; t++)
    {
        int E,F;
        cin >> E >> F;
        
        cin >> N;
        
        juices = new JUICE[N];
        
        for(int i = 0 ; i < N; i++)
        {
            cin >> juices[i].price >> juices[i].weight;
        }

        for(int i = 1; i <= (F-E); i++)
        {
            price[i] = INFINIT;
        }

        for(int i = 0 ; i < N; i++)
        {
            for(int k = juices[i].weight; k <= (F-E); k++)
            {
                price[k] = std::min(price[k],price[k - juices[i].weight] + juices[i].price);
            }
        }

        if(price[F-E] == INFINIT)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << price[F-E] << endl;
        }
        
    }

}


