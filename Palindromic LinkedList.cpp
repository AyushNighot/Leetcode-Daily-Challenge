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
    private:
    bool checkPalindrome(vector<int>ans)
{

    int size = ans.size();
    int s = 0;
    int e = size-1;
    while (s<=e)
    {
        if(ans[s] != ans[e]) return 0; 
        s++;
        e--;
    }
     return 1;
}

public:
    
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
         while (temp != NULL)
         {
             ans.push_back(temp -> val);
             temp = temp -> next;
         }
        
         return checkPalindrome(ans);
    }
};
