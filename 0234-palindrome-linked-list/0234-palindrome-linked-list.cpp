/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // bool rec(ListNode* head){
    //     //base case
    //     if(head==NULL or head->next==NULL){
    //         return true;
    //     }

    //     //rec case
    //     ListNode* temp=head;
    //     ListNode* prev=new ListNode(0);
    //     prev->next=temp;
    //     while(temp->next!=NULL){
    //         temp=temp->next;
    //         prev=prev->next;
    //     }
    //     if(temp->val!=head->val){
    //         return false;
    //     }
    //     else{
    //         prev->next=NULL;
    //         return rec(head->next);
    //     }
    //     return true;
    // }
    
    ListNode* left;

    bool rec(ListNode* right) {
        // Base case
        if (right == NULL) {
            return true;
        }

        // Recursive call
        bool ans = rec(right->next);

        if (ans == false) {
            return false;
        }

        // Compare nodes
        if (left->val != right->val) {
            return false;
        }

        // Move left forward
        left = left->next;

        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        /*ListNode* prev=new ListNode(0);
        prev->next=head;*/
        // ListNode* fast=head;
        // ListNode* slow=head;
         
        // while(fast->next!=NULL and fast->next->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     //prev=prev->next;
        // }

        // //if(fast!=slow){
        //     ListNode* curr= slow->next;
        //     slow->next=NULL;
            
        //     ListNode* pr=NULL;

        //     while(curr!=NULL){
        //         ListNode* temp=curr->next;
        //         curr->next=pr;
        //         pr=curr;
        //         curr=temp;
        //     }

        //     ListNode* head2=pr;


        //     while(head2 != NULL){
        //         if(head->val != head2->val)
        //             return false;

        //         head = head->next;
        //         head2 = head2->next;
        //     }
        //     /*while(head!=NULL and head2!=NULL){
        //         if(head->val!=head2->val){
        //             return false;
        //         }
        //     }*/

        //     return true;
        /*} 
        else{
            if (fast->val==slow->val){
                return true;
            }
            return false;
        }*/
        left = head;
        return rec(head);

    }
};