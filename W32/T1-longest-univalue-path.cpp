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
    int ans = 0;
    int dfs(TreeNode* root){
        int l = 0, r = 0;
        if(root -> left != NULL){
            if(root -> left -> val == root -> val)l = dfs(root -> left);
            else dfs(root -> left);
        }
        if(root -> right != NULL){
            if(root -> right -> val == root -> val)r = dfs(root -> right);
            else dfs(root -> right);
        }
        ans = max(ans, 1 + l + r);
        return 1 + max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)return 0;
        dfs(root);
        return ans-1;
    }
};
