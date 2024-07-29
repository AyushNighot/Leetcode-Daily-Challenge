class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;
        
        vector<pair<int, int>> soldiers;
        for (int i = 0; i < n; i++) {
            soldiers.push_back({rating[i], i});
        }
        sort(soldiers.begin(), soldiers.end());
        
        vector<int> indexMap(n);
        for (int i = 0; i < n; i++) {
            indexMap[soldiers[i].second] = i;
        }
        
        return countTeams(indexMap, n, true) + countTeams(indexMap, n, false);
    }
    
private:
    int countTeams(const vector<int>& indexMap, int n, bool ascending) {
        vector<int> bit(n + 1, 0);
        int teams = 0;
        
        for (int i = 0; i < n; i++) {
            int rank = indexMap[i] + 1;
            int left = ascending ? getSum(bit, rank - 1) : getSum(bit, n) - getSum(bit, rank);
            int right = ascending ? n - rank - (getSum(bit, n) - getSum(bit, rank)) : rank - 1 - getSum(bit, rank - 1);
            teams += left * right;
            update(bit, rank, 1);
        }
        
        return teams;
    }
    
    void update(vector<int>& bit, int index, int val) {
        while (index < bit.size()) {
            bit[index] += val;
            index += index & (-index);
        }
    }
    
    int getSum(const vector<int>& bit, int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }
        return sum;
    }
};
