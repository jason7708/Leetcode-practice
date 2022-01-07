class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool> (s.size(), false));
        int start = 0, maxlen = 1;
        // check base case len = 1 or 2
        for(int i=0; i<s.size(); i++) {
            dp[i][i] = true;
            if(i == s.size()-1) {
                break;
            }
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                if(2 > maxlen) {
                    start = i;
                    maxlen = 2;
                }
            }
        }
        for(int k=3; k<=s.size(); k++) { //check substring len = k
            for(int i=0; i<(s.size()-k+1); i++) {
                if(s[i] == s[i+k-1] && dp[i+1][i+k-1-1]) { // ex:    'cabac' is pali onoly if 'aba' is pali
                    dp[i][i+k-1] = true;
                    if(k > maxlen) {
                        start = i;
                        maxlen = k;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};