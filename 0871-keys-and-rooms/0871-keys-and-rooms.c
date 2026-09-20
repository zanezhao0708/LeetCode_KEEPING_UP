void dfs(int** rooms, int roomsSize, int* roomsColSize,int* visited,int i){
    if (visited[i] == 1)
        return;
    visited[i] = 1;

    for (int j = 0; j < roomsColSize[i]; j++) {
        int visit = rooms[i][j];
        dfs(rooms, roomsSize, roomsColSize, visited, visit);
    }
}


bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int visited[roomsSize];
    for(int i = 0;i<roomsSize;i++)visited[i] = 0;
    dfs(rooms,roomsSize,roomsColSize,visited,0);

    for(int i = 0;i<roomsSize;i++)if(visited[i] != 1)return false;
    return true;
}
