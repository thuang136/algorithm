/*



Falling Leaves
Time Limit: 1000MSMemory Limit: 10000KTotal Submissions: 4005Accepted: 2221
Description

Figure 1
Figure 1 shows a graphical representation of a binary tree of letters. People familiar with binary trees can skip over the definitions of a binary tree of letters, leaves of a binary tree, and a binary search tree of letters, and go right to The problem.

A binary tree of letters may be one of two things:

    1. It may be empty.

    2. It may have a root node. A node has a letter as data and refers to a left and a right subtree. The left and right subtrees are also binary trees of letters.


In the graphical representation of a binary tree of letters:

    1. Empty trees are omitted completely.

    2. Each node is indicated by

        * Its letter data,

        * A line segment down to the left to the left subtree, if the left subtree is nonempty,

        * A line segment down to the right to the right subtree, if the right subtree is nonempty.



A leaf in a binary tree is a node whose subtrees are both empty. In the example in Figure 1, this would be the five nodes with data B, D, H, P, and Y.

The preorder traversal of a tree of letters satisfies the defining properties:

    1. If the tree is empty, then the preorder traversal is empty.

    2. If the tree is not empty, then the preorder traversal consists of the following, in order

        * The data from the root node,

        * The preorder traversal of the root's left subtree,

        * The preorder traversal of the root's right subtree.



The preorder traversal of the tree in Figure 1 is KGCBDHQMPY.

A tree like the one in Figure 1 is also a binary search tree of letters. A binary search tree of letters is a binary tree of letters in which each node satisfies:

The root's data comes later in the alphabet than all the data in the nodes in the left subtree.

The root's data comes earlier in the alphabet than all the data in the nodes in the right subtree.

The problem:

Consider the following sequence of operations on a binary search tree of letters

Remove the leaves and list the data removed
Repeat this procedure until the tree is empty
Starting from the tree below on the left, we produce the sequence of trees shown, and then the empty tree


BDHPY
CM
GQ
K
*
AC
B
$


*/

#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;

struct Node
{
    char letter;
    struct Node* left;
    struct Node* right;
};

Node* createTree(stack<string>& treeStack)
{
    Node* root = NULL;

    while(!treeStack.empty())
    {
        string level = treeStack.top();

        if(root == NULL && level.size() == 1)
        {
            root = new Node();
            root->letter = level[0];
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            //对level中的每个字母，自上而下找到它的parent
            for(int i = 0 ; i < level.size(); i++)
            {
                char curLetter = level[i];
                Node* parent = root;
                while(parent != NULL)
                {
                    if(curLetter < parent->letter)
                    {
                        if(parent->left == NULL)
                        {
                            parent->left = new Node();
                            parent->left->letter = curLetter;
                            parent->left->left = NULL;
                            parent->left->right = NULL;
                            break;
                        }
                        else
                        {
                            parent = parent->left;
                        }
                    }

                    else if(curLetter > parent->letter)
                    {
                        if(parent->right == NULL)
                        {
                            parent->right = new Node();
                            parent->right->letter = curLetter;
                            parent->right->left = NULL;
                            parent->right->right = NULL;
                            break;
                        }
                        else
                        {
                            parent = parent->right;
                        }
                    }

                }


            }

        }


        treeStack.pop();


    }

    return root;

}


void preOrder(Node* curNode)
{

   if(curNode)
   {
       cout << curNode->letter;
       preOrder(curNode->left);
       preOrder(curNode->right);
   }

}

int main(int argc, char** argv)
{
    const char* INPUTFILE("../res/test-case/sample_input_tree.txt");
    freopen(INPUTFILE,"r",stdin);

    // 读取每一层放入栈中

    stack<string> treeStack;

    string levelStr;
    cin >> levelStr;

    while(levelStr != "$")
    {
        if(levelStr == "*")
        {
            // 一个case读取完毕，处理
            Node* root = createTree(treeStack);
            preOrder(root);
            cout << endl;
        }
        else
        {
            treeStack.push(levelStr);
        }

        cin >> levelStr;
    }

    Node* root = createTree(treeStack);
    preOrder(root);



}



