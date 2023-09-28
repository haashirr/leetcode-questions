class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        if(n==0) {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int curr=1;
        int lcs=0;
        for(int i=1;i<n;i++) {
            if(nums[i]!=nums[i-1]) {
                if(nums[i]==nums[i-1]+1) {
                    curr++;
                }
                else {
                    lcs = max(lcs,curr);
                    curr=1;
                }
            }
        }
        return max(lcs,curr);
    }
};