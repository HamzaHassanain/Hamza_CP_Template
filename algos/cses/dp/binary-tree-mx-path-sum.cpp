#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    map<TreeNode *, int> dp;
    int dfs(TreeNode *node)
    {
        if (!node)
            return -1e9;

        if (dp.count(node))
            return dp[node];

        dp[node] = max({node->val + dfs(node->right), node->val + dfs(node->left), dfs(node->left), dfs(node->left)});
        return dp[node];
    }
    int maxPathSum(TreeNode *root)
    {
        dp[root] = dfs(root);
        return dp[root];
    }
};

int main()
{
}
