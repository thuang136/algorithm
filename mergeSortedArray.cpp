#include<iostream>
using namespace std;

class Solution
{

public:

       void merge(int A[], int m, int B[], int n)
       {
           int* pC = new int[m+n];

           int i = 0;
           int j = 0;

           int k = 0;

           while( i < m && j < n)
           {
               if(A[i] <= B[j])
               {
                   pC[k++] = A[i++];

               }
               else
               {
                   pC[k++] = B[j++];
               }
           }

           while( i < m)
           {
               pC[k++] = A[i++];
           }

           while( j < n)
           {
               pC[k++] = B[j++];
           }

           for(i = 0 ; i < k; i++)
           {
               A[i] = pC[i];
           }

       }


};

int main(int argc, char** argv)
{
    return 0;
}
