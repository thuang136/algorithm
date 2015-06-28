/*

Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time 
and uses O(h) memory, where h is the height of the tree.

*/

#include<iostream>
#include<stack>
using namespace std;

struct TreeNode
{
    int val;

    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL),right(NULL) {}

};


/*

BST�Ƕ�����������������ϵ�Ԫ�ض�С�ڸ��ڵ㣬�������ϵ�Ԫ�ش��ڸ��ڵ�
�����������������������Ĵ���,����һ����С�����˳��

*/


class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        TreeNode* pCurNode = root;
    while(pCurNode)
    {
            nodeStack.push(pCurNode);
        pCurNode = pCurNode->left;
    }
    }

    bool hasNext()
    {
        //ջ�ձ�ʾû�нڵ�Ҫ������
        return !nodeStack.empty();
    }

    int next()
    {
        //ÿ�ν�next()��ʱ�򣬶���֤��ǰ�ڵ���������,�����������Ѿ�û�нڵ���
        TreeNode* pCurNode = nodeStack.top();
    int value = pCurNode->val;
    

    //��������������������ǰ�ڵ㣬
    pCurNode = pCurNode->right;
    nodeStack.pop();

        //�����������Ϊ�գ����������·������нڵ����μ���ջ
        while(pCurNode != NULL)
        {
            nodeStack.push(pCurNode);
            pCurNode = pCurNode->left;
        }
    
    return value;
    }

private:
    stack<TreeNode*> nodeStack;
};


int main(int argc, char** argv)
{
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(5);    
    TreeNode* node7 = new TreeNode(7);    
    TreeNode* node11 = new TreeNode(11);
    TreeNode* node13 = new TreeNode(13);

    node6->left = node3;
    node6->right = node9;
    node3->left = node2;
    node3->right = node5;

    node9->left = node7;
    node9->right = node11;

    node11->right = node13;

    BSTIterator iter = BSTIterator(node6);
    while( iter.hasNext())
    {
        cout << iter.next() << endl;
    }


}

