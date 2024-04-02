#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ematriz(int *ptr, int *L, int *C){

    int i, j;

    for(i=0; i<(*L); i++){
        for(j=0; j<(*C); j++){
            printf("%d ", *ptr);
            ptr++;
        }
    }
}

int main(){

    int L=5, C=5, i, j;
    int *ptr;

    srand(time(NULL));

    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            *ptr = rand() % 100;
            ptr++;
        }
    }

    ematriz(ptr, &L, &C);

    return 0;
}