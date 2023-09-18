class Solution {
public:
    int solve(vector<int>&nums,int l, int r) {
        int prev = 0;
        int prevPrev = 0;
        for(int i=l;i<=r;i++) {
            int skip = prev;
            int take = nums[i] + prevPrev;
            int temp = max(take,skip);
            prevPrev = prev;
            prev = temp;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) {
            return nums[0];
        }
        if(n==2) {
            return max(nums[0],nums[1]);
        }
        int first = solve(nums,0,n-2); //3
        int second = solve(nums,1,n-1); //3

        return max(first,second); 
    }
};