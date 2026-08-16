class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            int i=it[0];
            int j=it[1];
            adj[j].push_back(i);
        }
        vector<int>in(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                in[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0)q.push(it);
            }
        }if (ans.size() != numCourses)
    return {};
return ans;
    }
};