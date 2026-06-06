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
    bool isbst(TreeNode* root,int maxi,int mini)
    {
        if(root==nullptr)
        {
            return true;
        }
        if(root->val>=maxi or root->val<=mini)
        {
            return false;
        }
        bool leftans=isbst(root->left,root->val,mini);
        bool rightans=isbst(root->right,maxi,root->val);
        return leftans and rightans;
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
        return isbst(root,INT_MAX,INT_MIN);
    }
};
