bool canFinish(int numCourses, int** prerequisites,int prerequisitesSize, int* prerequisitesColSize) {
    int in_degree[2000] = {0};
    int out_degree[2000] = {0};
    int path[numCourses][numCourses];

    for(int i = 0;i<prerequisitesSize;i++){
        int pre = prerequisites[i][1];
        int rear = prerequisites[i][0];

        path[pre][out_degree[pre]++] = rear;
        in_degree[rear]++;
    }

    int queue[2000];
    int front = 0;
    int rear = 0;
    for(int i = 0;i<numCourses;i++){
        if(in_degree[i] == 0)queue[rear++] = i;
    }

    while(front < rear){
        int cur = queue[front++];
        for(int j = 0;j<out_degree[cur];j++){
            int delete = path[cur][j];
            in_degree[delete]--;
            if(in_degree[delete] == 0)queue[rear++] = delete;
        } 

    }
    return numCourses == rear;
}