void dfs(char** graph, int rows, int cols,int visited[rows][cols], int r, int c) {
    visited[r][c] = 1;

    if (c+1 < cols &&graph[r][c+1] =='1'&&visited[r][c+1] == 0) dfs(graph, rows, cols, visited, r, c+1);
    if (r+1 < rows &&graph[r+1][c] =='1'&&visited[r+1][c] == 0)dfs(graph, rows, cols, visited, r+1, c);
    if (c-1 >= 0 &&graph[r][c-1] =='1'&&visited[r][c-1] == 0)dfs(graph, rows, cols, visited, r, c-1);
    if (r-1 >= 0 &&graph[r-1][c] =='1'&&visited[r-1][c] == 0)dfs(graph, rows, cols, visited, r-1, c);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int count = 0;
    int visited[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1' && visited[i][j] == 0) {
                count++;
                dfs(grid, rows, cols, visited, i, j);
            }
        }
    }
    return count;
}