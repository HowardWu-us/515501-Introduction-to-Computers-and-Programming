/*
我將head也作為一個Node，因為這樣比較好實作
*/
# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

Node *head = NULL;
Node *offsetHead = NULL;
int offset = 0;
void delete(int p){
    Node *pointer = offsetHead;
    for(int i=0;i<p;++i) {
        pointer = pointer->next;
        if(pointer==NULL) {
            printf("Invalid deletion\n");
            return;
        }
    }
    if(pointer->next==NULL) {
        printf("Invalid deletion\n");
        return;
    }
    // 紀錄現在結點是第幾個
    Node *oldNode = pointer->next;
    pointer->next = oldNode->next;
    free(oldNode);
}
void insert(int p, int d){
    Node *pointer = offsetHead;
    for(int i=0;i<p;++i) {
        pointer = pointer->next;
        if(pointer==NULL) {
            printf("Invalid insertion\n");
            return;
        }
    }

    Node *newNode = malloc(sizeof(Node*));
    newNode->data = d;
    newNode->next = pointer->next;
    pointer->next = newNode;

    offset += p;
    offsetHead = pointer;
}
void printList(){
    // 跳過第一個
    Node* node = head->next;
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void freeList(){
    Node *cur = head, *tmp;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    // 順便建立第零個
    head = malloc(sizeof(Node*));
    head->next = NULL;
    head->data = 0;
    offsetHead = head;
}

int main(){
    int position, data;
    char op;
    freeList();
    while(scanf(" %c", &op) != EOF){
        switch(op){
            case 'A':
                scanf("%d%d", &position, &data);
                    insert(position-offset, data);
                break;
            case 'B':
                scanf("%d", &position);
                    delete(position-offset);
                break;
            default:
                printf("Wrong OP\n");
                break;
        }
        // printf("Offset: %d\n",  offset);
        // printf("offset first element: %d\n", offsetHead->data);
        // printList();
        // printf("\n");
    }
    printList();
    freeList();
    return 0;
}