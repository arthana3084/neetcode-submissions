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
    void levelorder(TreeNode* root,vector<vector<int>>& ans)
    {
        if(root==nullptr)
        {
            return;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> level;
            int levelSize = que.size();
            for(int i=0;i<levelSize;i++)
            {
                TreeNode* root=que.front();
                level.push_back(root->val);
                que.pop();
                if(root->left)
                {
                    que.push(root->left);
                }
                if(root->right)
                {
                    que.push(root->right);
                }
            }
            ans.push_back(level);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(root,ans);
        return ans;
    }
};
