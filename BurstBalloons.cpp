class Solution {
public:
    vector<int> pad_nums;
    //create dp array to store max coins
    //dp[i][j] means the max coins we can get if we burst all balloons from i to j
    int dp[501][501];
    int maxCoins(vector<int>& nums) {
        //padding the array 1, nums, 1
        pad_nums.push_back(1);
        for(auto num:nums) {
            pad_nums.push_back(num);
        }
        pad_nums.push_back(1);
        
        memset(dp, -1, sizeof(dp));
        
        //because the first and last element is padding (1)
        return Burst(1, pad_nums.size()-2);
    }
    int Burst(int left, int right) { 
        //burst balloons from index left to index right
        //return the max coins we can collect
        if(left > right) {
            //corner (left most / right most)
            //which means no balloons to burst
            return 0;
        }
        if(left == right) {
            //only one
            dp[left][right] = pad_nums[left-1] * pad_nums[left] * pad_nums[left+1];
            return dp[left][right];
        }
        if(dp[left][right] != -1) {
            //if already caculate
            return dp[left][right];
        }
        int ans = -1;
        for(int i=left; i<=right; i++) {
            int this_coins = 0;
            //this situation coins = Burst(left, i-1) + (left-1)*i*(right+1) + Burst(i+1, right)
            this_coins += Burst(left, i-1);
            this_coins += pad_nums[left-1] * pad_nums[i] * pad_nums[right+1];
            this_coins += Burst(i+1, right);
            ans = max(ans, this_coins);
        }
        dp[left][right] = ans;
        return ans;
    }
};
 