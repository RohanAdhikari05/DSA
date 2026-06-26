class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, mid;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (s <= e && nums[mid] == target) {
                return true;
            }
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
                continue;
            }
            if (s <= e && nums[s] <= nums[mid]) {
                if(nums[s]<=target && target<nums[mid]){
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            } else {
                if(target<=nums[e] && nums[mid]<target){
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
        }
        return false;
    }
};