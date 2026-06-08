/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root,int number)
    {
        if(root==nullptr)
        {
            return 0;
        }
        if(root->left==nullptr and root->right==nullptr)
        {
            number=number*10+root->val;
            return number;
        }
        number=number*10+root->val;
        int left=sumNumbers(root->left,number);
        int right=sumNumbers(root->right,number);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        int number=0;
        int ans=sumNumbers(root,number);
        return ans;
    }
};