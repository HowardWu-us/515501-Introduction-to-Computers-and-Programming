# include <stdio.h>
# define N 1024

// global variable array
int arr[N];

int duel(int left, int right){ // 會回傳目前最大的節點，改動會直接修改原本的值，所以可以直接呼叫。
    if(left < right){
        int lans = duel(left, (left+right)/2);
        int rans = duel((left+right)/2+1, right);
        if(arr[lans] >= arr[rans]) { // 等於的話有算在左邊
            arr[lans] -= arr[rans]; // 直接修改原本的值，因為我是將大的剪掉小的，因此必定是正數
            return lans;
        }
        else {
            arr[rans] -= arr[lans];
            return rans;
        }
    }
    if(left == right)
        return left;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
        scanf("%d", &arr[i]);
    int winner = duel(0, n-1);
    printf("%d %d", winner, arr[winner]);
    return 0;
}