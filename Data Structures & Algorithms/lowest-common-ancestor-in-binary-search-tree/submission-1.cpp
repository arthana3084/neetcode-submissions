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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        if(root==nullptr)
        {
            return nullptr;
        }
        if((p->val>root->val and q->val<root->val) or (p->val<root->val and q->val>root->val))
        {
            return root;
        }
        if(root->val==p->val or root->val==q->val)
        {
            return root;
        }
        if(p->val<root->val and q->val<root->val)
        {
            ans=lowestCommonAncestor(root->left,p,q);
            return ans;
        }
        if(p->val>root->val and q->val>root->val)
        {
            ans=lowestCommonAncestor(root->right,p,q);
            return ans;
        }
        return ans;
    }
};
