class Solution {
public:
    typedef vector<vector<int>> GRAPH;
    map<int, map<int , bool>> directedEdge;
    vector<bool>vis;
    int ans = 0;
    
    void dfs(int node, GRAPH& graph){
        vis[node] = true;
        for(auto adj: graph[node]){
            if(!vis[adj]){
                if(directedEdge[node][adj]) {
                    cout<<node<<" "<<adj<<"\n";
                    ans ++;
                }
                dfs(adj, graph);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections){
        GRAPH graph = vector<vector<int>>(n);
        vis.resize(n, false);
        for(int x = 0; x<connections.size(); x++){
            int from = connections[x][0] , to = connections[x][1];
            directedEdge[from][to] = true;
            graph[from].push_back(to);
            graph[to].push_back(from);
            
        }
        dfs(0, graph);
        return ans;
        
    }
};