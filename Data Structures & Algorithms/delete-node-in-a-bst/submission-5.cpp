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
    vector<TreeNode*> inorder(TreeNode* root,vector<TreeNode*>& node)
    {
        if(root==nullptr)
        {
            return {};
        }
        inorder(root->left,node);
        node.push_back(root);
        inorder(root->right,node);
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
        {
            return nullptr;
        }
        if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }
        if(key>root->val)
        {
            root->right=deleteNode(root->right,key);
        }
        if(root->val==key)
        {
            if(root->left==nullptr and root->right==nullptr)
            {
                return nullptr;
            }
            else if(root->right==nullptr and root->left!=nullptr)
            {
                root=root->left;
                return root;
            }
            else if(root->right!=nullptr and root->left==nullptr)
            {
                root=root->right;
                return root;
            }
            else
            {
                vector<TreeNode*> node;
                vector<TreeNode*> inOrder=inorder(root,node);
                auto it=find(inOrder.begin(),inOrder.end(),root);
                int idx=it-inOrder.begin();
                root->left=deleteNode(root->left,inOrder[idx-1]->val);
                root->val=inOrder[idx-1]->val;
                return root;
            }
        }
        return root;
    }
};