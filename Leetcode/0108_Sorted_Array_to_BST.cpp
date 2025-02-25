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

TreeNode *Solve(vector<int> &nums, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = Solve(nums, start, mid - 1);
    root->right = Solve(nums, mid + 1, end);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    return Solve(nums, 0, n - 1);
}

int main()
{
    // 0 -3 -10 5 9
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = sortedArrayToBST(nums);

    // Preorder traversal to display the BST
    function<void(TreeNode *)> preorder = [&](TreeNode *node)
    {
        if (node == nullptr)
            return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    };

    preorder(root);
    cout << endl;
}
