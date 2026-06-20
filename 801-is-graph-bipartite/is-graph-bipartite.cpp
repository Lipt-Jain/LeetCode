class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> c(n, -1);

        for (int i = 0; i < n; i++) {
            if (c[i] != -1) continue;

            queue<int> q;
            q.push(i);
            c[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto it : graph[node]) {
                    if (c[it] == -1) {
                        c[it] = !c[node];
                        q.push(it);
                    }
                    else if (c[it] == c[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};