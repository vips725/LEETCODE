class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = 0;
        if(root == NULL){
            return NULL;
        }
        TreeNode* r1 = lowestCommonAncestor(root->left,p,q);
        TreeNode* r2 = lowestCommonAncestor(root->right,p,q);
        int self = 0;
        if(root==p || root==q){
            self = 1;
        }
        int leftFlag = (r1 != NULL) ? 1 : 0;
        int rightFlag = (r2 != NULL) ? 1 : 0;

        int total = self + leftFlag + rightFlag;
        if(total >= 2){
            ans = root;
            return ans;
        }
        if(self) return root;
        if(r1) return r1;
        if(r2) return r2;

        return ans;
    }
};
