Intuition:
To solve this problem, we need to find the minimum number of intervals required to complete all tasks while following the cooling time constraint. One way to approach this is to first count the frequency of each task. Then, we can sort the frequencies in descending order to prioritize tasks with higher frequency. After sorting, we can calculate the number of intervals needed by considering the task with the maximum frequency.

Approach:

Count the frequency of each task using an array freq.
Sort the freq array in descending order.
Calculate the number of intervals needed based on the task with the maximum frequency.
Return the total number of intervals required.
Complexity:

Time complexity: Sorting the freq array takes O(26 log 26), which simplifies to O(1) as it's a constant time operation. The loop to calculate intervals takes O(26), which is again a constant. So overall, the time complexity is O(1).
Space complexity: We use an array of size 26 for frequency, so the space complexity is O(1).
Code :
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(char task : tasks){
            freq[task - 'A']++;
        }
        sort(begin(freq) , end(freq));
        int chunk = freq[25] - 1;
        int idel = chunk * n;

        for(int i=24; i>=0; i--){
            idel -= min(chunk,freq[i]);
        }

        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};
Key Points:

The min(chunk, freq[i]) calculation effectively adapts the initial idel estimate based on less frequent tasks.
The final check for negative idel handles scenarios where all tasks can be scheduled without remaining idle slots.
Dry Run :
Let's dry run the first test case: tasks = ["A","A","A","B","B","B"], n = 2

Count the frequency of each task:
Frequency of A = 3
Frequency of B = 3
All other tasks have frequency 0.
Sort the freq array: [0, 0, 0, ..., 3, 3]
Calculate chunk as 3 - 1 = 2.
Calculate idle as 2 * 2 = 4.
Iterate from index 24 to 0 in the freq array:
For index 24 (B's frequency), idel -= min(2, 3) => idel -= 2.
For index 23 (A's frequency), idel -= min(2, 3) => idel -= 2.
Other frequencies are 0, so no changes to idel.
Return idel < 0 ? tasks.size() : tasks.size() + idel, which is 8.
Thus, the output is 8, which matches the expected result.
