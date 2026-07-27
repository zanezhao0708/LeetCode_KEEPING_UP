//等价于拓扑排序判环
#define QUE_MAX 100000

typedef struct Node {
    int val;
    struct Node *next;
} *GraghNode;

typedef struct gNode {
    int size;
    GraghNode *Lists;  // 保存每个节点的邻接节点数组
} *Gragh;             // 邻接表

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    if (numCourses == 0 || numCourses == 1) {
        return true;
    }
    
    Gragh G = (Gragh)malloc(sizeof(struct gNode));// 构建邻接表
    G->size = numCourses;
    G->Lists = (GraghNode *)malloc(sizeof(GraghNode)*G->size);//链表头节点数组
    for (int i = 0; i < G->size; i++) {
        G->Lists[i] = (GraghNode)malloc(sizeof(struct Node));
        G->Lists[i]->next = NULL;
    }
    // 初始化入度数组并赋值
    int *Indegree = (int *)malloc(sizeof(int) * numCourses);
    memset(Indegree, 0, sizeof(int) * numCourses);
    for (int i = 0; i < prerequisitesSize; i++) {
        Indegree[prerequisites[i][0]]++;
        GraghNode node = (GraghNode)malloc(sizeof(struct Node));
        node->val = prerequisites[i][0];
        node->next = G->Lists[prerequisites[i][1]]->next;
        G->Lists[prerequisites[i][1]]->next = node;
    }

    // que保存入度为0的节点
    int que[QUE_MAX];
    int head = 0, tail = 0;
    for (int i = 0; i < numCourses; i++) {
        if (Indegree[i] == 0) {
            que[tail++] = i;
        }
    }

    // 保存拓扑排序的数组
    int *topSortNumber = (int *)malloc(sizeof(int) * numCourses);
    int count = 0;

    // 入度为0的节点出队并将相邻节点入度减一，若减为0则入队
    while (head < tail) {
        int V = que[head];
        topSortNumber[count++] = V;
        // 与V相邻的节点入度减一
        GraghNode node = G->Lists[V]->next;
        while (node) {
            Indegree[node->val]--;
            if (Indegree[node->val] == 0) {
                que[tail++] = node->val;
            }
            node = node->next;
        }
        head++;
    }

    // 若所有节点最终都能入队并出队，则说明有向图无环，能够修完所有课程
    return count == numCourses;

}
