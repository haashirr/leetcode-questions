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
        if(!head || k<=1) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = head;
        ListNode* prevGroupEnd = dummy;
        int length=0;
        while(current) {
            length++;
            current = current->next;
        }
        while(length>=k) {
             ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = groupStart;
            ListNode* nextGroupStart = nullptr;
            for(int i=1;i<k;i++) {
                groupEnd = groupEnd->next;
            }
            if(groupEnd->next) {
                nextGroupStart = groupEnd->next;
            }
            ListNode* prev = nextGroupStart;
            current = groupStart;
            while(current!=nextGroupStart) {
                ListNode* nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }
            prevGroupEnd->next = groupEnd;
            groupStart->next = nextGroupStart;
            prevGroupEnd = groupStart;
            length-=k;
        } 
       
        return dummy->next;

    }
};