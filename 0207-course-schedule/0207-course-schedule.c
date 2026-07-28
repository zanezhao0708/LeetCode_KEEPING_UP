#define QUE_MAX 2000

typedef struct Node {    // 定义链表
    int val;
    struct Node *next;
} Node;

typedef struct GraghNode {   // 邻接表
    int size;
    Node **Lists;            // 每个元素是一个链表头指针
} GraghNode;

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    if (numCourses == 0) return true;

    // 开始构建邻接表
    GraghNode *G = (GraghNode *)malloc(sizeof(GraghNode));
    G->size = numCourses;
    G->Lists = (Node **)malloc(sizeof(Node *) * G->size);

    for (int i = 0; i < G->size; i++) {
        G->Lists[i] = (Node *)malloc(sizeof(Node));
        G->Lists[i]->next = NULL;   // 每个链表只有头结点
    }

    int *Indegree = (int *)malloc(sizeof(int) * G->size);
    memset(Indegree, 0, sizeof(int) * G->size);

    for (int i = 0; i < prerequisitesSize; i++) {
        //[A,B] 等价于 B -> A
        Indegree[prerequisites[i][0]]++;

        Node *node = (Node *)malloc(sizeof(Node));
        node->val = prerequisites[i][0];

        node->next = G->Lists[prerequisites[i][1]]->next;
        G->Lists[prerequisites[i][1]]->next = node;   // 头插法
    }

    int que[QUE_MAX];
    int head = 0, tail = 0;

    for (int i = 0; i < G->size; i++) {
        if (Indegree[i] == 0)
            que[tail++] = i;
    }

    int count = 0;

    while (head < tail) {
        int idx = que[head++];
        count++;

        Node *node = G->Lists[idx]->next;

        while (node) {
            Indegree[node->val]--;

            if (Indegree[node->val] == 0)
                que[tail++] = node->val;

            node = node->next;
        }
    }

    return count == numCourses;
}