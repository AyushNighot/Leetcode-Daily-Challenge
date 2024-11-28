using pii = pair<int, int>;
const int d[] = {0, 1, 0, -1, 0};
class Solution {
public:
    static int minimumObstacles(vector<vector<int>>& g) {
        const int n = g.size(), m = g[0].size();
        vector<unsigned> dist(n * m, INT_MAX);
        deque<pii> q;
        dist[0] = 0;
        q.push_front({0, 0});
        while (!q.empty()) {
            auto [d1, idx] = q.front();
            q.pop_front();
            int i = idx / m, j = idx % m;
            if (i == n - 1 && j == m - 1) return d1;
            for (int a = 0; a < 4; ++a) {
                int r = i + d[a], c = j + d[a + 1];
                if (r < 0 || r >= n || c < 0 || c >= m) continue;
                int d2 = d1 + g[r][c], idx2 = r * m + c;
                if (d2 < dist[idx2]) {
                    dist[idx2] = d2;
                    if (g[r][c] == 0)
                        q.push_front({d2, idx2});
                    else
                        q.push_back({d2, idx2});
                }
            }
        }
        return -1;
    }
};
