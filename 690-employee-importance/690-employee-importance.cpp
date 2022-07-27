/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
vector<bool>vis;
vector<Employee*> emps;

int dfs(int id){
    vis[id] = true;
    Employee* emp;
    for(auto it : emps){
        if(it->id == id){
            emp = it;
            break;
        }
    }
    int ret = emp->importance;
    
    for(auto adj: emp->subordinates){
        ret += dfs(adj);
    }
    return ret;
}

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        emps = employees;
        vis.resize(3000, false);
        return dfs(id);
        return 0;
    }
};