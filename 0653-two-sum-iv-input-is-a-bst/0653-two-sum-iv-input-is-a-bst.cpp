/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;

    TreeNode* getSmall() {
        if (asc.empty())
            return NULL;

        TreeNode* small = asc.top();
        asc.pop();

        TreeNode* rightChild = small->right;
        while (rightChild) {
            asc.push(rightChild);
            rightChild = rightChild->left;
        }

        return small;
    }

    TreeNode* getBig() {
        if (desc.empty())
            return NULL;

        TreeNode* big = desc.top();
        desc.pop();

        TreeNode* leftChild = big->left;
        while (leftChild) {
            desc.push(leftChild);
            leftChild = leftChild->right;
        }

        return big;
    }

    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;

        TreeNode* t = root;

        while (t) {
            asc.push(t);
            t = t->left;
        }

        t = root;

        while (t) {
            desc.push(t);
            t = t->right;
        }

        TreeNode* left = getSmall();
        TreeNode* right = getBig();

        while (left != right) {
            int sum = left->val + right->val;

            if (sum == k)
                return true;
            else if (sum < k)
                left = getSmall();
            else
                right = getBig();
        }

        return false;
    }
};