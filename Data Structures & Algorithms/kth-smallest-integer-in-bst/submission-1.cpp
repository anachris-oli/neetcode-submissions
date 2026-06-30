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
        vector<int> result = {root->val};
        if(root->left==nullptr and root->right==nullptr){
            return result;
        }

        vector<int> left_subtree;
        vector<int> right_subtree;

        if(root->left!=nullptr) 
        {
           left_subtree = recursion(root->left);
        }

        if (root->right!=nullptr) 
        {
            right_subtree = recursion(root->right);
        }

        result.insert(result.begin(),left_subtree.begin(),left_subtree.end());
        result.insert(result.end(),right_subtree.begin(),right_subtree.end());
        return result;
    }
};
