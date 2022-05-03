#include <stdlib.h>
#include <stdio.h>

int string2int(char* str){
    int result=0;

    for(int i=0; str[i]!='\0'; i++){
        result = result*10 + str[i] - '0';
    }

    return result;
}

int main(){
    char str[]="45672";

    int stringtoint = string2int(str);
    printf("%d", stringtoint);
    return 0;
}