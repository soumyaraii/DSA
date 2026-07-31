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
    // int heightl(TreeNode* node){    //o(h)
    //     int height=0;
    //     while(node){
    //         height++;
    //         node=node->left;
    //     }

    //     return height;
    // }

    // int heightr(TreeNode* node){
    //     int height=0;
    //     while(node){
    //         height++;
    //         node=node->right;
    //     }

    //     return height;
    // }

    // int countNodes(TreeNode* root) {
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int lh=heightl(root);
    //     int rh=heightr(root);
    //     if(lh==rh){
    //         // return 2**(lh)-1;
    //         return (1 << lh) - 1;
    //     }

    //     return 1+countNodes(root->left)+countNodes(root->left);
    // }

    int countNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        if(lh==rh){
            return (1<<lh)+countNodes(root->right);
            //1<<lh==2**h
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
      }
      
      int height(TreeNode* node){
        int h=0;
        while(node){
            h+=1;
            node=node->left;
        }
        return h;
      }
};