class Solution {
public:
    int minMoves(vector<int>& nums) {

        int minVal = INT_MAX;

        for (int num : nums) {
            minVal = min(minVal, num);
        }
        int ans = 0;
        for (int num : nums) {
            ans += num - minVal;
        }
        return ans;
    }
};