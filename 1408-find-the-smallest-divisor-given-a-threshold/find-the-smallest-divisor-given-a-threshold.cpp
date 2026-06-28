class Solution {
public:
    long long findSum(vector<int>& nums, int mid){
        long long total=0;
        for(int i=0; i<nums.size(); i++){
            total+=(nums[i]+mid-1)/mid;
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1, e=*max_element(nums.begin(),nums.end());
        int mid;
        int ans=e;
        while(s<=e){
            mid=s+(e-s)/2;
            long long sum = findSum(nums,mid);
            if(sum<=threshold){
                ans=min(ans,mid);
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    
    }
};