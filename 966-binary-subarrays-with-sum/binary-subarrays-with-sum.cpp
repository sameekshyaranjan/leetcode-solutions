class Solution {

private:
    int subarrays(vector<int>& nums, int goal){
       int left=0, right=0, cnt=0, sum=0;
       int n=nums.size();

       if (goal < 0) return 0;

       while(right<n){
         sum=sum+nums[right];
         
         while(sum>goal){
            sum=sum-nums[left];
            left++;
         }

         cnt=cnt+(right-left+1);
         right++;
       }
       return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarrays(nums,goal)-subarrays(nums,goal-1);
    }
};