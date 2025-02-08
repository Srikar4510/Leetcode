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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        //node,vertical line;
        queue<pair<TreeNode*,int>> q;
        //vertical line,{horizontal line,values of node at that horizontal levels};
        map<int,vector<pair<int,int>>> mp;  
        q.push({root,0});
        int horLine=0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int verLine = it.second;
            mp[verLine].push_back({horLine,node->val});
            
            if(node->left){
                q.push({node->left,verLine-1});
            } 
            if(node->right){
                q.push({node->right,verLine+1});
            }
           
            }
             horLine++;
        }
        //TC - O(n*logn *nlogn) -> O(n^2*(logn)^2)
        for(auto x:mp){
            vector<int> tmp;
            sort(x.second.begin(),x.second.end());
            for(auto y:x.second){
                tmp.push_back(y.second);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};