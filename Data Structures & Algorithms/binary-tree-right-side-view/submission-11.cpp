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
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        vector<int>ans;
        if(root==NULL)return ans;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node1=it.first;
            int level=it.second;
            if(mp[level]==NULL)mp[level]=node1->val;
            if(node1->right)q.push({node1->right,level+1});
            if(node1->left)q.push({node1->left,level+1});
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }return ans;

    }
};
