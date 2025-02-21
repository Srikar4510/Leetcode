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
 /**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
class FindElements {
    unordered_set<int> seen;
public:
    FindElements(TreeNode* root) {
        bfs(root);
    }
    
    bool find(int target) {
        return seen.find(target)!=seen.end();
    }
private:
  void bfs(TreeNode* root){
      queue<TreeNode*> q;
      root->val=0;
      q.push(root);
      while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto curr = q.front();
            q.pop();
            int x = curr->val;
            seen.insert(x);
            if(curr->left){
                curr->left->val = 2*x+1;
                q.push(curr->left);
            }
            if(curr->right){
                curr->right->val=2*x+2;
                q.push(curr->right);
            }
        }
      }
  }
};


