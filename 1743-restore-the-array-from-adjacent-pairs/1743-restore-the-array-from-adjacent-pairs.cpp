class Solution {
public:
    typedef map<int, vector<int>> GRAPH;
    vector<int>ret;
    void dfs(int node, int prev, GRAPH& graph){
        ret.push_back(node);
        for(int x = 0; x<graph[node].size(); x++){
            if(graph[node][x] != prev){
                dfs(graph[node][x], node, graph);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        GRAPH graph;
        set<int>nodes;
        for(int x = 0; x<pairs.size(); x++){
            graph[pairs[x][0]].push_back(pairs[x][1]);
            graph[pairs[x][1]].push_back(pairs[x][0]);
            nodes.insert(pairs[x][0]);
            nodes.insert(pairs[x][1]);
        }
        for(auto node : nodes){
            if(graph[node].size() == 1){
                dfs(node, -1000000, graph);
                break;
            }
        }
        return ret;
    }
};