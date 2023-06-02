
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
    
   void Helper(TreeNode* root, int row, int col, map<int, vector<pair<int, int>>>& mpp){
       if(root == NULL) return;
       mpp[col].push_back({row, root->val}); 
       Helper(root->left, row+1, col-1, mpp);
       Helper(root->right, row+1, col+1, mpp); 
   }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> preorder;
        map<int, vector<pair<int, int>>> mpp;
        Helper(root, 0, 0, mpp);
        
        vector<int> helper;
        for(pair<int, vector<pair<int, int>>> p : mpp){
            sort(p.second.begin(), p.second.end()); 
            for(pair<int, int> p1 : p.second) helper.push_back(p1.second); 
            preorder.push_back(helper); 
            helper.clear(); 
        }
        return preorder;
         
    }
};