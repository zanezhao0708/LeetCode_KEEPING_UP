int dfs(int** grid,int rows,int cols,int row,int col){
    if(row >= rows||row<0||col >= cols||col<0 || grid[row][col] != 1)return 0;
    grid[row][col] = 2;
    
    int left = dfs(grid,rows,cols,row+1,col); 
    int right =dfs(grid,rows,cols,row-1,col);
    int up = dfs(grid,rows,cols,row,col+1);
    int down = dfs(grid,rows,cols,row,col-1);
    return 1+left+right+up+down;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int max = 0;
    int rows  = gridSize;
    int cols = gridColSize[0];
   
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(grid[i][j] == 1){
                int area = dfs(grid,rows,cols,i,j);
                if(area > max)max = area;
            }   
        }
    }

    return max;
}