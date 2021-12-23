class Solution {
public:
    int *take;
    vector<vector<int>> req;
    vector<int> ans;
    bool imp = false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        take = new int[numCourses]{0};
        for(int i=0; i<numCourses; i++){
            vector<int> tmp;
            req.push_back(tmp);
        }
        for(int i=0; i<prerequisites.size(); i++){
            req[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0; i<numCourses; i++){
            if(take[i] == 0){
                takeCourse(i);
            }
        }
        if(imp){
            vector<int> emp;
            return emp;
        }
        return ans;
    }
    void takeCourse(int n){
        if(imp == true){
            return;
        }
        if(req[n].empty()){
            take[n] = 2;
            ans.push_back(n);
            return;
        }
        take[n] = 1;
        for(int i=0; i<req[n].size(); i++){
            if(take[req[n][i]] == 0){
                takeCourse(req[n][i]);
            }
            if(take[req[n][i]] == 1){
                //false
                imp = true;
                return;
            }
        }
        take[n] = 2;
        ans.push_back(n);
        return;
    }
};
