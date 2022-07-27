/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
vector<Employee*> emps;
int dfs(int id){
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
        return dfs(id);
        return 0;
    }
};