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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root!=NULL && root->val!=val) {

        // If the current node's value is greater than the target value,
        // move to the left subtree to continue the search.
            if (root->val>val)
                root = root->left;

            // If the current node's value is lesser than the target value,
            // move to the right subtree to continue the search.
            else
                root = root->right;
        }

    // Return the current node (which contains the target value) if found,
    // or NULL if the target value is not present in the BST.
    return root;        
    }
};