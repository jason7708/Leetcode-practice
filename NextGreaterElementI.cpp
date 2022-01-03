#include <stack>
#include <unordered_map>
//monotonic stack find next greater element

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //monotonic stack
        stack<int> mono_stack;
        unordered_map<int, int> gre;
        for(int i=nums2.size()-1; i>=0; i--) {
            
            while(!mono_stack.empty() && nums2[i] > mono_stack.top()) {
                mono_stack.pop();
            }
            gre[nums2[i]] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(nums2[i]);
        }
        vector<int> ans;
        for(auto num : nums1) {
            ans.push_back(gre[num]);
        }
        return ans;
    }
};
