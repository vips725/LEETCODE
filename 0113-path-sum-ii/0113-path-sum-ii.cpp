class Solution {
public:
    vector<vector<int>> res;

    void fun(TreeNode* root, int targetSum, vector<int>& diary, int sum) {
        if (root == NULL) return;

        diary.push_back(root->val);
        sum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                res.push_back(diary);
            }
        } else {
            fun(root->left, targetSum, diary, sum);
            fun(root->right, targetSum, diary, sum);
        }

        diary.pop_back(); 
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> diary;
        fun(root, targetSum, diary, 0);
        return res;
    }
};
