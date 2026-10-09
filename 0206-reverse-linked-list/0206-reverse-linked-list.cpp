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
    ListNode* rec(ListNode* head){
        //base case
        if(head==NULL or head->next==NULL){
            return head;
        }
        //rec case
        // ListNode* currtail=head->next;
        // ListNode* prev=head;
        // while(currtail->next!=NULL){
        //     prev=prev->next;
        //     currtail=currtail->next;
        // }
        // prev->next=NULL;
        // currtail->next=rec(head);
        ListNode* newhead=rec(head->next);
        head->next->next=head;
        head->next=NULL;

        return newhead;
    }
    ListNode* reverseList(ListNode* head) {
        //if(head==NULL){
        //    return head;
        //}
        // ListNode* prev=NULL;
        // ListNode* curr= head;
        // while(curr!=NULL){
        //     ListNode* temp=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=temp;
        // }
        // return prev;
        return rec(head);
    }
};