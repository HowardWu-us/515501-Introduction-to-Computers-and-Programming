#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



int N=0;
int* read_input(int *a){
    a = realloc(a, 10000*sizeof(int));
    int t;
    int pointer = 0;
    while(scanf("%d", &t)==1 && t!=0) {
        a[pointer++] = t;
    }
    N = pointer;

    return a;
}
int cmpe(const void* a, const void* b) {
    return *(int *)a>*(int *)b;
}
int main(){
    int *n_arr;
    n_arr = read_input(n_arr);
    int pos_max,pos_min;
    int neg_max,neg_min;
    int pos_num,neg_num;
    long long pos_sum, neg_sum;
    double pos_avg=0.0, neg_avg=0.0;
    
    pos_max = -1;
    pos_min = 2147483647;
    for(int i=0;i<N;++i) {
        if(n_arr[i] <= 0) continue;
        if(n_arr[i] > pos_max) {
            pos_max = n_arr[i];
        }
        if(n_arr[i] < pos_min) {
            pos_min = n_arr[i];
        }
    }
    neg_min = 1;  
    neg_max = -2147483648;  
    for(int i=0;i<N;++i) {
        if(n_arr[i] >= 0) continue;
        if(n_arr[i] > neg_max) {
            neg_max = n_arr[i];
        }
        if(n_arr[i] < neg_min) {
            neg_min = n_arr[i];
        }
    }
    pos_num = neg_num = pos_sum = neg_sum = 0;
    for(int i=0;i<N;++i) {
        
        if(n_arr[i] > 0) {
            pos_num+=1;
            pos_sum += n_arr[i];
        }
        if(n_arr[i] < 0) {
            neg_num++;
            neg_sum += n_arr[i];
        }
    }

    pos_avg = (double) pos_sum / (double) pos_num;
    neg_avg = (double) neg_sum / (double) neg_num; 
    
    // printf("%d %d\n", neg_num, neg_num);

    printf("pos max: %-13d min: %-13d\n", pos_num==0?0: pos_max, pos_num==0?0:pos_min);
    printf("neg max: %-13d min: %-13d\n", neg_num==0?0:neg_max, neg_num==0?0:neg_min);
    printf("Avg pos: %-13.1lf neg: %-13.1lf\n", pos_num==0 ? 0 : pos_avg, neg_num==0 ? 0 : neg_avg);
    
    qsort(n_arr, N,sizeof(int), cmpe);

    int l = 0;
    while(n_arr[l]<=0) l++;
    printf("Non-unique positive numbers: ");
    int tag, out=0;
    tag = l;
    for(int i=l+1;i<N;++i) {
        if(n_arr[i] == n_arr[tag]) {
            printf("%d ", n_arr[tag]);
            ++out;
            while(i<N && n_arr[i]==n_arr[tag])++i;
            tag = i;
        } else {
            tag = i;
        }
    }
    if(out==0) {
        printf("NULL\n");
    } else {
        printf("\n");
    }
    return 0;
}