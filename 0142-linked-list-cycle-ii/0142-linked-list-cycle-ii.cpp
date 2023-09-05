/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* pos = nullptr;
        if(!head || !head->next) {
            return pos;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            fast = fast->next;
            if(fast->next!=NULL) {
                slow = slow->next;
                fast = fast->next;
            }

            if(slow==fast) {
                break;
            }
        }
        if(slow!=fast) {
            return pos;
        }
        slow = head;
        while(slow!=fast) {
            slow = slow->next;
            fast = fast->next;
        }
        pos = fast;
        return pos;
    }
};