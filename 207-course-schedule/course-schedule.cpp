class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        
        vector<vector<int>> adj(n);
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> d(n, 0);
        
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                d[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(d[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto it : adj[node]){
                d[it]--;
                if(d[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return topo.size() == n;
    }
};