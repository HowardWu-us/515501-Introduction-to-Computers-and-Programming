# include <stdio.h>
# include <stdlib.h>
#include <string.h>

    int N=0;
typedef struct node{
    int data;
    struct node* next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void add_num(int d){
    Node *tes = tail;
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = d;
    tes->next = newNode;
    tail = newNode;
    N++;
}
void del_num(int d) {
    Node *tes = head;
    while(tes->next!=NULL) {
        if(tes->next->data == d) {
            if(tes->next == tail) {
                tail = tes;
                free(tes->next);
                tes->next = NULL;

            } else {
                Node *tmp = tes->next;
                tes->next = tes->next->next;
                free(tmp);
            }
            N--;
            break;
        }
        tes = tes->next;
    }
}
void printList(){
  	Node * tes = head->next;
    int isfirst = 1;
    while(tes!=NULL) {
        if(isfirst) {
            isfirst=0;
        } else {
            printf(" ");
        }
        printf("%d", tes->data);
        if(tes == tail) break;
        tes = tes->next;
    }
    printf("\n");
}

int main(){
    head = malloc(sizeof(Node));
    head->next = NULL;
    tail = head;

  	// Read input to linked list
    int x;
    while(scanf("%d", &x)!=EOF) {
        if(x==0) break;
        add_num(x);
    }

    char op[100];
    scanf("%s", op);

    while(1) {
        char StrX[100];
        // printf("<%s>", op);
        if(strcmp(op, "+")==0) {
            while(1) {
                if(scanf("%s", StrX)==EOF) {
                    goto END;
                }
                if((strcmp(StrX, "-")==0 ) || (strcmp(StrX, "+")==0)) {
                    strcpy(op, StrX);
                    break;
                }
                add_num(atoi(StrX));
            }
        } else {
            while(1) {
                if(scanf("%s", StrX)==EOF) {
                    goto END;
                }
                if((strcmp(StrX, "-")==0 )|| (strcmp(StrX, "+")==0)) {
                    strcpy(op, StrX);
                    break;
                }

                del_num(atoi(StrX));
            }
        }

    }
    END:;

  	// Sort the linked list
    for(int i=0;i<N;++i) {
        int mx = -1;
        Node *tes = head;
        for(int j=0;j<N-i;++j) {
            if(mx < tes->next->data) {
                mx = tes->next->data;
            }
            tes = tes->next;
        }
        tes = head;
        while(tes->next->data!=mx) tes = tes->next;
        if(tes->next == tail) continue;
        tail->next = tes->next;
        tail = tes->next;
        tes->next = tes->next->next;
        tail->next=NULL;
    }

  
  	// Output the linked list
	printList();
    return 0;
}
