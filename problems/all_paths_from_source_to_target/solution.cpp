class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // vector of vector to store paths
        vector<vector<int>> res;
        
        // temporary path
        vector<int> path;
        
        // dfs call
        dfs(0, res, path, graph);
        
        return res;
    }
    
    void dfs(int s, vector<vector<int>> &res, vector<int> path, vector<vector<int>> g) {
        // Push current node into path
        path.push_back(s);
        
        // If the current node is last node then we got a complete path
        if(s==(int)g.size()-1) {
            res.push_back(path); // Push the path into result array
            return;
        }
        
        for(int w: g[s]) {
            dfs(w, res, path, g);
        }
    }
};