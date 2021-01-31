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
    deque<TreeNode *> deque;
    vector<vector<int>> res;
    if (root != NULL)
        deque.push_back(root);
    while (!deque.empty())
    {
        vector<int> tmp;
        for (int i = deque.size(); i > 0; i--)
        {
            TreeNode *node = deque.front();
            deque.pop_front();
            tmp.push_back(node->val);
            if (node->left != NULL)
                deque.push_back(node->left);
            if (node->right != NULL)
                deque.push_back(node->right);
        }
        res.push_back(tmp);
        if (deque.empty())
            break;
        tmp.clear();
        for (int i = deque.size(); i > 0; i--)
        {
            TreeNode *node = deque.back();
            deque.pop_back();
            tmp.push_back(node->val);
            if (node->right != NULL)
                deque.push_front(node->right);
            if (node->left != NULL)
                deque.push_front(node->left);
        }
        res.push_back(tmp);
    }
    return res;
}