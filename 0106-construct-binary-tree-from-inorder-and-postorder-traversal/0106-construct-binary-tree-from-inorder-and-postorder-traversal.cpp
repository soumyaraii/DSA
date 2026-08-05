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
int postidx;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int s, int e){
        if(s>e){
            return NULL;
        }
        TreeNode* root= new TreeNode(postorder[postidx]);
        postidx--;
        int k;
        for(k=0; k<=e; k++){
            if(inorder[k]==root->val){
                break;
            }
        }
        root->right=helper(inorder, postorder, k+1, e);
        root->left=helper(inorder, postorder, s, k-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postidx = postorder.size()-1;
        int si=postorder.size();    //postorder not inorder
        TreeNode* r=helper(inorder, postorder, 0, si-1);
        return r;
    }
};