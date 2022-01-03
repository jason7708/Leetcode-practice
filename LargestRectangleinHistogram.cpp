#include <stack>
#include <algorithm>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> mono_stack;
        int rec = 0;
        for(int i=0; i<heights.size(); i++) {
            while(!mono_stack.empty() && (heights[i] < heights[mono_stack.top()])) {
                int h = heights[mono_stack.top()];
                mono_stack.pop();
                
                int w = mono_stack.empty() ? i : i-mono_stack.top()-1;
                rec = max(rec, h*w);
            }
            mono_stack.push(i);
        }
        return rec;
    }
};