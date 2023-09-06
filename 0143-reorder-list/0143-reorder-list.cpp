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
    void reorderList(ListNode* head) {
        if(!head || !head->next) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            fast = fast->next;
            if(fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* current = secondHalf;
        while(current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        secondHalf = prev;
        ListNode* firstHalf = head;
        while(firstHalf && secondHalf) {
            ListNode* firstNext = firstHalf->next;
            ListNode* secondNext = secondHalf->next;
            firstHalf->next = secondHalf;
            secondHalf->next = firstNext;
            firstHalf = firstNext;
            secondHalf = secondNext;
        }

    }
};