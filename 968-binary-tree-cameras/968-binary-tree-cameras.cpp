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
    map<TreeNode*, map<int, int>>mp;
    void makeDP(TreeNode *node){
        if(node == nullptr)return;
        mp[node][0] = -1;
        mp[node][1] = -1;
        mp[node][2] = -1;
        makeDP(node->left);
        makeDP(node->right);
    }
        
    int solve(TreeNode* node, int done){
        if(node == nullptr) return 0;
        int &ret = mp[node][done];
        if(~ret)return ret;
        int path1 = INT_MAX , path2 = INT_MAX , path3 = INT_MAX , path4 = INT_MAX , path5 = INT_MAX , path6 = INT_MAX;
        if(done == 0){
            path1 = solve(node->left , 2) + 1 + solve(node->right , 1);
            path2 = solve(node->left , 1) + 1 + solve(node->right , 2);
            path3 = solve(node->left , 1) + 1 + solve(node->right , 1);
            path4 = solve(node->left , 2) + 1 + solve(node->right , 2);
        }else if(done == 1){
            path1 = solve(node->left , 2) + solve(node->right , 2);
        }else if(done == 2){
            if(node->left == nullptr and node->right == nullptr) return 1;
            path1 = solve(node->left , 2) + 1 + solve(node->right , 1);
            path2 = solve(node->left , 1) + 1 + solve(node->right , 2);
            path3 = solve(node->left , 1) + 1 + solve(node->right , 1);
            path4 = solve(node->left , 2) + 1 + solve(node->right , 2);
            if(node->left != nullptr)
                path5 = solve(node->left , 0) + solve(node->right , 2);
            if(node->right != nullptr)
                path6 = solve(node->left , 2) + solve(node->right , 0);
        }
        return ret = min({path1 , path2, path3, path4, path5, path6});
    }
    
    
    int minCameraCover(TreeNode* root) {
        makeDP(root);
        if(root->left == nullptr and root->right == nullptr)return 1;
        int path1 = solve(root, 2);
        return path1;
    }
    
};