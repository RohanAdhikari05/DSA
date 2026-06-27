class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1){return x;}
        int s = 0, e = x, mid;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (mid == x/mid) {
                return mid;
            }
            if (mid <= x/mid) {
                s = mid + 1;
            } else {
                e=mid-1;
            }
        }
        return s-1;
    }
};