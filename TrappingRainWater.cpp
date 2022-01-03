#include <stack>
#include <utility>
#include <algorithm>

//monotonic stack
class Solution {
public:
    int trap(vector<int>& height) {
        //find next higher bar for every bar
        stack<pair<int, int>> mono_stack;
        vector<int> gre(height.size(), -1);
        for(int i=height.size()-1; i>=0; i--) {
            int last = -1;
            while(!mono_stack.empty() && (height[i] > mono_stack.top().second)) {
                last = mono_stack.top().first;
                mono_stack.pop();
            }
            gre[i] = mono_stack.empty() ? last : mono_stack.top().first;
            mono_stack.push(make_pair(i, height[i]));
        }

        int ans=0;
        for(int i=0; i<gre.size()-1; i++) {
            int len = gre[i] - 1 - i;
            ans += len * min(height[i], height[gre[i]]);
            for(int j=i; j<gre[i]; j++) {
                if(j == i) {
                    continue;
                }
                ans -= height[j];
            }
            i += len;
        }
        return ans;
    }
};