class Solution {
public:
    typedef vector<vector<int>> GRAPH;
    vector<bool>vis;
    vector<int>path;
    void dfs(int node, GRAPH& graph){
        path.push_back(node);
        vis[node] = true;
        for(auto adj: graph[node]){
            if(!vis[adj])dfs(adj, graph);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& p) {
        GRAPH graph = vector<vector<int>>(s.size());
        for(int x = 0; x<p.size(); x++){
            int from = p[x][0], to = p[x][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        string ret = s;
        vis.resize(s.size(), false);
        for(int x = 0; x<s.size(); x++){
            path.clear();
            if(!vis[x]) dfs(x, graph);
            string sub;
            for(auto it: path){
                sub += s[it];
            }
            sort(path.begin(), path.end());
            sort(sub.begin(), sub.end());
            for(int x = 0; x<path.size(); x++){
                ret[path[x]] = sub[x];
            }
        }
        return ret;
        
    }
};