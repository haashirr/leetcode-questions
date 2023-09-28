class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        for(int i=0;i<nums.size();i++) {
            int j=i+1;
            int k = nums.size()-1;
            while(j<k) {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<target) {
                    j++;
                }
                else if(sum>target){
                    k--;
                }
                else {
                    result.push_back({nums[i],nums[j],nums[k]});
                    int temp1 = j, temp2 = k;
                    while(j<k && nums[j]==nums[temp1]) {
                        j++;
                    }
                    while(j<k && nums[k]==nums[temp2]) {
                        k--;
                    }
                }
            }
            while(i+1<nums.size() && nums[i]==nums[i+1]) {
                i++;
            }
        }
        return result;
    }  
};