#include <stdio.h>
#include <stdlib.h>

void remove_spaces(char* str){
    int counter=0;

    for(int i=0; str[i]; i++){
        if(str[i]!=' '){
            str[counter++]=str[i];
        }
    }
    str[counter]='\0';
}

int main(){
    char str[]="te stowe slo wo tego za dani a";
    remove_spaces(str);
    printf("%s", str);
    return 0;
}