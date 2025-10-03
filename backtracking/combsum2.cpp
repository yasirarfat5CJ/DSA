C++
class Solution {
public:
   set<vector<int>>s;
   void combo(vector<int>&arr,vector<vector<int>>&ans,int st,int target,vector<int>&curr){
        int n=arr.size();
       
        if(target==0){
            if(s.find(curr)==s.end()){
                ans.push_back(curr);
                s.insert(curr);
            }
            return;
        }
        for(int i=st;i<n;i++){
            if(i>st && arr[i]==arr[i-1]) {
                continue;
            }
            if(arr[i]>target) break;
            curr.push_back(arr[i]);
            combo(arr,ans,i+1,target-arr[i],curr);
            curr.pop_back();
        }
       

   }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        combo(candidates,ans,0,target,curr);
        return ans;
    }
};

/*Similar combsum1 here a number is used only once and duplicates we need to skip 
set is  used to store all unique combinations */