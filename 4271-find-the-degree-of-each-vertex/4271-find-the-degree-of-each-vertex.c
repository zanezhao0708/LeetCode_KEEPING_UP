/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDegrees(int** matrix, int matrixSize, int* matrixColSize,int* returnSize) {
    *returnSize = matrixSize;

    int * arr = (int*)calloc(matrixSize, sizeof(int));
    for(int i = 0;i < matrixSize-1;i++){
        for(int j = i+1;j < matrixSize; j++){
            if(matrix[i][j]==1){//遍历到有一个边
                arr[i]++;
                arr[j]++;
            }
        }
    }
    return arr;
}