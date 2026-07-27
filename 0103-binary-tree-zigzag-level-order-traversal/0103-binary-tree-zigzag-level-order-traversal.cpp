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
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);


        int level=1;
        while(!q.empty()){
            vector<int> v;
            int n=q.size();     //important otherwise size of queue keeps on changing

            for(int i=0; i<n; i++){
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left!=NULL){
                    q.push(temp->left);
                }

                if(temp->right!=NULL){
                    q.push(temp->right);
                }

                v.push_back(temp->val);

                
                // if(level%2!=0){
                //     if(temp->right!=NULL){
                //         q.push(temp->right);
                //     }
                //     if(temp->left!=NULL){
                //         q.push(temp->left);
                //     }
                // }
                // else{
                //     if(temp->left!=NULL){
                //         q.push(temp->left);
                //     }
                //     if(temp->right!=NULL){
                //         q.push(temp->right);
                //     }
                // }
            }
            if(level % 2 == 0){
                reverse(v.begin(), v.end());
            }
            ans.push_back(v);
            level++;
        }

        return ans;
    }
};