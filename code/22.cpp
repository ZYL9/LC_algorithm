#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    queue<TreeNode *> que;
    int cnt = 0;
    que.push(root);
    while (!que.empty())
    {
        vector<int> tmp;
        for (int i = que.size(); i > 0; --i)
        {
            root = que.front();
            que.pop();
            tmp.push_back(root->val);
            if (root->left)
                que.push(root->left);
            if (root->right)
                que.push(root->right);
        }
        res.push_back(tmp);
    }
    return res;
}