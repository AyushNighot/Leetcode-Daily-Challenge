Approach
1. Initialize a HashMap:

Use a HashMap<Integer, Integer> to store the remainder of the cumulative sum when divided by k and its corresponding index.
Start with an entry (0, -1) to handle subarrays starting from index 0.
2. Iterate through the Array:

Maintain a cumulative sum as you iterate through the array.
3. Calculate Remainder:

For each element, update the cumulative sum and calculate remainder = sum % k.
If the remainder is negative, adjust it by adding k to ensure it's positive.
4. Check for Subarray:

If the remainder exists in the HashMap:
Check if the distance between the current index and the stored index for this remainder is greater than 1.
If yes, return true (indicating a valid subarray is found).
If the remainder is not in the HashMap, store it with the current index.
5. Return Result:

If no valid subarray is found after iterating through the array, return false.
Complexity

Time complexity: O(n).
Space complexity: O(n).



Code 🧑🏻‍💻
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = -1; // To handle the case where the sub-array starts from index 0
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if (map.find(rem) != map.end()) {
                if (i - map[rem] > 1) {
                    return true;
                }
            } else {
                map[rem] = i;
            }
        }

        return false;
    }
};
