#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x),left(NULL),right(NULL) {}

};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;

    if(root == NULL)
    {
        return result;
    }

    //用二个vector交替存储上一行和下一行元素
    queue<TreeNode*> top;
    queue<TreeNode*> down;
    top.push(root);
    result.push_back(root->val);
        while(!top.empty())
        {
            while(!top.empty())
            {
                TreeNode* node = top.front();
                top.pop();
            
                if(node->left)
                {
                    down.push(node->left);
                }
                if(node->right)
                {
                    down.push(node->right);
                }
            }
        if(!down.empty())
        {
                TreeNode* rightMost = down.back();
                result.push_back(rightMost->val);
        }
        while(!down.empty())
        {
                TreeNode* downNode = down.front();
        top.push(downNode);
        down.pop();
        }
    }
    
    return result;

    }

};

int main(int argc, char** argv)
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;

    node2->right = node5;
    node3->right = node4;

    Solution s;

    vector<int> result = s.rightSideView(node1);

    cout << "[";
    for(int i = 0 ; i < result.size(); i++)
    {
        cout << result[i];
        if( i < result.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

