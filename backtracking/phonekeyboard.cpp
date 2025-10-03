class Solution {
  public:
    void lettercomb(vector<int> &arr, int idx, string curr, string mapping[], vector<string> &res) {
        if (idx >= arr.size()) {
            res.push_back(curr);
            return;
        }
         
        string value = mapping[arr[idx]];
         if (value == "") {
            lettercomb(arr, idx + 1, curr, mapping, res);
            return;
        }
        for (int i = 0; i < value.length(); i++) {
            curr.push_back(value[i]);
            lettercomb(arr, idx + 1, curr, mapping, res);
            curr.pop_back();  // backtrack
        }
    }
    
    vector<string> possibleWords(vector<int> &arr) {
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string curr = "";
        lettercomb(arr, 0, curr, mapping, res);
        return res;
    }
};
/*we are given an array where we need to form the combinations of letters by using arr values

for that we are doing an mapping  string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

now the problem gets simplified we just need to find the combinations by using recursion nad backtrack

base case hits when idx >=arr.size() here we get one combination we push into an result

if the string is empty we just skip we go to next by callng an function
*/