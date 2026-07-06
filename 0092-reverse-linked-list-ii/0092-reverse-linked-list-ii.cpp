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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy= new ListNode(0);
        dummy->next=head;

        ListNode* prev = dummy;
        ListNode* leftnode=head;
        int l=left-1;
        while(l--){
            leftnode=leftnode->next;
            prev=prev->next;
        }

        ListNode* beforeleft=prev;
        ListNode* curr=leftnode;
        int n=right-left+1;
        while(n--){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        ListNode* rightnode=prev;
        ListNode* afterright=curr;
        leftnode->next=afterright;
        beforeleft->next=rightnode;

        return dummy->next;
    }
};