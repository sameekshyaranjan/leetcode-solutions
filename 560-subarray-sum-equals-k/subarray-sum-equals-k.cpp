class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int sum=0;
        map<int, int> presummap;

        presummap[0]=1;

        for(int i=0;i<n;i++){
            sum=sum+nums[i];

            int rem=sum-k;
            if(presummap.find(rem)!=presummap.end()){
               cnt+=presummap[rem];
            }  

            presummap[sum]+=1;    
        }
        return cnt;
    }
};