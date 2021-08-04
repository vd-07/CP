/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    int ans;
public:
    Solution() {
        ans = 0;
    }
    int calc(TreeNode* node) {
        if(node->left == NULL && node->right == NULL)
            return 1;
        int v1 = 0, v2 = 0;
        if(node->left != NULL)
            v1 = calc(node->left);
        if(node->right != NULL)
            v2 = calc(node->right);
        ans = max(ans, v1 + v2);
        // cout << (node->val) << " " << v1 << " " << v2 << endl;
        return max(v1, v2) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        calc(root);
        return ans;
    }
};
