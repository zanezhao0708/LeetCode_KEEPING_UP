
void dfs(int** graph, int n, int start, int* visited){
    for(int i = 0;i < n;i++){
        if(graph[start][i] == 1 && visited[i] == 0){
            visited[i] = 1;
            dfs(graph,n,i,visited);
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
            dfs(isConnected,isConnectedSize,i,visited);
        }
    }
    return count;
}
