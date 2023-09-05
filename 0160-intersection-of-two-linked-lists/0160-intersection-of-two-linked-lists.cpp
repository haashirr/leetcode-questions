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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //calculate the length of the lists
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        int len1=0;
        int len2=0;
        while(curr1->next!=NULL) {
            len1++;
            curr1 = curr1->next;
        }
        while(curr2->next!=NULL) {
            len2++;
            curr2 = curr2->next;
        }
        //move the pointer of the longer linked list by the difference
        curr1 = headA;
        curr2 = headB;
        if(len1>len2) {
            for(int i=0;i<len1-len2;i++) {
                curr1 = curr1->next;
            }
        }
        else {
            for(int i=0;i<len2-len1;i++) {
                curr2 = curr2->next;
            }
        }
        //traverse the linked lists and find the intersecting node
        while(curr1!=curr2) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return curr1;
    }
};