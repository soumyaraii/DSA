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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        if(head->next==NULL and n==1){
            return NULL;
        }

        ListNode* left=head;
        ListNode* right=head;
        while(n--){
           right=right->next;
        }

        if(right==NULL){
            head=left->next;
            return head;
        }

        while(right!=NULL){
            right=right->next;
            left=left->next;
            dummy=dummy->next;
        }

        dummy->next=left->next;
        return head;
    }
};