#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX 100

void end_append(int* tab, int* length, int value){
    if(*length<SIZE_MAX){
        tab[*length]=value;
        (*length)++;
    }
}

void print_box(int* tab, int length){
    if(length<=0){
        printf("Pudelko jest puste!");
    }

    for(int i=0; i<length; i++){
        printf("%d ", *(tab + i));
    }
    printf("\n");
}

void add_n_values(int* tab, int* length, int n){
    for(int i=1; i<=n; i++){
        *(tab + *length) = i;
        (*length)++;
    }
}

void erase_numbers(int* tab, int* length){
    for(int i=0; i<*length; i++){
        *(tab+i)=0;
    }
    (*length)=0;
}

int max_value(int* tab, int* length){
    int max_value=0;
    for(int i=0; i<*length; i++){
        if(*(tab+i)>max_value){
            max_value=*(tab+i);
        }
    }

    return max_value;
}

int sum_of_numbers(int* tab, int* length){
    int sum=0;
    for(int i=0; i<*length; i++){
        sum+=*(tab+i);
    }

    return sum;
}

void erase_value(int* tab, int* length, int value){
    int position=0;
    int if_found=0;
    for(int i=0; i<*length; i++){
        if(*(tab+i)==value){
            *(tab+i)=0;
            position=i;
            if_found=1;
            break;
        }
    }



    if(if_found==1){
        for(int i=position; i<*length; i++){
            *(tab+i)=*(tab+1+i);
        }
        (*length)--;
    }else{
        printf("Nie ma takiego elementu w tablicy \n");
    }
}

int main()
{
    int tab[SIZE_MAX]={0};
    int length=0;

    end_append(tab, &length, 3);
    end_append(tab, &length, 4);
    end_append(tab, &length, 5);

    print_box(tab, length);

    add_n_values(tab, &length, 4);
    print_box(tab, length);

    //erase_numbers(tab, &length);
    //print_box(tab, length);

    printf("%d \n", max_value(tab, &length));
    printf("%d \n", sum_of_numbers(tab, &length));
    erase_value(tab, &length, 5);
    print_box(tab, length);


    return 0;
}
