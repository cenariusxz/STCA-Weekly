/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL)return 0;
        int tmp = 0;
        if(root -> val >= L && root -> val <= R){
            tmp += root -> val;
            if(root -> left != NULL)tmp += rangeSumBST(root -> left, L, R);
            if(root -> right != NULL)tmp += rangeSumBST(root -> right, L, R);
        }
        if(root -> val < L){
            if(root -> right != NULL)tmp += rangeSumBST(root -> right, L, R);
        }
        if(root -> val > R){
            if(root -> left != NULL)tmp += rangeSumBST(root -> left, L, R);
        }
        return tmp;
    }
};
