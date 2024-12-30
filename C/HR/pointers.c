#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    //*b = *a - *b;
    int c =*a;
    int d =*b;
    if(*a>*b){
        *b = *a - *b;
        *a = c + d;
    }
    else{
        *b = *b - *a;
        *a = c + d;
    }

}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}