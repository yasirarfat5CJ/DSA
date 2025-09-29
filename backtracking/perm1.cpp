class Solution {
public:
  void getPerms(vector<int>& nums,int idx,vector<vector<int>>&ans){
    if(idx==nums.size()){
        ans.push_back({nums});
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        getPerms(nums,idx+1,ans);
        swap(nums[idx],nums[i]);
    }
  }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        
        getPerms(nums,0,ans);
        return ans;


        
    }
};
/*in  this problem we need  find permutation of an array
It is  nothing all possible arrangements here we are using the conept of backtracking + swapping
at every time we are fixing one elements onece currsize becomes equal to n we push to ans
backtracking step is to  restore the elements back like it was previous */