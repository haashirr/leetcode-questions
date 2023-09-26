class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>result;
        priority_queue<vector<int>>pq;
        for(auto p:points) {
            int x = p[0];
            int y = p[1];
            pq.push({x*x + y*y,x,y});
            if(pq.size()>k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            vector<int>t = pq.top();
            pq.pop();
            result.push_back({t[1],t[2]});
        }
        return result;
    }
};