#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct box3
{
    int* ptr;
    int length;
    char* name;
}Box3;

Box3* create_box3(char* text){
    Box3* ptrBox = malloc(sizeof(Box3));

    ptrBox->length=0;
    ptrBox->name=text;
    ptrBox->ptr=NULL;

    return ptrBox;
}

Box3* create_box3_with_element(char* text, int value){
    Box3* ptrBox=malloc(sizeof(Box3));

    ptrBox->ptr=malloc(1*sizeof(int));
    *(ptrBox->ptr+0)=value;
    ptrBox->ptr[0] = value;

    ptrBox->length=1;
    ptrBox->name=text;

    return ptrBox;
}

void display_box3(Box3* box){
    printf("Pudelko %s ma: \n", box->name);
    if(box->length==0){
        printf("Pudelko jest puste! \n");
    }else{
        for(int i=0; i<box->length; i++){
            printf("%d ", *(box->ptr+i));
        }
    }
    
    printf("\n");
}

void append(Box3* box, int value){
    int* temporary = malloc((box->length+1)*sizeof(int));

    for(int i=0; i<box->length; i++){
        temporary[i]=box->ptr[i];
    }
    temporary[box->length]=value;
    free(box->ptr);

    box->ptr=temporary;
    box->length++;
}

void end_append(Box3* box, int value){
    box->length++;
    box->ptr = realloc(box->ptr, (box->length)*sizeof(int));

    *(box->ptr + box->length-1) = value;
}

void add_n_numbers(Box3* box, int n){
    (box->length)+=n;
    box->ptr = realloc(box->ptr, (box->length)*sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n; i++){
        int random=rand()%n+1;
        //printf("%d", random);
        *(box->ptr + box->length-n+i) = random;
    }

}

void erase_numbers(Box3* box){
    for(int i=0; i<box->length; i++){
        box->ptr[i]=0;
    }
    box->length=0;
}

void sort_box(Box3* box){
    for(int i=0; i<box->length; i++){
        for(int j=0; j<box->length; j++){
            if(box->ptr[i]<box->ptr[j]){
                int temp=box->ptr[i];
                box->ptr[i]=box->ptr[j];
                box->ptr[j]=temp;
            }
        }
    }
}


int main()
{
    Box3* b = create_box3("pudelko nr 1");
    printf("%s \n", b->name);

    Box3* b2=create_box3_with_element("pudelko nr2", 1);
    printf("%s \n", b2->name);

    append(b2, 3);
    append(b2, 4);

    display_box3(b);
    display_box3(b2);

    end_append(b2, 8);
    display_box3(b2);

    add_n_numbers(b2, 5);
    display_box3(b2);

    erase_numbers(b2);
    display_box3(b2);

    Box3* b3=create_box3_with_element("pudelko nr3", 1);
    add_n_numbers(b3, 10);
    display_box3(b3);

    sort_box(b3);
    display_box3(b3);


    return 0;
}
