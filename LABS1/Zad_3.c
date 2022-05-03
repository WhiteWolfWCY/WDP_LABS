#include <stdio.h>
#include <stdlib.h>

void T3_increase_val(int *a){
    *a=(*a)*2;
}

int T4_return_address(int *a, int*b){
    if(*a>*b){
        return a;
    }else if(*b>*a){
        return b;
    }

}

int T5_return_ptr_val(int *a, int *b, int *c){
    if(a<b && a<c){
        return *a;
    }else if(b<a && b<c){
        return *b;
    }else{
        return *c;
    }
}

void T6_value_swap(int *a, int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

void T7_ptr_swap(int **a, int **b){
    int temp=*a;
    *a = *b;
    *b=temp;
}

void T8_numbers_compare(int *a, int *b){
    if(*a<*b){
        *a = *a + *b;
    }else{
        *b = *a + *b;
    }
}

int *T9_new_tab(int *tab, int length){
    int *Btab = (int *) malloc(length * sizeof(int));
    int i=0;
    int k=0;
    if(length>0){
        while(i<length){
            if((*(tab+i))%2==0){
                *(Btab+k) = *(tab+i);
                printf("%d ", *(Btab+k));
                k++;
            }
            i++;
        }
    }

    return Btab;
}


int main(){
    int liczba1=5;
    int liczba2=17;
    int liczba3=41;
    int* pointer = &liczba1;

    T3_increase_val(pointer);
    printf("%d \n", *pointer);
    //printf("adres l1: %d \n", &liczba1);
    //printf("adres l2: %d \n", &liczba2);
    //printf("adres l3: %d \n", &liczba3);

    printf("%d \n", T4_return_address(&liczba1, &liczba2));
    printf("%d \n", T5_return_ptr_val(&liczba1, &liczba2, &liczba3));

    T6_value_swap(&liczba1, &liczba3);
    printf("l1: %d, l3: %d \n", liczba1, liczba3);

    int *aptr;
    int *bptr;
    aptr=&liczba1;
    bptr=&liczba3;

    int **ppatr;
    int **ppbtr;
    ppatr=&aptr;
    ppbtr=&bptr;

    printf("l1: %d, l3: %d\n", &liczba1, &liczba3);
    T7_ptr_swap(ppatr, ppbtr);
    printf("l1: %d, l3: %d\n", aptr, bptr);

    T8_numbers_compare(&liczba1, &liczba3);
    printf("l1: %d, l3: %d \n", liczba1, liczba3);
    printf("\n");

    int tab1[]={1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(tab1)/sizeof(int);

    int *ptr;
    ptr=T9_new_tab(tab1, length);
    for(int i=0; i<length/2; i++){
        printf(" %d : %d ", i, *(ptr+i));
    }

    free(ptr);
    free(aptr);
    free(bptr);
    free(ppatr);
    free(ppbtr);
    
    
    return 0;
}