class Solution {
  public:
    void getans(vector<vector<int>>& maze, int r, int c, string curr, vector<string>& ans) {
        int n = maze.size();
        if (r == n - 1 && c == n - 1) {
            ans.push_back(curr);
            return;
        }

        if (r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0)
            return;

        maze[r][c] = 0; 

        getans(maze, r + 1, c, curr + 'D', ans);
        getans(maze, r - 1, c, curr + 'U', ans);
        getans(maze, r, c + 1, curr + 'R', ans);
        getans(maze, r, c - 1, curr + 'L', ans);

        maze[r][c] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        if (maze[0][0] == 0) return ans; 
        getans(maze, 0, 0, "", ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
/*the problem is we have an 2d matrix and rat .rat has to reach n-1,n-1 postition from 0,0 position
here we are having four option to move D U R L 
rat will to move to the cell which consist of 1.

to solve this we are using an backtracking approach 
as we have  to find all possible paths we use recursion 
and call function r+1 for 'D r-1 for 'U' and c+1 for 'R' and 
c-1 for 'L'

once we we visit the  cell we should not again visit so we are 
marking 0 to that cell


when we reach to n-1,n-1 we push path to res
*/