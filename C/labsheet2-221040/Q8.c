#include<stdio.h>
int main(){
    float base = 3.2;
    float height = 10.1;
    float pi = 3.14;
    float volume = pi*base*base*height;
    float surface = 2*pi*base*height;
    printf("volume: %f\n",volume);
    printf("surface area: %f\n",surface);

    return 0;
}