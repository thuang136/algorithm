/*

In our company, there is a popular meeting room.
Many meetings are reserved to use this room with starting time and finishing time, and the place can’t hold two meetings at the same time if the time is overlapped.

Thus only one of the same time-framed meetings can be held in here and the others should give up.

However, it is not overlapped for the same starting time of a meeting and the finishing time of another meeting.
When the number of meetings, starting time and finishing time of each meetings are given, you want to hold as many meetings as possible.
\In a given number of meetings and each given starting/finishing time, you want to hold as many meetings as possible.

Create a program that can assign meetings to the meeting room as many as it can.

Time limit: 1 second (java: 2 seconds)

Input format

Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 20) are given in a row.
N, the number of meetings is given in the first row of each test case (1 ≤ N ≤ 500).
Numbers of each meeting, starting time, and finishing time are given separately from the second row to the number of N. (Each number is natural numbers below 500)

Output format

Output the maximum number of meetings which can assign in the first row of each test case.

Example of Input

2
6
1 1 10
2 5 6
3 13 15
4 14 17
5 8 14
6 3 12
15
1 4 8
2 2 5
3 2 6
4 4 6
5 2 3
6 1 6
7 4 7
8 3 5
9 3 8
10 1 2
11 1 7
12 2 4
13 5 6
14 4 5
15 7 8

Example of Output

3
5


*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct _meeting
{
    int idx;
    int start;
     int finish;
}MeetingInfo;

bool cmpFinish(MeetingInfo a, MeetingInfo b)
{
     return a.finish < b.finish;
}

int maxValue[501];

// 按结束时间排序后的会议， 可以安排第k个会议， 而是安排与第k个会议不相交的前几个会议， 然后取前k-1个会议
int maxHold(int k, MeetingInfo* infos)
{
   if( k < 0)
   {
       return 0;
   }

   if(maxValue[k] != -1)
   {
       return maxValue[k];
   }

   int i = k;
   while( --i >= 0)
   {
       if(infos[i].finish <= infos[k].start)
       {
           break;
       }
   }

   maxValue[k] = std::max( maxHold(i,infos) + 1, maxHold(k-1,infos) );

   return maxValue[k];

}

int main(int argc, char** argv)
{

    const char* INPUTFILE("../res/test-case/sample_input_meeting.txt");
    freopen(INPUTFILE,"r",stdin);

     int T, N;
     cin >> T;

     for(int t = 0; t < T; t++)
     {
        cin >> N;
        memset(maxValue,-1,sizeof(maxValue));
         MeetingInfo* meetingInfos = new MeetingInfo[N];

         for(int i = 0; i < N ; i++)
         {
            cin >> meetingInfos[i].idx;
              cin >> meetingInfos[i].start;
              cin >> meetingInfos[i].finish;
         }

         sort(meetingInfos,meetingInfos + N,cmpFinish);

          int holdNum = maxHold(N-1,meetingInfos);

          cout << holdNum << endl;

     }


}

