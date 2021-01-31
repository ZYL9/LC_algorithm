#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return root == nullptr || recur(root->left, root->right);
    }

private:
    bool recur(TreeNode *l, TreeNode *r)
    {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        return l->val == r->val && recur(l->left, r->right) && recur(l->right, r->left);
    }
};