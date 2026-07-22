/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDegrees(int** matrix, int matrixSize, int* matrixColSize,int* returnSize) {
    *returnSize = matrixSize;

    int * arr = (int*)calloc(matrixSize, sizeof(int));
    for(int i = 0;i < matrixSize;i++){
        for(int j = 0;j < matrixSize; j++){//仅遍历上三角矩阵（不包含对角）
            
            if(matrix[i][j]==1){//遍历到有一个边
                arr[i]++;
            }
        }
    }
    return arr;
}