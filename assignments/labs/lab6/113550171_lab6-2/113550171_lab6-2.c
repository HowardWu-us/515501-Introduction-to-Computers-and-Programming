# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

Node *head = NULL;

void insert(int p, int d){


    if(head==NULL) {
        head = malloc(sizeof(Node*));
        head->next = NULL;  
        head->data = 0;

    }
    Node *pointer = head;
    for(int i=0;i<p;++i) {
        pointer = pointer->next;
        if(pointer==NULL) {
            printf("Invalid insertion\n");
            return;
        }
    }

    pointer = head;
    for(int i=0;i<p;++i) {
        pointer = pointer->next;
    }
    Node *newNode = malloc(sizeof(Node*));
    newNode->data = d;
    newNode->next = pointer->next;
    pointer->next = newNode;
}

void printList(){
    Node* node;
    if(head == NULL) {
        printf("\n");
        return;
    } else {
        node = head->next;
    }
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
    head = NULL;
}

int main(){
    int position, data;
    char op;
    while(scanf(" %c", &op) != EOF){
        switch(op){
            case 'A':
                scanf("%d%d", &position, &data);
                insert(position, data);
                break;
            case 'B':
                printList();
                break;
            case 'C':
                freeList();
                break;
            default:
                printf("Wrong OP\n");
                break;
        }
    }
    return 0;
}