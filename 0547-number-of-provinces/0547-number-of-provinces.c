void dfs(int** graph,int* visited,int node,int n){
    visited[node] = 1;
    for(int i = 0;i < n;i++){
        if(graph[node][i] == 1 && visited[i] != 1)dfs(graph,visited,i,n);//再次调用dfs
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int visited[n];
    for(int i = 0;i < n;i++)visited[i] = 0;
    int count = 0;

    for(int i = 0;i < n;i++){
        if(visited[i] == 0){
            count++;
            dfs(isConnected,visited,i,n);
        }
    }
    return count;
}


