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
// struct compare {
//     bool operator()(ListNode* a, ListNode* b) {
//         return a->val > b->val; // min-heap: smallest val has highest priority
//     }
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // priority_queue<ListNode*, vector<ListNode*>, compare> h;

        // // Put first node of every list into heap
        // for(int i = 0; i < lists.size(); i++) {
        //     if(lists[i] != NULL) {
        //         h.push(lists[i]);
        //     }
        // }

        // ListNode* dummy = new ListNode(0);
        // ListNode* tail = dummy;

        // while(!h.empty()) {

        //     // Smallest node
        //     ListNode* temp = h.top();
        //     h.pop();

        //     // Add it to result
        //     tail->next = temp;
        //     tail = temp;

        //     // Add next node of that list
        //     if(temp->next != NULL) {
        //         h.push(temp->next);
        //     }
        // }

        // return dummy->next;
        if (lists.empty()){
            return NULL;
        }

        int interval = 1;
        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

};