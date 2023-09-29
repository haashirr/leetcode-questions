class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++) {
            int left = i+1;
            int right = nums.size()-1;
            while(left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==target) {
                    return sum;
                }
                if(abs(sum-target)<abs(ans-target)) {
                    ans = sum;
                }
                if(sum<target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ans;
    }
};