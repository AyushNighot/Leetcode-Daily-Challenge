Approach - 2
So, the second approach will be the same as we discuss above using frequency map, which was taking O(n) time complexity, but it's taking O(n) space complexity too!

Let's code this up, you know the tutorial above for this approach!

Here's an explanation of the code:

Frequency Map Construction:

We iterate over the array and build a frequency map (or hash map) where the keys are the numbers from the array and the values are the counts of those numbers.
Finding Unique Numbers:

We then iterate over the entries of the frequency map to find the numbers that appear exactly once and add them to the result array.
Return Result:

The result array, which contains the two numbers that appear only once, is returned.
C++

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        
        // Build the frequency map
        for (int num : nums) {
            frequencyMap[num]++;
        }
        
        // Find the elements that appear only once
        vector<int> result;
        for (const auto& entry : frequencyMap) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};
