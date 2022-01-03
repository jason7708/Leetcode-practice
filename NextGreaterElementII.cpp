#include <stack>

//go through twice

class Solution {
public:
    stack<int> mono_stack;
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        find(ans, nums);
        find(ans, nums);
        return ans;
    }
    void find(vector<int> &ans, vector<int> &nums) {
        for(int i=nums.size()-1; i>=0; i--) {
            while(!mono_stack.empty() && nums[i] >= mono_stack.top()) {
                mono_stack.pop();
            }
            ans[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(nums[i]);
        }
    }
};