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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        while(head!=NULL){
            if(head->val==val and head->next!=NULL){
                head=head->next;
            }
            else if(head->val==val and head->next==NULL){
                return NULL;
            }
            else{
                break;
            }
        }
        
        ListNode* curr=head;
        while(curr!=NULL and curr->next!=NULL){
            if(curr->next->val==val and curr->next->next!=NULL){
                curr->next=curr->next->next;
            }
            else if(curr->next->val==val){
                curr->next=NULL;
            }
            else{
                curr=curr->next;
            }
        }
        if(curr->val==val){

        }
        return head;
    }
};