#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_tab(int tab[], int length){
    if(length>0){
        for(int i=0; i<length; i++){
            printf("[%d] = %d ", i, tab[i]);
        }
        printf("\n");
    }
    
}

void print_tab_using_pointer(int tab[], int length){
    if(length>0){
        for(int i=0; i<length; i++){
            printf("[%d] = %d ", i, *(tab+i));
        }
        printf("\n");
    }
    
}

void increase_nopointers(int tab[], int length){
    if(length>0){
        tab[0]+=10;
        tab[length-1]+=10;
    }
}

void increase_pointers(int tab[], int length){
    if(length>0){
        *tab+=100;
        *(tab+length-1)+=100;
    }
}

int* create_tab_with_malloc(int length){
    int *pointer = (int *) malloc(length * sizeof(int));
    return pointer;
}

int* create_tab_with_calloc(int length){
    int *pointer = (int*)calloc(length, sizeof(int));
    return pointer;
}

void fill_tab_with_val(int *tab, int length, int value){
    if(length>0){
        for(int i=0; i<length; i++){
            *(tab+i)=value;
        }
    }
}

void fill_tab_with_random(int *tab, int length, int range){
    if(length>0){
        srand(time(NULL));
        for(int i=0; i<length; i++){
            *(tab+i)=rand() % range;
        }
    }
}

int main(){
    int tab[]={0,1,2,3,4,5,6,7,8,9};
    int *pointer = tab;

    int length = sizeof(tab)/sizeof(int);

    print_tab(tab, length);
    print_tab_using_pointer(tab, length);

    increase_nopointers(tab, length);
    print_tab(tab, length);

    increase_pointers(tab, length);
    print_tab(tab, length);

    int length2=5;

    int *tab2 = create_tab_with_malloc(length2);
    print_tab_using_pointer(tab2, length2);

    int *tab3 = create_tab_with_calloc(length2);
    print_tab_using_pointer(tab3, length2);

    fill_tab_with_val(tab2, length2, 3);
    print_tab_using_pointer(tab2, length2);

    fill_tab_with_random(tab3, length2, 100);
    print_tab_using_pointer(tab3, length2);

    free(tab);
    free(tab2);
    free(tab3);

    return 0;
}