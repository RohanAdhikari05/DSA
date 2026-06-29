class Solution {
public:
    int findDays(vector<int> weights, int mid) {
        int cnt = 0;
        int i = 0;
        int temp = mid;
        while (i < weights.size()) {
            if (temp - weights[i] < 0) {
                cnt++;
                temp = mid;
            }
            temp -= weights[i];
            i++;
        }
        return cnt+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int maxi = *max_element(weights.begin(),weights.end());
        int s = 0, e = sum, mid;
        int ans = sum;
        while (s <= e) {
            mid = s + (e - s) / 2;
            int total = findDays(weights, mid);
            if (total <= days && mid>=maxi) {
                cout << total << " " << mid << endl;
                ans = min(ans, mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};