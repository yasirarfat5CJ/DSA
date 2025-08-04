class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int zeroes=0;
        int maxi=0;
        while(r<n){
            if(nums[r]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            if(zeroes<=k){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
       
    }
};
/*In this problem we have o find the maximum consecutives ones 
we will follow the techniue of sliding window 
we take two ponters l and r pointing to first element of the array
we fix l and move r if we encounter a zero we increase the count of zeroes
if the count  of zeroes is greater than e will move the window that is if nums[l] is zero we will 
decrease the count of zero and move l and so on;
if the count of zeroes is less  than k then we will update the maximum length that is r-l+1


*/
