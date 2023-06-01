/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/
/*
  approach:
       do a simple dfs on cells containing 0 itself and when we reach at bottom right cell then return ans
*/
class Solution {
public:
    vector<pair<int,int>> v={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    
    // validate function
    bool valid(int i,int j,int n,int m){
         return i>=0 && j>=0 && i<n && j<m;
    }
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 ||grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>> q;
        int visited[n+1][n+1];
        memset(visited,false,sizeof(visited));
        q.push({0,0});
        visited[0][0]=true;
        int ans=0;
        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int k = 0;k < size; k++){
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first, j = p.second;
                if(i==n-1 and j==n-1) return ans;
                for(auto it:v){
                    int x=it.first+i,y=it.second+j;
                        if(!valid(x,y,n,n)) continue;
                           if(grid[x][y]) continue;
                           if(visited[x][y]) continue;
                            q.push({x,y});
                            visited[x][y] = true;
                        }          
            }            
            
        }
        
        return -1;
        
    }
};