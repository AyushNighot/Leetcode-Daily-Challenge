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
    int rec(ListNode* head)
    {
        //base case 
        if(head ==  NULL) return 0;
        head -> val = head -> val * 2 + rec(head -> next);

        if( head -> val > 9)
        {
            int a = head -> val % 10 ;
            int b = head -> val / 10;

            head -> val = a;
            return b; 
        }

        return 0;
    }
    ListNode* doubleIt(ListNode* head) {
        int c = rec(head);

        if(c)
        {
            ListNode* newHead = new ListNode(c,head);
            return newHead;
        }

        return head;
    }
};
