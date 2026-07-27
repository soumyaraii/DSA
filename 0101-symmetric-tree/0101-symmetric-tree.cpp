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
    bool isSymmetric(TreeNode* root) {
        return ismirror(root->left, root->right);
    }
    bool ismirror(TreeNode* n1, TreeNode* n2){
        if(n1==NULL and n2==NULL){
            return true;
        }

        if(n1==NULL or n2==NULL){
            return false;
        }
        return (n1->val==n2->val) and ismirror(n1->left, n2->right) and ismirror(n1->right, n2->left);
    }
};