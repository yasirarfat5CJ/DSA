class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.length();
        int maxi=0;
         int hash[256];
        fill(hash, hash + 256, -1);
        int i=0;
        int j=0;
        while(j<n){
             if(hash[s[j]]!=-1){
                if(hash[s[j]]>=i){
                    i=hash[s[j]]+1;
                }
             }
             maxi=max(maxi,j-i+1);
             hash[s[j]]=j;
             j++;
        }
      
        return maxi;
        
    }
};
/*In this problem we have to find the length of the longest subdtring without repeating characters
we maintain a hash  arary of size 256 initialized with -1
we take two pointers i and j pointing to first element of the strig
Check if character was seen:

if(hash[s[j]] != -1 && hash[s[j]] >= i) {
    i = hash[s[j]] + 1;
}
If s[j] has been seen and it was seen inside the current window, move i to one index after the last seen position of s[j].

 This removes duplicates from the current substring.

update the maximum length

*/