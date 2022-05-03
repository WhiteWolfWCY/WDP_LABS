#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_MAX 100

typedef struct box2
{
    int tab[SIZE_MAX];
    int length;
} Box2;

void print_box(Box2 b){
    if(b.length==0){
        printf("Pudelko jest puste!");
    }else{
        for(int i=0; i<b.length; i++){
            printf("%d ", b.tab[i]);
        }
    }
    printf("\n");

}

void end_append(Box2* box, int value){
    if(box->length < SIZE_MAX){
        box->tab[box->length]=value;
        (box->length)++;
    }else{
        printf("Pudelko jest pelne");
    }
}

Box2* create_new_box(){
    Box2* b2 = (Box2*) malloc(sizeof(Box2));
    b2->length=0;

    return b2;
}

void print_box_ptr(Box2* box){
    if(box->length<=0){
        printf("Pudelko jest puste!");
    }else{
        for(int i=0; i<(box->length); i++){
            printf("[%d] - %d, ", i,  box->tab[i]);
        }
    }
    printf("\n");
}

void add_n_values(Box2* box, int n){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        int random = rand()%n;
        box->tab[box->length+i]=random;
    }
    box->length+=n;
}

void erase_box(Box2* box){
    for(int i=0; i<box->length; i++){
        box->tab[i]=0;
    }
    box->length=0;
}

int even_in_box(Box2* box){
    int even=0;
    for(int i=0; i<box->length; i++){
        if((box->tab[i]%2)==0){
            even++;
        }
    }
    return even;
}

float mean_value(Box2* box){
    float srednia=0;
    int sum=0;
    int elements=0;

    for(int i=0; i<box->length; i++){
        sum+=(box->tab[i]);
        elements++;
    }
    //printf("%d ", sum);
    //printf("%d ", elements);
    srednia = (float)sum/(float)elements;
    return srednia;
}

int main()
{
    Box2 b1;
    b1.length=0;
    b1.tab[b1.length]=5;
    b1.length++;

    print_box(b1);

    Box2* ptr_b2 = create_new_box();

    print_box(*ptr_b2);
    end_append(ptr_b2, 7);
    print_box(*ptr_b2);
    end_append(ptr_b2, 8);
    end_append(ptr_b2, 9);
    end_append(ptr_b2, 10);
    print_box_ptr(ptr_b2);
    add_n_values(ptr_b2, 4);
    print_box_ptr(ptr_b2);
    erase_box(ptr_b2);
    print_box_ptr(ptr_b2);
    print_box_ptr(ptr_b2);

    printf("%d", even_in_box(ptr_b2));
    printf("\n");
    printf("%d", mean_value(ptr_b2));

    add_n_values(ptr_b2, 8);
    print_box_ptr(ptr_b2);

    return 0;
}
