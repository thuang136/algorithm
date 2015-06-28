/*



Description
In order to get from one of the F (1 <= F <= 5,000) grazing fields (which are numbered 1..F) to another field, 

Bessie and the rest of the herd are forced to cross near the Tree of Rotten Apples. The cows are now tired of often being forced to take a particular path and 

want to build some new paths so that they will always have a choice of at least two separate routes between any pair of fields. 

They currently have at least one route between each pair of fields and want to have at least two. 

Of course, they can only travel on Official Paths when they move from one field to another.

Given a description of the current set of R (F-1 <= R <= 10,000) paths that each connect exactly two different fields, 

determine the minimum number of new paths (each of which connects exactly two fields) 

that must be built so that there are at least two separate routes between any pair of fields. 

Routes are considered separate if they use none of the same paths, even if they visit the same intermediate field along the way.

There might already be more than one paths between the same pair of fields, and you may also build a new path that connects the same fields as some other path.
Input
Line 1: Two space-separated integers: F and R

Lines 2..R+1: Each line contains two space-separated integers which are the fields at the endpoints of some path.
Output
Line 1: A single integer that is the number of new paths that must be built.
Sample Input
7 71 22 33 42 54 55 65 7
Sample Output
2
Hint
Explanation of the sample:

One visualization of the paths is:
   1   2   3
   +---+---+  
       |   |
       |   |
 6 +---+---+ 4
      / 5
     / 
    / 
 7 +
Building new paths from 1 to 6 and from 4 to 7 satisfies the conditions.
   1   2   3
   +---+---+  
   :   |   |
   :   |   |
 6 +---+---+ 4
      / 5  :
     /     :
    /      :
 7 + - - - - 
Check some of the routes:
1 �C 2: 1 �C> 2 and 1 �C> 6 �C> 5 �C> 2
1 �C 4: 1 �C> 2 �C> 3 �C> 4 and 1 �C> 6 �C> 5 �C> 4
3 �C 7: 3 �C> 4 �C> 7 and 3 �C> 2 �C> 5 �C> 7
Every pair of fields is, in fact, connected by two routes.

It's possible that adding some other path will also solve the problem (like one from 6 to 7). Adding two paths, however, is the minimum.



*/

#include<iostream>
using namespace std;

int main(int argc, char** argv)
{



}
