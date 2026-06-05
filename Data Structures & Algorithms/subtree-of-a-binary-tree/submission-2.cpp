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
    bool sametree(TreeNode* root1,TreeNode* root2)
    {
        bool left;
        bool right;
        if(root1==nullptr and root2==nullptr)
        {
            return true;
        }
        else if(root1==nullptr)
        {
            return false;
        }
        else if(root2==nullptr)
        {
            return false;
        }
        else
        {
            if(root1->val!=root2->val)
            {
                return false;
            }
            else
            {
                bool left=sametree(root1->left,root2->left);
                bool right=sametree(root1->right,root2->right);
                return left and right;
            }
        }
        return (left and right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)
        {
            return false;
        }
        bool ans=sametree(root,subRoot);
        bool leftans=isSubtree(root->left,subRoot);
        bool rightans=isSubtree(root->right,subRoot);
        return (ans or leftans or rightans);
    }
};
