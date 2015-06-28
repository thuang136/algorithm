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

BST是二叉查找数，左子数上的元素都小于根节点，右子数上的元素大于根节点
按照左子树，根，右子树的次序,就是一个从小到大的顺序

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
        //栈空表示没有节点要访问了
        return !nodeStack.empty();
    }

    int next()
    {
        //每次进next()的时候，都保证当前节点是最左下,则其左子树已经没有节点了
        TreeNode* pCurNode = nodeStack.top();
    int value = pCurNode->val;
    

    //保存完右子树，弹出当前节点，
    pCurNode = pCurNode->right;
    nodeStack.pop();

        //如果右子树不为空，将其沿左下方的所有节点依次加入栈
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

