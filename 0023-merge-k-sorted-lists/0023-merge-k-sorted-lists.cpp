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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap: smallest val has highest priority
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> h;

        // Put first node of every list into heap
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                h.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!h.empty()) {

            // Smallest node
            ListNode* temp = h.top();
            h.pop();

            // Add it to result
            tail->next = temp;
            tail = temp;

            // Add next node of that list
            if(temp->next != NULL) {
                h.push(temp->next);
            }
        }

        return dummy->next;
    }
};