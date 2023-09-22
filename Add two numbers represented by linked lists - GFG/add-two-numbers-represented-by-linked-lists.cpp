//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    // Function to reverse a linked list.
    struct Node* reverseLinkedList(struct Node* head) {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    // Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // Reverse the input linked lists to add them from right to left.
        first = reverseLinkedList(first);
        second = reverseLinkedList(second);

        // Initialize variables
        Node* res = NULL;
        Node* temp = NULL;
        Node* prev = NULL;
        int carry = 0;
        int sum;

        // Traverse both reversed linked lists
        while (first || second) {
            int x = (first) ? first->data : 0;
            int y = (second) ? second->data : 0;

            // Calculate the sum of current digits and carry
            sum = carry + x + y;
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;

            // Create a new node for the sum digit
            temp = new Node(sum);

            // If this is the first node, set it as the result
            if (res == NULL) {
                res = temp;
            }
            else {
                prev->next = temp;
            }

            prev = temp;  // Update prev to the current node

            // Move to the next nodes, if available
            if (first) {
                first = first->next;
            }
            if (second) {
                second = second->next;
            }
        }

        // If there is a carry left, create a new node for it
        if (carry > 0) {
            temp->next = new Node(carry);
        }

        // Reverse the result linked list to get the correct order.
        res = reverseLinkedList(res);

        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends