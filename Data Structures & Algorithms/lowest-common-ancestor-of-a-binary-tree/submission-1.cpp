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
public:
    bool search(TreeNode* root,TreeNode* p)
    {
        if(root==nullptr)
        {
            return false;
        }
        if(root->val==p->val)
        {
            return true;
        }
        bool left=search(root->left,p);
        bool right=search(root->right,p);
        return left or right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        if(root==nullptr)
        {
            return nullptr;
        }
        bool leftp=search(root->left,p);
        bool rightp=search(root->right,p);
        bool leftq=search(root->left,q);
        bool rightq=search(root->right,q);
        if((leftp and rightq) or (leftq and rightp))
        {
            return root;
        }
        if(leftp and leftq)
        {
            ans=lowestCommonAncestor(root->left,p,q);
        }
        if(rightp and rightq)
        {
            ans=lowestCommonAncestor(root->right,p,q);
        }
        return ans;
    }
};