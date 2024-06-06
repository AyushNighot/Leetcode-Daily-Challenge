Intuition
When first approaching this problem, the idea is to check if we can rearrange the cards in such a way that we form groups of consecutive cards of a specific size.
We need to ensure that every card can be part of a group of the specified size and that no cards are left ungrouped.
==========================================================================================================================================
Approach
Check for Valid Group Size: The total number of cards must be divisible by the group size to possibly form the required groups. If not, return False.
Count Card Frequencies: Use a dictionary or Counter from the collections module to count how many times each card appears.
Sort the Card Values: Sort the unique card values. This helps in sequentially forming groups starting from the smallest card value.
Form Groups: Iterate through the sorted card values and try to form groups starting from each card:
For each card value, if it has not been fully used in previous groups, attempt to form a group of consecutive cards starting from that value.
For each card in the required group, check if there are enough cards to form the group. If not, return False.
Decrement the count of each card in the group as they are used.
Return Result: If all groups can be successfully formed, return True.

==========================================================================================================================
Code
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if (hand.size() % groupSize != 0) {
        return false;
    }

    map<int, int> cardCount;
    for (int card : hand) {
        cardCount[card]++;
    }

    for (auto it = cardCount.begin(); it != cardCount.end(); ++it) {
        if (it->second > 0) {
            int count = it->second;
            for (int i = 0; i < groupSize; ++i) {
                if (cardCount[it->first + i] < count) {
                    return false;
                }
                cardCount[it->first + i] -= count;
            }
        }
    }

    return true;
    }
};
Complexity
Time complexity:O(n)
Space complexity:O(k)
