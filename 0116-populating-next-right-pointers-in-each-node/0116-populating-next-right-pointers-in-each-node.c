/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	if(!root) return NULL;
    int rear = 0;
    int front = 0;
    struct Node* queue [100000];
    queue[rear++] = root;

    while(front < rear){
        int len = rear - front;
        for(int i = 0;i < len;i++){
            if(i == len-1)queue[front]->next = NULL;
            else queue[front]->next = queue[front+1];
            
            if(queue[front]->left)queue[rear++] = queue[front]->left;
            if(queue[front]->right)queue[rear++] = queue[front]->right;
            front++;

        }
    }
    return root;
}