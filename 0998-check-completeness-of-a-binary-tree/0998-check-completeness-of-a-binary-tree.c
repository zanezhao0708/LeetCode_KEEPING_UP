/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isCompleteTree(struct TreeNode* root) {
    struct TreeNode* queue[100];
    if(!root)return true;

    int rear = 0;
    int front = 0;
    int flag1 = 0;
    queue[rear++] = root;
    while(front < rear){
        int len = rear-front;
        for(int i = 0;i<len;i++){//节点有四种情况
            if(queue[front]->left == NULL&&queue[front]->right !=NULL)return false;//右有，左没有
            
            if(queue[front]->left != NULL&&queue[front]->right ==NULL){//左有，右没有
                if(flag1 == 1)return false;
                else{
                   queue[rear++] = queue[front]->left;
                   flag1 = 1;
                }
            }
            if(queue[front]->left != NULL&&queue[front]->right !=NULL){//左右都有
                if(flag1 == 1)return false;
                else{
                    queue[rear++] = queue[front]->left;
                    queue[rear++] = queue[front]->right;
                }
            }
            if(queue[front]->left == NULL&&queue[front]->right ==NULL){//左右都没有
                    flag1 = 1;
                }
            front++;    
            }
        }
        return true;
    }

