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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> level;
            int levelSize = que.size();
            for(int i=0;i<levelSize;i++)
            {
                TreeNode* root=que.front();
                que.pop();
                if(root->left)
                {
                    que.push(root->left);
                }
                if(root->right)
                {
                    que.push(root->right);
                }
                if(i==levelSize-1)
                {
                    ans.push_back(root->val);
                }
            }
        }
        return ans;
    }
};
