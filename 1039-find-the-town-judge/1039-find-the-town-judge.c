int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int graph[n + 1][n + 1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < trustSize; i++){
        int a = trust[i][0];
        int b = trust[i][1];
        graph[a][b] = 1;
    }
    for(int i = 1; i <= n; i++){

        int out = 0;
        int in = 0;

        for(int j = 1; j <= n; j++){

            if(graph[i][j] == 1){
                out++;
            }

            if(graph[j][i] == 1){
                in++;
            }
        }

        if(out == 0 && in == n - 1){
            return i;
        }
    }

    return -1;
}