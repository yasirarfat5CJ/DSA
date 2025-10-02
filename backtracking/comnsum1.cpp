class Solution {
public:
  set<vector<int>>s;
   void combo(vector<int>& arr,vector<vector<int>>&ans,int i,int target,vector<int>&curr){
   
    int n=arr.size();
    if(i==n|| target<0){
        return;
    }
    if(target==0){
        if(s.find(curr)==s.end()){
           ans.push_back(curr);
           s.insert(curr);
           
        }
        return;
       
    }
   
    curr.push_back(arr[i]);
    combo(arr,ans,i+1,target-arr[i],curr);
    combo(arr,ans,i,target-arr[i],curr);
    curr.pop_back();
    combo(arr,ans,i+1,target,curr);
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>>ans;
          vector<int>curr;
       
       combo(candidates,ans,0,target,curr);
       return ans;

    }
};

/*in this problem we need all unique combinations whose sum is equal to target note:multiple inclusion are allowed
here we  using recusion and backtrack where we at every step 
we perform inclusion ,multiple inclusion and exxlusion with the help of recursion
backtrack steps comes when we need to take an exclusion step so we pop the ele 
set datastructre is used for unique combination*/