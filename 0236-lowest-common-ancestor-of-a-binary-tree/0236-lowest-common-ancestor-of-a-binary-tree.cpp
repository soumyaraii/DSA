/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//this doesnt work since the vector is passed by value and memory limit exceeds
    // vector<TreeNode*> findval(TreeNode* node, TreeNode* target, vector<TreeNode*> ancestors){
    //     if(node==NULL){
    //         return {};
    //     }
        
    //     ancestors.push_back(node);
    //     if(node==target){
    //         return ancestors;
    //     }

    //     vector<TreeNode*> left=findval(node->left, target, ancestors);
    //     if(!left.empty()){
    //         return left;
    //     }
    //     vector<TreeNode*> right=findval(node->right, target, ancestors);
    //     if(!right.empty()){
    //         return right;
    //     }

    //     return {};
    // }
    bool findval(TreeNode* node, TreeNode* target, vector<TreeNode*>& ancestors) {
        if (node == NULL){
            return false;
        }
        ancestors.push_back(node);

        if (node == target){
            return true;
        }

        if (findval(node->left, target, ancestors)){
            return true;
        }
        if (findval(node->right, target, ancestors)){
            return true;
        }
        ancestors.pop_back();   // backtrack
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> first, second;
        findval(root, p, first);
        findval(root, q, second);
        
        TreeNode* ans=NULL;
        
        int i=0;
        while(i<first.size() and i<second.size()){
            if(first[i]==second[i]){
                ans=first[i];
            }
            else{
                break;
            }
            i++;
        }

        return ans;
    }
};