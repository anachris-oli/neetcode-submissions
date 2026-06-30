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
    int kthSmallest(TreeNode* root, int k) {
        auto sorted_values = recursion(root);
        return sorted_values[k-1];

    }

    vector<int> recursion(TreeNode* root)
    {
        if(root->left==nullptr and root->right==nullptr){
            return {root->val};
        }

        vector<int> result;
        if(root->left!=nullptr) 
        {
           auto left_subtree = recursion(root->left);
           result.insert(result.begin(),left_subtree.begin(),left_subtree.end());
        }

        result.push_back(root->val);
        if (root->right!=nullptr) 
        {
            
            auto right_subtree = recursion(root->right);
            result.insert(result.end(),right_subtree.begin(),right_subtree.end());
        }
        return result;
    }
};
