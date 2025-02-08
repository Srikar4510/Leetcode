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
    void findSum(TreeNode* node,int currSum,int &totalSum){
        if(!node) return;

        currSum = 10*currSum+node->val;
        if(!node->left && !node->right){
            totalSum += currSum;
            return;
        }
       findSum(node->left,currSum,totalSum);
       findSum(node->right,currSum,totalSum);

    }
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        findSum(root,0,totalSum);
        return totalSum;
    }
};