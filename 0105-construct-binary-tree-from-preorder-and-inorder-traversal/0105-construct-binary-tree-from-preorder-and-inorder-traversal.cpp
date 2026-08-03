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
int i=0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int s,int e){
        if(s>e){
            return NULL;
        }
        int root=preorder[i];
        TreeNode* rootnode=new TreeNode(root);
        i++;
        int k;
        for(k=s; k<=e; k++){
		    if(inorder[k]==root){
			    break;
		    }
	    }
        rootnode->left=helper(preorder, inorder, s, k-1);
        rootnode->right=helper(preorder, inorder, k+1, e);

        return rootnode;
    }

    // void levelwise(TreeNode* r){
    //     queue<TreeNode*> q;
    //     q.push(r);

    //     while(!q.empty()){
    //         TreeNode* x=q.front();
    //         int s=q.size();
    //         q.pop();
    //         for(int i=0; i<s; i++){
    //             q.push(r->left);
    //             q.push(r->right);
    //         }
    //         cout<<x->val;
    //     }
    // }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        TreeNode* r=helper(preorder, inorder, 0, n-1);
        // levelwise(r);
        return r;
    }
};