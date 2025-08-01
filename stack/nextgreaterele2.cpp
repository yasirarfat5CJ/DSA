class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        stack<int>s;
        for(int i=2*n-1;i>=0;i--){
            while(s.size()>0 && nums[s.top()]<=nums[i%n]){
                s.pop();
            }
            ans[i%n]=s.empty()?-1:nums[s.top()];
            s.push(i%n);
        }
        return ans;
    }
};

/*In this problem we r given an circular arr where we have to find the next graeter element
as the arr is circular last element of arr points to first ele of arr

to solve this problem we assume the arr of size 2n and apply the same concept of next graeter ele1 
for every ith idx we do i%n so that it will be in  the range of arr size
*/