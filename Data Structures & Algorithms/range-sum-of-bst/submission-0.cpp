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
    void rangebst(TreeNode* root,vector<int>& ans,int low,int high)
    {
        if(root==nullptr)
        {
            return;
        }
        if(root->val<=high and root->val>=low)
        {
            ans.push_back(root->val);
        }
        rangebst(root->left,ans,low,high);
        rangebst(root->right,ans,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr)
        {
            return 0;
        }
        vector<int> ans;
        rangebst(root,ans,low,high);
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            sum+=ans[i];
        }
        return sum;
    }
};