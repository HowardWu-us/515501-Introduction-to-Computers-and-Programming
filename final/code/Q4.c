# include <stdio.h>
# include <stdlib.h>

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
        tes = tes->next;
    }
}

int main(){
    head = malloc(sizeof(Node));
    head->next = NULL;
    tail = head;

  	// Read input to linked list
    int x;
    int N;
    while(scanf("%d", &x)!=EOF) {
        if(x==0) break;
        add_num(x);
        N++;
    }
  
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
