Method 1: Monotonic Stack Approach
🤔 Intuition:
One approach is to traverse the linked list and maintain a stack to store nodes in non-decreasing order of their values. While traversing, if we encounter a node with a value greater than the top element of the stack, we pop elements from the stack until the condition is met. This ensures that the stack contains only nodes with the highest values seen so far. Finally, we reverse the stack to get the modified linked list.

🧠 Approach:
Initialize a stack to store nodes in non-decreasing order of their values.
Traverse the linked list:
If the current node's value is greater than the top element of the stack, pop elements from the stack until the condition is met.
Push the current node onto the stack.
Reverse the stack to obtain the modified linked list.
Return the head of the modified linked list.
⚙️ Dry Run:
Given Linked List: 5 -> 2 -> 13 -> 3 -> 8
Iteration	Node	Stack
Step 1	5	5
Step 2	2	5, 2
Step 3	13	5, 2, 13
Step 4	3	13, 3
Step 5	8	13, 3, 8
Stack: [13, 8]
Now Creating Linked List using stack from top - bottom.

Result: 13 -> 8
📒 Complexity:
⏰ Time complexity: O(n)O(n)O(n), where n is the number of nodes in the linked list and we iterate through linked list.
🧺 Space complexity: O(n)O(n)O(n), to store nodes in the stack.

🧑‍💻 Code
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        
        while (cur != nullptr) {
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        
        return cur;
    }
};
