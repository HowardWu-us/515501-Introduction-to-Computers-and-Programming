#include <stdio.h>
#include <string.h>

int check_scramble_key(int keys[]); 

int main(void) {
    char str[20];
    int strarr[20];
    int inputs[10] = {0};
    scanf("%s", str);
    for(int i=0;i<10;++i) {
        scanf("%d", &inputs[i]);
    }
    if(check_scramble_key(inputs)!=-1) {
        for(int i=0;i<10;++i) {
            inputs[i] = 0;
        }
    }
    
    
    if(str=="0") {
        printf("position codes: 0\n");
        return 0;
    }
    int pointer = 0;
    printf("position codes: ");
    for(int i=0;i<strlen(str);++i) {
        strarr[i] = inputs[str[i]-'0'];
        printf("%d", strarr[i]);
    }


    printf("\n");
    

    return 0;
}

int check_scramble_key(int keys[]) {
    
    int arr[10] = {0};
    for(int i=0;i<10;++i) {
        if(keys[i]<0 || 9<keys[i]) return 1;
        if(arr[keys[i]]) {
            return 1;
        }
        arr[keys[i]]++;
    }
    return -1;
}