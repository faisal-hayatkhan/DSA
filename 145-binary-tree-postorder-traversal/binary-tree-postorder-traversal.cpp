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
    private:
    vector<int> ans;
    void traver(TreeNode *element)
    {
        if(element==NULL) // if the root or the value is NULL
        return;

        traver(element->left);
        traver(element->right);
        ans.push_back(element->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        ans.clear();
        traver(root); 
        return ans;
        
    }
};