class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            }
        }
        
        int unsatis = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                unsatis += customers[i];
            }
        }
        
        int max = unsatis;
        for (int i = minutes; i < n; i++) {
            if (grumpy[i - minutes] == 1) {
                unsatis -= customers[i - minutes];
            }
            if (grumpy[i] == 1) {
                unsatis += customers[i];
            }
            max = std::max(max, unsatis);
        }
        
        return ans + max;
    }
};
