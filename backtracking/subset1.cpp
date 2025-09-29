void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
    if(i == nums.size()){              // Base case: end of array
        allSubsets.push_back(ans);     // Store current subset
        return;
    }
    
    // Choice 1: include nums[i]
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i+1, allSubsets);
    
    // Backtrack: remove last element
    ans.pop_back();
    
    // Choice 2: exclude nums[i]
    getAllSubsets(nums, ans, i+1, allSubsets);
}


Start with empty subset []

i=0: nums[0] = 1
   ├── Include 1 → subset = [1]
   │      i=1: nums[1] = 2
   │      ├── Include 2 → subset = [1,2]
   │      │      i=2: nums[2] = 3
   │      │      ├── Include 3 → [1,2,3]  (leaf)
   │      │      └── Exclude 3 → [1,2]   (leaf)
   │      └── Exclude 2 → subset = [1]
   │             i=2: nums[2] = 3
   │             ├── Include 3 → [1,3]  (leaf)
   │             └── Exclude 3 → [1]    (leaf)
   └── Exclude 1 → subset = []
          i=1: nums[1] = 2
          ├── Include 2 → subset = [2]
          │      i=2: nums[2] = 3
          │      ├── Include 3 → [2,3]  (leaf)
          │      └── Exclude 3 → [2]    (leaf)
          └── Exclude 2 → subset = []
                 i=2: nums[2] = 3
                 ├── Include 3 → [3]    (leaf)
                 └── Exclude 3 → []     (leaf)
/*At every step we r deciding wheather the ele has
to include or exclude from the subset */