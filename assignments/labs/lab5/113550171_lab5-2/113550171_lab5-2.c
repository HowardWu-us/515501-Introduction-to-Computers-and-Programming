#include <stdio.h>


void rearrangeArray(int *c, int size) {
    for(int i=0;i<(size+1)*(size+1);i++){
        for(int j=0;j<size-1;j++){
            if(((c[j]%2+2) %2)<((c[j+1]%2+2) %2)){
                int tmp = c[j];
                c[j] = c[j+1];
                c[j+1] = tmp; 
            }
        }
    }
}
void printArray(int c[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
}
int main() {
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }
    rearrangeArray(&arr, size);
    printArray(arr, size);
    return 0;
}