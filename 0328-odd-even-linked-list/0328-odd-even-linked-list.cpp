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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* oddhead=head;
        ListNode* evenhead=head->next;
        ListNode* newhead=evenhead;
        while(oddhead->next!=NULL and evenhead->next!=NULL){
            oddhead->next=oddhead->next->next;
            evenhead->next=evenhead->next->next;
            if(oddhead->next==NULL){
                break;
            }
            oddhead=oddhead->next;
            if(evenhead->next==NULL){
                break;
            }
            evenhead=evenhead->next;
        }
        evenhead->next=NULL;
        oddhead->next=newhead;
        return head;
    }
};