class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mpp;
        vector<int>ans(nums1.size(),-1);

        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && st.top() < nums2[i]){
                mpp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(mpp.find(nums1[i]) != mpp.end()){
                ans[i] = mpp[nums1[i]];
            }
        }
        return ans;
    }
};