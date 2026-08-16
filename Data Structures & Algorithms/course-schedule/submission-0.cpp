class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            int i=it[0];
            int j=it[1];
            adj[j].push_back(i);
        }
        vector<int>in(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i])in[it]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            count++;
            for(auto it:adj[f]){
                in[it]--;
                if(in[it]==0)q.push(it);
            }
        }if(count==numCourses)return true;
        return false;
    }
};
