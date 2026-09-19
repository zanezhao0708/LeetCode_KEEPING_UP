
int Find(int* root,int index){
    if(root[index] != index)root[index] = Find(root,root[index]);
    return root[index];
}

void Union(int* root,int index1,int index2){
    root[Find(root,index1)] = Find(root,index2);
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int root[isConnectedSize];
    for(int i = 0;i<isConnectedSize;i++)root[i] = i;

    for(int i = 0;i<isConnectedSize;i++){
        for(int j = i+1;j < isConnectedSize;j++){
            if(isConnected[i][j] == 1)Union(root,i,j);
        }
    }
    int count = 0;
    for(int i = 0;i<isConnectedSize;i++){
        if(root[i] == i)count++;
    }
    return count;

}
