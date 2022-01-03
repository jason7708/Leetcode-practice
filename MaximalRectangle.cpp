#include <stack>

//see as n different histogram
//same as find Largest Recrangle in Histogram


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> bar(matrix[0].size()+1, 0);
        int ans = 0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == '0') {
                    bar[j] = 0;
                }
                else {
                    bar[j]++;
                }
            }
            ans = max(ans, findMaxRec(bar));
        }
        return ans;
    }
    int findMaxRec(vector<int> histogram) {
        stack<int> mono_stack;
        int ans = 0;
        for(int i=0; i<histogram.size(); i++) {
            while(!mono_stack.empty() && (histogram[i] < histogram[mono_stack.top()])) {
                int h = histogram[mono_stack.top()];
                mono_stack.pop();
                int w = mono_stack.empty() ? i : i-mono_stack.top()-1;
                ans = max(ans, h*w);
            }
            mono_stack.push(i);
        }
        return ans;
    }
};