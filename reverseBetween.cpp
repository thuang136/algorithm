#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL) {}

};

/*

Given 1->2->3->4->5->NULL m = 2 and n = 4


return 1->4->3->2->5->NULL


*/


class Solution
{
public:
       ListNode* reverseBetween(ListNode* head, int m, int n)
       {
           ListNode* result =  NULL;
           ListNode* p = head;
           ListNode* left = NULL;
           int i = 1;
           for( ; i < m ; i++)
           {
               left = p;
               p = p->next;
           }

           ListNode* subRight = p;
           ListNode* r = NULL;

           for(; i <= n; i++)
           {
               ListNode* q = p->next;

               p->next = r;

               r = p;

               p = q;
           }

           if(left != NULL)
           {
               left->next = r;
               result = head;
           }
           else
           {
               result = r;
               subRight = head;
           }
           
           subRight->next = p;

           return result;
       }

};

int main(int argc, char** argv)
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution s;
    ListNode* newHead = s.reverseBetween(node1,2,5);

    ListNode* p = newHead;

    while( p!= NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

}


