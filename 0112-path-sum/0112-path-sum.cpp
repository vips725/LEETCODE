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
    bool res = false;
    void fun(TreeNode* root,int sum, int targetSum){
        if(root==NULL){
            return ;
        }
        sum +=root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
              res = true;
              return;
            }
        }
        fun(root->left ,sum ,targetSum);
        fun(root->right ,sum ,targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        fun(root  , 0 , targetSum);
        return res;
    }
};