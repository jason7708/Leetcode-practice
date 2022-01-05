class Solution {
public:
    vector<vector<string>> ans;
    vector<string> one_ans;
    vector<vector<string>> partition(string s) {
        int len = s.size();
        int left = 0, right = len-1;
        //dp[i][j] means substring from i to j is palindrome
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        dfs(dp, s, left, right);
        return ans;
    }
    void dfs(vector<vector<bool>> &dp, string s, int left, int right) {
        if(left > right) {
            ans.push_back(one_ans);
            return;
        }
        //first cut at i
        //check left side is palindrome or not
        //if yes dfs right side
        for(int i=left; i<=right; i++) { 
            // smaller than 2 && s[left] == s[i]   is palindrome
            if(s[left] == s[i] && (i-left <=2 || dp[left+1][i-1] == true)) {
                dp[left][i] = true;
                one_ans.push_back(s.substr(left, i-left+1));
                dfs(dp, s, i+1, right);
                //clear one_ans to get next ans
                one_ans.pop_back();
            }
        }
    }
};