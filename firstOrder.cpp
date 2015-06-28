#include<iostream>
#include<stack>
using namespace std;


struct Node
{
    Node(char ch)
    {
        c = ch;
    left = NULL;
    right = NULL;
    }
    char c;
    Node* left;
    Node* right;
};


void preOrder(Node* root)
{
    if(!root)
    {
        return;
    }

    stack<Node*> nodeStack;

    nodeStack.push(root);

    while(!nodeStack.empty())
    {
        Node* pNode = nodeStack.top();

    cout << pNode->c;

    nodeStack.pop();

    if(pNode->right) 
    {
            nodeStack.push(pNode->right);
    }
    if(pNode->left)
    {
            nodeStack.push(pNode->left);
    }
    }
    
}

int main(int argc, char** argv)
{

   Node* pNodeA = new Node('A');
   Node* pNodeB = new Node('B');
   Node* pNodeC = new Node('C');
   Node* pNodeD = new Node('D');
   Node* pNodeE = new Node('E');
   Node* pNodeF = new Node('F');

   pNodeB->left = pNodeD;
   pNodeC->left = pNodeE;
   pNodeC->right = pNodeF;
   pNodeA->left = pNodeB;
   pNodeA->right = pNodeC;

   preOrder(pNodeA);


}


