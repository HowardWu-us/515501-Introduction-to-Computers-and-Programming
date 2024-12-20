#include <stdio.h>

int check_scramble_key(int keys[]); 

int main(void) {
    int N;
    scanf("%d", &N);
    while(N--) {
        int inputs[10] = {0};
        for(int i=0;i<10;++i) {
            scanf("%d", &inputs[i]);
        }
        if(check_scramble_key(inputs) == -1) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}

int check_scramble_key(int keys[]) {
    int arr[10] = {0};
    for(int i=0;i<10;++i) {
        if(arr[keys[i]]) {
            return 1;
        }
        arr[keys[i]]++;
    }
    return -1;
}