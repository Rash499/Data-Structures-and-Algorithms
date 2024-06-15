#include<stdio.h>
int main(){
    char C = 'B';
    int i=3,j=3,k=3;
    double x = 0.0,y =2.3;

    printf((i&&j&&k) ? "true\n":"false\n");
    printf((x || i && j-3) ? "true\n":"false\n");
    printf((i<j && x<y) ? "true\n":"false\n");
    printf((i<j || x<y) ? "true\n":"false\n");
    printf(('A' <= C && C <= 'Z') ? "true\n":"false\n");
    printf((C-1=='A' || C+1 == 'Z') ? "true\n":"false\n");

    return 0;
}