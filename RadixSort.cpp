class Solution {
public:
    using int2 = pair<int, int>; // (difficulty[i], profit[i])
    
    inline static void radix_sort(vector<int2> & pair) {
        vector<int2> bucket[64];
        // 1st round
        for (auto& [x, i] : pair)
            bucket[x & 63].emplace_back(x, i);
        int index = 0;
        for (auto& B : bucket) {
            for (auto& v : B)
                pair[index++] = v;
            B.clear();
        }
        // 2nd round
        for (auto& [x, i] : pair)
            bucket[(x >> 6) & 63].emplace_back(x, i);
        index = 0;
        for (auto& B : bucket) {
            for (auto& v : B)
                pair[index++] = v;
            B.clear();
        }
        // 3rd round
        for (auto& [x, i] : pair)
            bucket[(x >> 12)].emplace_back(x, i);
        index = 0;
        for (auto& B : bucket) {
            for (auto& v : B)
                pair[index++] = v;
            B.clear();
        }
    }

    inline static void radix_sort(vector<int> & nums) {
        vector<int> bucket[64];
        // 1st round
        for (auto x : nums)
            bucket[x & 63].emplace_back(x);
        int index = 0;
        for (auto& B : bucket) {
            for (auto v : B)
                nums[index++] = v;
            B.clear();
        }
        // 2nd round
        for (auto x : nums)
            bucket[(x >> 6) & 63].emplace_back(x);
        index = 0;
        for (auto& B : bucket) {
            for (auto v : B)
                nums[index++] = v;
            B.clear();
        }
        // 3rd round
        for (auto x : nums)
            bucket[x >> 12].emplace_back(x);
        index = 0;
        for (auto& B : bucket) {
            for (auto v : B)
                nums[index++] = v;
            B.clear();
        }
    }

    static int maxProfitAssignment(vector<int> & difficulty, vector<int> & profit,
                            vector<int> & worker) {
        const int n = profit.size(), m = worker.size();
        vector<int2> d_p(n);
        for (int i = 0; i < n; i++)
            d_p[i] = {difficulty[i], profit[i]};

        radix_sort(d_p);
        radix_sort(worker);

        int maxProfit = 0, idx = 0, bestProfit = 0;

        for (int i = 0; i < m; i++) {
            // Increase index to the next worker's ability
            while (idx < n && worker[i] >= d_p[idx].first) {
                bestProfit = max(bestProfit, d_p[idx].second);
                idx++;
            }
            maxProfit += bestProfit;
        }
        return maxProfit;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
