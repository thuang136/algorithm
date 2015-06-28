#include<iostream>
using namespace std;

struct ListNode
{
    int val;

    ListNode* next;

    ListNode(int x) : val(x),next(NULL) {}

};

class Solution
{

public:

       ListNode* reverseList(ListNode* head)
       {
           ListNode* r = NULL;
           ListNode* p = head;

           // p指向当前要反转的节点， 为了反转后，不丢失原节点的下个节点，用q保存

           while( p != NULL)
           {
                ListNode* q = p->next;

                p->next = r;

                r = p;

                p = q;

           }

           return r;

       }

};


int main(int argc ,char** argv)
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution s;
    ListNode* newHead = s.reverseList(node1);

    ListNode* p = newHead;

    while( p!= NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }

}


