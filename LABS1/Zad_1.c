#include <stdio.h>
#include <stdlib.h>

int add_one(int a, int x){
    return a+x;
}

void add_one_pointer(int *a, int x){
    *a += x;
}

int main() {
    int zmienna;
    int *wskaznik;
    zmienna=15;
    wskaznik=&zmienna;

    printf("Wartosc zmiennej: %d\n", zmienna);
    printf("Adres zmiennej: %p\n", &zmienna);
    printf("Wskaznik: %d\n", wskaznik);
    printf("Wartosc wskaznika: %d\n", *wskaznik);
    printf("adres wskaznika: %d\n", &wskaznik);

    zmienna = zmienna + 2;
    printf("Wartosc zmiennej: %d\n", zmienna);
    printf("Adres zmiennej: %p\n", &zmienna);
    printf("Wskaznik: %d\n", wskaznik);
    printf("Wartosc wskaznika: %d\n", *wskaznik);
    printf("adres wskaznika: %d\n", &wskaznik);

    *wskaznik=*wskaznik+4;
    printf("Wartosc zmiennej: %d\n", zmienna);
    printf("Adres zmiennej: %p\n", &zmienna);
    printf("Wskaznik: %d\n", wskaznik);
    printf("Wartosc wskaznika: %d\n", *wskaznik);
    printf("adres wskaznika: %d\n", &wskaznik);

    zmienna = add_one(zmienna, 5);
    printf("Wartosc zmiennej: %d\n", zmienna);
    printf("Adres zmiennej: %p\n", &zmienna);
    printf("Wskaznik: %d\n", wskaznik);
    printf("Wartosc wskaznika: %d\n", *wskaznik);
    printf("adres wskaznika: %d\n", &wskaznik);

    add_one_pointer(&zmienna, 100);
    printf("Wartosc zmiennej: %d\n", zmienna);
    printf("Adres zmiennej: %p\n", &zmienna);
    printf("Wskaznik: %d\n", wskaznik);
    printf("Wartosc wskaznika: %d\n", *wskaznik);
    printf("adres wskaznika: %d\n", &wskaznik);



   return 0;
}