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
//imp trick- of index= 2*i for left and 2*i+1 for right
//width=right-left+1
//use bfs

    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        long long ans=0;
        long long first, last;
        while(!q.empty()){
            int sz=q.size();
            int firstidx=q.front().second;

            for(int k=0; k<sz; k++){
                TreeNode* node=q.front().first;
                long long idx=q.front().second;
            
                q.pop();

                idx=idx-firstidx;

                if(node->left){
                    q.push({node->left, 2*idx});
                }
                if(node->right){
                    q.push({node->right, 2*idx+1});
                }

                if(k==0){
                    first=idx;
                }
                if (k==sz-1){
                    last=idx;
                }
            }
            ans=max(last-first+1, ans);
        }


        return ans;
    }
};