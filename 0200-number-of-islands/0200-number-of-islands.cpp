class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        //MARKING THE LAND AS 0 FOR VISITED (INSTEAD OF USING EXTRA VISITED ARRAY)
        grid[i][j]=0;
        int n=grid.size();
        int m=grid[0].size();

        //TRAVERSING ACROSS ALL 4 NEIGHBOURS 
        if(i-1 >= 0 && grid[i-1][j] == '1') dfs(i-1,j,grid);
        if(i+1 < n && grid[i+1][j] == '1')  dfs(i+1,j,grid);
        if(j-1 >= 0 && grid[i][j-1] == '1') dfs(i,j-1,grid);
        if(j+1 < m && grid[i][j+1] == '1') dfs(i,j+1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        //CALCULATE ROWS AND COLUMNS
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;

        //TO FIND THE STARTING POINTS ON AN ISLAND
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
       return ans; 
    }
};