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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
        {
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[0]);
        auto it=find(inorder.begin(),inorder.end(),preorder[0]);
        int idx=it-inorder.begin();
        vector<int> leftinorder(inorder.begin(),inorder.begin()+idx);
        vector<int> rightinorder(inorder.begin()+idx+1,inorder.end()); 
        vector<int> leftpreorder(preorder.begin()+1, preorder.begin()+1+leftinorder.size());
        vector<int> rightpreorder(preorder.begin()+1+leftinorder.size(), preorder.end());
        root->left=buildTree(leftpreorder,leftinorder);
        root->right=buildTree(rightpreorder,rightinorder);
        return root;
    }
};
