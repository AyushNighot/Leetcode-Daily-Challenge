class Solution {
public:
    int findCenter(vector<vector<int>> &edges) {
        ios_base::sync_with_stdio(0); // Speed up I/O operations

        // Number of nodes in the graph is number of edges + 1
        int numberOfNodes = edges.size() + 1;
        vector<int> nodeDegreeCount(numberOfNodes + 1, 0); // Degree count array

        // Iterate through each edge to count the degree of each node
        for (const vector<int> &edge : edges) {
            nodeDegreeCount[edge[0]]++;
            nodeDegreeCount[edge[1]]++;
        }

        // The center node will have a degree equal to number of edges
        for (int node = 1; node <= numberOfNodes; node++) {
            if (nodeDegreeCount[node] == edges.size()) {
                return node;
            }
        }

        return -1; // In case no center is found, though it's guaranteed in a valid star graph
    }
};
