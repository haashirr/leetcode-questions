class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>arr;
        vector<int>indegree(numCourses,0);
        vector<int>adj[numCourses];
        for(auto i:prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++) {
            for(auto it:adj[i]) {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            arr.push_back(node);
            for(auto i:adj[node]) {
                indegree[i]--;
                if(indegree[i]==0) {
                    q.push(i);
                }
            }
        }
       if(arr.size()==numCourses) return arr;
       return vector<int>();
    }
};