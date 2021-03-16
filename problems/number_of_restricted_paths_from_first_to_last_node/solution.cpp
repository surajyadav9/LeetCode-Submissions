typedef pair<int, int> ii;
typedef long long ll;
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<ii> adj[n+1];
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Implementing Dijkstra Algo
        
        vector<int> dist(n + 1, INT_MAX);
        priority_queue< ii, vector<ii>, greater<ii> > mpq;
        
        dist[n] = 0;
        mpq.push({0, n});
        
        
		int u, v, w;
        while (!mpq.empty()) {
            ii p = mpq.top(); mpq.pop();
            u = p.second;
            for (auto& to : adj[u]) {
                v = to.first, w = to.second;
                
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    mpq.push({dist[v], v});
                }
            }
        }
        
        vector<ll> paths(n + 1, 0);
        return dfs(1, n, adj, paths, dist);
    }
    
    ll dfs(int s, int n, vector<ii> adj[n+1], vector<ll>& paths, vector<int>& dist) {
        // const int mod = 1e9+7;
        
        if (s == n) return 1LL;
        if (paths[s] > 0) return paths[s];
        // int sum = 0;
        for (auto& to : adj[s]) {
            int u = to.first;
            if (dist[s] > dist[u]) {
                paths[s] = (paths[s] + dfs(u, n, adj, paths, dist));
            }
        }
        return paths[s] % 1000000007;
    }
};