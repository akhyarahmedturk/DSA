#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<ctype.h>

int main(){

    char input[1001];
    char ch = 'A';
    int i = 0;
    while (isalnum(ch)){
        scanf("%c", &ch);
        input[i++] = ch;
    }
    input[i] = '\0';

    int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
    i = 0;
    for (i = 0; i < strlen(input); i++){
        if (input[i] >= '0' && input[i] <= '9'){
            arr[input[i] - '0']++;
        }
    }

    for (i = 0;i < 10;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}