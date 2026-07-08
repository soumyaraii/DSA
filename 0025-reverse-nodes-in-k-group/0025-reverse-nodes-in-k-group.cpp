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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* groupprev=dummy;
        while (true) {
            // Find the kth node
            ListNode* kth=groupprev;
            for (int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            // Less than k nodes left
            if (kth==NULL)
                break;
            
            ListNode* groupNext=kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupprev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Reconnect
            ListNode* temp = groupprev->next;   // old head (becomes tail)
            groupprev->next = kth;             // new head
            groupprev = temp;                  // move to next group
        }

        return dummy->next;   
    }
};