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
    int res = 0;
    void fun(TreeNode* root , int sum){
        if(root == NULL){
            return;
        }
        sum = sum*10+root->val;
        if(root->left==NULL && root->right==NULL){
            res+=sum;
            return;
        }
        fun(root->left ,sum);
        fun(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
     fun(root , 0);
     return res;

    }
};