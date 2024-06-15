#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,m,tot =0;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    for(int i =0; i<5; i++){
        m = n%10;
        n = n/10;
        tot = tot + m;
    }
    printf("%d",tot);
    return 0;
}