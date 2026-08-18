int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int graph[n + 1][n + 1];//注意题目里是从1到n编号

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++)graph[i][j] = 0;//全部初始化为0
    }

    for(int i = 0; i < trustSize; i++){
        int a = trust[i][0];
        int b = trust[i][1];
        graph[a][b] = 1;
    }
    for(int i = 1; i <= n; i++){//从1到n编号
        int out = 0;
        int in = 0;

        for(int j = 1; j <= n; j++){
            if(graph[i][j] == 1)out++;
            if(graph[j][i] == 1)in++;
        }
        if(out == 0 && in == n - 1)return i;
    }
    return -1;
}