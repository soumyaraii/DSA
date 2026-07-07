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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    /*    int n1=0;
        int n2=0;
        ListNode* temp1=l1;
        while(temp1!=NULL){
            n1=n1*10+temp1->val;
            temp1=temp1->next;
        }

        ListNode* temp2=l2;
        while(temp2!=NULL){
            n2=n2*10+temp2->val;
            temp2=temp2->next;
        }

        int n=n1+n2;
        ListNode* dummy= new ListNode(0);
        ListNode* tail=dummy;
        while(tail!=NULL){
            tail->next= new ListNode(n%10);
            n=n/10;
            tail=tail->next;
        }
        return dummy->next;*/
        int carry=0;
        int sum=0;
        int digit=0;
        ListNode* dummy= new ListNode(0);
        ListNode* tail=dummy;
        while(l1!=NULL or l2!=NULL or carry){
            sum=carry;

            if(l1!=NULL){
                sum+=l1->val;
            }

            if(l2!=NULL){
                sum+=l2->val;
            }

            digit=sum%10;
            carry=sum/10;
            tail->next= new ListNode(digit);
            tail=tail->next;


            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }
        return dummy->next;
    }
};