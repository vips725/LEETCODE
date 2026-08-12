class Solution {
public:
    int idx = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int l, int r) {
        if (idx >= preorder.size() || l > r) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);
        if (l == r) return root; // leaf node

        // Next preorder element is left child
        int leftVal = preorder[idx];
        int pos = -1;
        for (int i = l; i <= r; i++) {
            if (postorder[i] == leftVal) {
                pos = i;
                break;
            }
        }

        if (pos != -1) {
            root->left = build(preorder, postorder, l, pos);
            root->right = build(preorder, postorder, pos + 1, r - 1);
        }

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        idx = 0;
        return build(preorder, postorder, 0, postorder.size() - 1);
    }
};
