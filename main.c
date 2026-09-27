#include "hashmap.h"
#include <stdio.h>

int main(int argc, char** argv) {
    HashMap* hm = hashmap_init();
    double d1 = 26.9;
    int i = 288984;
    char* dbl_str = "double";
    char* int_str = "int";

    hashmap_insert(hm, dbl_str, (void*)&d1);
    hashmap_insert(hm, int_str, (void*)&i);

    double retrieved_double = *(double*)hashmap_get(hm, dbl_str);
    int retrieved_int = *(int*)hashmap_get(hm, int_str);

    printf("%s: %f\n%s: %i", dbl_str, retrieved_double, int_str, retrieved_int);

    return 0;
}