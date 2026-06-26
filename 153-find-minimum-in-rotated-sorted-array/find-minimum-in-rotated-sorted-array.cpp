class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        int s=0, e=nums.size()-1, mid;
        while(s<=e){
            mid=s+(e-s)/2;
            mini=min(mini,nums[mid]);
            if(nums[mid]<nums[e]){
                e=mid;
            }else{
                s=mid+1;
            }
            
            
        }
        return mini;
    }
};