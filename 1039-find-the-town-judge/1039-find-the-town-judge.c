int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int ans[n+1][n+1];
    
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<n+1;j++)ans[i][j] = 0;
    }   

    for(int i = 0;i<trustSize;i++){
        int a = trust[i][0];
        int b = trust[i][1];
        ans[a][b] = 1;
    }

    for(int i = 1;i<n+1;i++){
        int count1 = 0;
        for(int j = 1;j<n+1;j++){//是否相信别人
            if (ans[i][j] == 1)  
            count1++;
        }
        int count2 = 0;
        for(int j = 1;j<n+1;j++){//是否被别人相信
            if (ans[j][i] == 1)  
            count2++;
        }
        if(count1 == 0 && count2 == n-1)return i;
    } 
    
    return -1;
}