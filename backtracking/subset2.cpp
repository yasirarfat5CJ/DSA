class Solution {
public:
    void getAllSubsets(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>&subset){
        if(i==nums.size()){
            subset.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getAllSubsets(nums,ans,i+1,subset);
        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
         getAllSubsets(nums,ans,idx,subset);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>subset;
        vector<int>ans;
        int i=0;
        getAllSubsets(nums,ans,i,subset);
        return subset;



        
    }
};
/*similar to prev one here we want only unique subsets for that
we are skiing the duplicates by using while loop before we backtrack*/