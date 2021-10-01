class Solution {
    
    pair<int, bool> dfs(TreeNode* root){
        if(root == NULL)
            return {0, true};
        
        auto [leftH, leftB] = dfs(root->left);
        auto [rightH, rightB] = dfs(root->right);
        
        if(abs(leftH - rightH) > 1)
            return {1 + max(leftH, rightH), false};
        else
            return {1 + max(leftH, rightH), leftB && rightB};
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
};
