class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day) {

        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= day) {

                flowers++;

                if (flowers == k) {
                    m--;
                    flowers = 0;

                    if (m == 0)
                        return true;
                }

            } else {
                flowers = 0;
            }
        }

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size()/k < m) {
            return -1;
        }
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int mid;
        int ans = e;
        while (s <= e) {
            mid = (s + (e - s) / 2);
            if (possible(bloomDay, m, k, mid)) {
                ans = min(mid, ans);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};