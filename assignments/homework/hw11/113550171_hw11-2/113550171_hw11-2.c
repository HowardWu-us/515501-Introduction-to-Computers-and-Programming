# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;
int NodeCount = 0;

Node *tail = NULL; // 末端
Node *offsetTail = NULL; // 會變動的末端
int offset = 0;
void delete(int p){
    Node *pointer = offsetTail;
    for(int i=0;i<p;++i) {
        pointer = pointer->next;
    }
    // 紀錄現在結點是第幾個
    Node *oldNode = pointer->next;
    if(oldNode==tail) {
        tail = pointer;
    }
    pointer->next = oldNode->next;
    free(oldNode);
}
void insert(int p, int d, int isTail){
    // 如果沒有元素在裡面就建立
    if(tail==NULL) {
        Node *newNode = malloc(sizeof(Node));
        newNode->data = d;
        newNode->next = newNode;
        tail = offsetTail = newNode;
    } else {
        // 找到要insert的前一格
        Node *pointer = offsetTail;
        for(int i=0;i<p;++i) {
            pointer = pointer->next;
        }
        Node *newNode = malloc(sizeof(Node));
        newNode->data = d;
        newNode->next = pointer->next;
        pointer->next = newNode;

        // 如果在最末端要更新tail
        if(isTail) {
            // printf("edit tail from %d to %d\n", tail->data, newNode->data);
            tail = newNode;
        }

        offset += p;
        offsetTail = pointer;
    }
}
void printList(){
    // 跳過第一個
    Node* node = tail->next;
    for(int i=0;i<NodeCount;++i) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void freeList(){
    Node *cur = tail, *tmp;
    while(cur->next == cur) {
        tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
    }
    free(cur);
    tail = offsetTail = NULL;
    NodeCount = 0;
}

int main(){
    int position, data;
    char op;
    while(scanf(" %c", &op) != EOF){
        switch(op){
            case 'A':
                scanf("%d%d", &position, &data);
                if(NodeCount<position) {
                    printf("Invalid insertion\n");
                } else {
                    insert(position-offset, data, NodeCount==position);
                    NodeCount++;
                }
                break;
            case 'B':
                scanf("%d", &position);
                if(NodeCount<=position) {
                    printf("Invalid deletion\n");
                } else {
                    delete(position-offset);
                    NodeCount--;
                }
                break;
            default:
                printf("Wrong OP\n");
                break;
        }
    }
    printList();
    freeList();
    return 0;
}
