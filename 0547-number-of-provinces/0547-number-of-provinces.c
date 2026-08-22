
void bfs(int** graph, int n, int start, int* visited){
    int queue[n];
    int front = 0;
    int rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    int count = 0;

    while(front < rear){
        int node = queue[front++];
        for(int i = 0;i < n;i++){
            if(graph[node][i] == 1 && visited[i] != 1){
                visited[i] = 1;
                bfs(graph,n,i,visited);
            }
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int count = 0;
    int visited[isConnectedSize];
    for(int i = 0;i < isConnectedSize;i++)visited[i] = 0;

    for(int i = 0;i < isConnectedSize;i++){
        if(visited[i] == 0){
            count++;
            bfs(isConnected,isConnectedSize,i,visited);
        }
    }
    return count;
}
