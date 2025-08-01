class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>mp;
       stack<int>s;
       int n1=nums1.size();
       int n2=nums2.size();
       for(int i=n2-1;i>=0;i--){
          while(s.size()>0 && s.top()<=nums2[i]){
            s.pop();
          }
          if(s.empty()){
            mp[nums2[i]]=-1;
          }else{
            mp[nums2[i]]=s.top();
          }
          s.push(nums2[i]);
          
       }
    vector<int>ans;
    for(int i=0;i<n1;i++){
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
    }
};

/*in this problem we have to find the next graeter ele of every element 
next greater ele:first element which is greater on the right

here we r given two arrys arr1 and arr2  and arr2 is the subset of arr1 
we have to find the next greater element in arr2 for arr1 for that purpose we use data structure called mapping
we traverse from the back  of arr2  and then we check if the stack is not empty and top element is less than current ele
then we pop it  from stack if the stack gets empty we store -1 else we push top og the stack
at the end we traverse the first arr1 and store the ans from map
*/