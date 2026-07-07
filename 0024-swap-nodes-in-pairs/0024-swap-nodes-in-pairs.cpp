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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* left=head;
        ListNode* right=head->next;
        ListNode* prev=dummy;
        prev->next=head;

        while(left!=NULL and left->next!=NULL){
            ListNode* temp=right->next;
            right->next=left;
            left->next=temp;
            prev->next=right;
            prev=left;
            left=temp;
            if(left!=NULL){
                right=left->next;
            }
        }

        return dummy->next;
    }
};