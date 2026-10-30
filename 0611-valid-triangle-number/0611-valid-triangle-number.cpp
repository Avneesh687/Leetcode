class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int l = j + 1, r = nums.size() - 1;
                int a = nums[i];
                int b = nums[j];
                int idx = -1;

                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    int c = nums[mid];
                    if (a + b > c) {
                        idx = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                if (idx != -1)
                    ans += idx - j;
            }
        }
        return ans;
    }
};