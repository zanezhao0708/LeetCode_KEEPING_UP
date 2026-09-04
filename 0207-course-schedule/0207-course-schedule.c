bool canFinish(int numCourses, int** prerequisites,int prerequisitesSize, int* prerequisitesColSize) {
    int graph[2000][2000];
    int indegree[2000] = {0};
    int outdegree[2000] = {0};

    for(int i = 0;i<prerequisitesSize;i++){
        int pre = prerequisites[i][1];
        int course = prerequisites[i][0];

        graph[pre][outdegree[pre]++] = course;
        indegree[course]++;
    }
    
    int queue[2000];
    int front = 0;
    int rear = 0;
    for(int i = 0;i < numCourses;i++){
        if(indegree[i] == 0)queue[rear++] = i;
    }

    while(front < rear){
        int cur = queue[front++];
        for(int i = 0;i<outdegree[cur];i++){
            int work = graph[cur][i];
            indegree[work]--;
            if(indegree[work] == 0)queue[rear++] = work;
        }
    }
    return numCourses == rear;
}