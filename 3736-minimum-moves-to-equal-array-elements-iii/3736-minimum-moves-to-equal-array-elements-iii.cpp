class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ele = *max_element(nums.begin(), nums.end());
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != ele){
                result += (ele - nums[i]);
            }
        }
        return result;
    }
};