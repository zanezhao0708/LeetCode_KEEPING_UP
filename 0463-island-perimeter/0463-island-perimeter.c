int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int peri = 0;

    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if (grid[i][j] == 1){
                peri += 4;
                if (i > 0 && grid[i - 1][j] == 1)peri -= 2;// 检查上方是否有陆地，如果有则减去共享的边
                if (j > 0 && grid[i][j - 1] == 1)peri -= 2;// 检查左侧是否有陆地，如果有则减去共享的边
            }
        }
    }
    return peri;
}