/*
*bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
bool canFinish：判断我是否能学完numCourses 门课程
int numCourses：学习课程的数量
int** prerequisites：课程关系表
int prerequisitesSize：课程关系表长度
int* prerequisitesColSize:课程关系表的列长
返回值：能学完返回true
        不能返回false
*/
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    if(prerequisitesSize == 0)
    {
        return true;
    }
    int * ans = malloc(sizeof(int) * numCourses);
    int i = 0;
    for(i = 0; i < numCourses; i++)//初始化为0
    {
        ans[i] = 0;
    }
    int m = prerequisitesSize;
    int j = 0;
    int res = 0;
    for(i = 0; i < prerequisitesSize; i++)//更新每个点的入度
    {
        ans[prerequisites[i][0]]++;
    }
    for(i = 0; i < numCourses; i++)
    {
        if(ans[i] == 0)//当前科目i学完了
        {
            res++;//学完的科目总数+1
            if(res == numCourses)//总数等于我要学的科目，说明我全部可以学完
            {
                return true;
            }
            for(j = 0; j < prerequisitesSize; j++)//更新以我为入度的点的入度
            {
                if(prerequisites[j][1] == i)
                {
                    ans[prerequisites[j][0]]--;
                }
            }
            ans[i]--;//避免重复比较
            i = -1;
        }
    }
    return false;
}

