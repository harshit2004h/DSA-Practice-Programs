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

/*USING ARRAY*/
// int Solve(TreeNode *root, vector<int> &sum, int temp)
// {
//     if (root == NULL)
//         return 0;
//     temp += root->val;
//     if (root->left == NULL && root->right == NULL)
//     {
//         sum.push_back(temp);
//         return temp;
//     }
//     int left = Solve(root->left, sum, temp);
//     int right = Solve(root->right, sum, temp);
//     return left + right;
// }
// bool hasPathSum(TreeNode *root, int targetSum)
// {
//     vector<int> sum;
//     Solve(root, sum, 0);
//     if (find(sum.begin(), sum.end(), targetSum) != sum.end())
//         return true;
//     return false;
// }

/*USING SETS*/
int Solve(TreeNode *root, set<int> &sum, int temp)
{
    if (root == NULL)
        return 0;

    temp += root->val;

    if (root->left == NULL && root->right == NULL)
    {
        sum.insert(temp);
        return temp;
    }

    int left = Solve(root->left, sum, temp);
    int right = Solve(root->right, sum, temp);

    return left + right;
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    set<int> sum;
    Solve(root, sum, 0);
    if (sum.find(targetSum) != sum.end())
        return true;
    return false;
}

int main()
{
    // Tree structure: [5,4,8,11,null,13,4,7,2,null,null,null,1]
    // Target sum: 22
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr);
    root->right = new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1)));

    int targetSum = 22; // true
    cout << (hasPathSum(root, targetSum) ? "true" : "false") << endl;
}
