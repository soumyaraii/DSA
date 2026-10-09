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
ListNode* newhead=new ListNode(0);
    ListNode* rec(ListNode* list1, ListNode* list2){
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }

        if(list1->val<=list2->val){
            list1->next=rec(list1->next, list2);
            return list1;
        }
        else{
            list2->next=rec(list1, list2->next);
            return list2;
        }
        // return newhead;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode* dummy= new ListNode(0);
        // ListNode* tail=dummy;
        // while(list1!=NULL and list2!=NULL){
        //     if(list1->val<list2->val){
        //         tail->next=list1;
        //         list1=list1->next;
        //     }
        //     else{
        //         tail->next=list2;
        //         list2=list2->next;
        //     }
        //     tail=tail->next;

        // }

        // //IMP
        // if(list1){
        //     tail->next=list1;
        // }
        // if(list2){
        //     tail->next=list2;
        // }

        // return dummy->next;
        return rec(list1, list2);
    }
};