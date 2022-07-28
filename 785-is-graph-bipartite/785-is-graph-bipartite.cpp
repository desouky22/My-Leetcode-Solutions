class Solution {
public:
    vector<bool>vis;
    vector<int>color;
    bool noAns;
    void dfs(int node, int col, int parentColor, vector<vector<int>>& graph){
        if(color[node] == col) return;
        if(color[node] == parentColor){
            noAns = true;
            return ;
        }
        color[node] = col;
        for(auto adj: graph[node]){
            dfs(adj, col == 1 ? 2 : 1, col, graph);
        }
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        color.resize(graph.size(), 0);
        for(int x = 0; x<graph.size(); x++){
            if(color[x] == 0)
                dfs(x, 1, -1, graph);
            if(noAns)return false;
            
        }
        return true;
    }
};