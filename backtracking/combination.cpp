class Solution {
public:
   void getComb(vector<int>& nums,int idx,int &k,  vector<vector<int>>&res,vector<int>ans){
      if(ans.size()==k){
        res.push_back(ans);
        return;
      }
       
      for(int i=idx;i<nums.size();i++){
        ans.push_back(nums[i]);
          getComb(nums,i+1,k,res,ans);
          ans.pop_back();
      }
   }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        vector<int>ans;
        vector<vector<int>>res;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
         getComb(nums,0,k,res,ans);
         return res;
      
    }
};
/*In this problem we are given n and k 
we need to get the comb of size k in the range of 1 to n
for that we convet 1 to n into an array 
written an function to get all posible combination
by using classical pattern of backtracking */