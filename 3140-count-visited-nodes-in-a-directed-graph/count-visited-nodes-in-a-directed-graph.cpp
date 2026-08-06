class Solution {
public:
    vector<int> ans;
    vector<int> vis;

    int dfs(int node, vector<int>& edges) {
        if (ans[node] != 0)
            return ans[node];

        return ans[node] = 1 + dfs(edges[node], edges);
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();

        vector<int> indegree(n, 0);

        for (int v : edges)
            indegree[v]++;

        queue<int> q;

        vector<int> removed(n, 0);

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            removed[u] = 1;

            int v = edges[u];

            if (--indegree[v] == 0)
                q.push(v);
        }

        ans.assign(n, 0);
        vis.assign(n, 0);

        // Find every cycle
        for (int i = 0; i < n; i++) {

            if (removed[i] || vis[i])
                continue;

            int cur = i;
            int len = 0;

            while (!vis[cur]) {
                vis[cur] = 1;
                cur = edges[cur];
                len++;
            }

            cur = i;

            while (ans[cur] == 0) {
                ans[cur] = len;
                cur = edges[cur];
            }
        }

        // Compute answers for tree nodes
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0)
                dfs(i, edges);
        }

        return ans;
    }
};