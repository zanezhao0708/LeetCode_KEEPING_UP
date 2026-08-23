int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int queue[rows * cols][2];
    int front = 0;
    int rear = 0;

    int fresh = 0;

    // 1. 找到所有腐烂橘子
    // 同时统计新鲜橘子的数量
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // 没有新鲜橘子
    if (fresh == 0)
        return 0;

    int minutes = 0;

    // 上、下、左、右
    int directions[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    // 2. BFS
    while (front < rear && fresh > 0) {

        // 当前这一分钟有多少个腐烂橘子
        int size = rear - front;

        for (int i = 0; i < size; i++) {

            int row = queue[front][0];
            int col = queue[front][1];
            front++;

            // 检查四个方向
            for (int d = 0; d < 4; d++) {

                int newRow = row + directions[d][0];
                int newCol = col + directions[d][1];

                // 越界
                if (newRow < 0 || newRow >= rows ||
                    newCol < 0 || newCol >= cols)
                    continue;

                // 只感染新鲜橘子
                if (grid[newRow][newCol] != 1)
                    continue;

                // 新鲜 -> 腐烂
                grid[newRow][newCol] = 2;
                fresh--;

                // 新腐烂的橘子加入队列
                queue[rear][0] = newRow;
                queue[rear][1] = newCol;
                rear++;
            }
        }

        // 当前这一层处理完成 = 过去一分钟
        minutes++;
    }

    // 如果还有新鲜橘子，说明无法全部感染
    if (fresh > 0)
        return -1;

    return minutes;
}