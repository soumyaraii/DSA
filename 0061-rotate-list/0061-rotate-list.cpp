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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        if(head==NULL or head->next==NULL or k==0){
            return head;
        }
        int count=1;
        while(temp->next!=NULL){
            count++;
            // prev=temp;
            temp=temp->next;
        }
        temp->next=head;
            // prev->next=NULL;
            // head=temp;
            // k--;
        temp=head;
        k=k%count;
        count = count - k;

        if(count == 0){
            return head;
        }

        while(count > 0){
            prev = temp;
            temp = temp->next;
            count--;
        }

        prev->next = NULL;
        return temp;

    }
};