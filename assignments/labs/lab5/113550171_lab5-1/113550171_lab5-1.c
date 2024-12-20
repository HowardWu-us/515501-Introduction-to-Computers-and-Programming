#include <stdio.h>
#include <stdlib.h>


int main() {
    int arr[1000] = {10,20,30,40,50};
    int V = 5;
    int pointer = 0;
    int op;
    while(scanf("%d", &op)==1) {
        if(op==1) {
            if(0<=pointer && pointer<V)
                arr[pointer]++;
            else {
                printf("Out of bounds\n");
            }
        } else if(op==2) {
            if(0<=pointer && pointer<V)
                arr[pointer]--;
            else {
                printf("Out of bounds\n");
            }
        } else if(op==3) {
            pointer++;
        } else if(op==4) {
            pointer--;
        } else if(op==5) {
            if(0<=pointer && pointer<V)
                printf("%d\n", arr[pointer]);
            else {
                printf("Out of bounds\n");
            }
        } else if(op==6){
            int v;
            scanf("%d", &v);
            for(int i=0; i<v; i++) {
                arr[i] = 0;
            }
            V = v;
            pointer = 0;
        }
        else {
            printf("Undefined operation\n");
        }
    }
    return 0;
}
