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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==nullptr)
        {
            return nullptr;
        }
        removeLeafNodes(root->left,target);
        removeLeafNodes(root->right,target);
        if(root->left!=nullptr and root->left->val==target)
        {
            if(root->left->left==nullptr and root->left->right==nullptr)
            {
                root->left=nullptr;
            }
        }
        if(root->right!=nullptr and root->right->val==target)
        {
            if(root->right->left==nullptr and root->right->right==nullptr)
            {
                root->right=nullptr;
            }
        }
        if(root->left==nullptr and root->right==nullptr and root->val==target)
        {
            return nullptr;
        }
        return root;
    }
};