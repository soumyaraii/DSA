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
    ListNode* middleNode(ListNode* head) {
        int length=0;
        ListNode* h=head;
        while(h!=NULL){
            length++;
            h=h->next;
        }

        int middle=0;
        if(length%2==0){
            middle=length/2;
        }
        else{
            middle=(length-1)/2;
        }

        ListNode* curr=head;
        while(middle--){
            curr=curr->next;
        }
        return curr;
    }
};