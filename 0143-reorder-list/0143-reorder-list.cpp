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
 //reverse the second half of the linked list and then it becomes swapping alternates
class Solution {
public:
    ListNode* reverse(ListNode* slow){
        ListNode* prev=NULL;
        ListNode* curr= slow;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast= head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;
    
        ListNode* head2=reverse(second);
        // cout<<head2->val;

        ListNode* head1=head;
        while(head1!=NULL and head2!=NULL){
            ListNode* p=head1->next;
            ListNode* r=head2->next;
            head1->next=head2;
            head2->next=p;
            head1=p;
            head2=r;
        }

        // if(head1!=NULL){
        //     head1->next=head1;
        // }
        // while(head!=NULL){
        //     cout<<head->val<<" ";
        // }
    }
};