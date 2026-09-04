bool canFinish(int numCourses, int** prerequisites,int prerequisitesSize, int* prerequisitesColSize) {

    // graph[i][j] 表示 i 的第 j 个后继课程
    int graph[2000][2000];
    int outdegree[2000] = {0};
    int indegree[2000] = {0};

    // 建图
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];

        // pre -> course
        graph[pre][outdegree[pre]++] = course;
        indegree[course]++;
    }

    // 队列，保存当前入度为 0 的节点
    int queue[2000];
    int front = 0;
    int rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;//已处理的节点个数

    while (front < rear) {
        int cur = queue[front++];
        count++;

        // 删除 cur 的所有出边
        for (int i = 0; i < outdegree[cur]; i++) {
            int next = graph[cur][i];

            indegree[next]--;

            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }

    // 所有课程都能被拓扑排序 => 无环
    return count == numCourses;
}