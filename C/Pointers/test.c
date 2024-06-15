#include<stdio.h>
int main()
{
    int a = 1025;
    int *p = &a;
    printf("Address = %d, value = %d \n",p,*p);
    printf("Address = %d, value = %d \n",p+1,*(p+1));

    char *p0;
    p0 = (char*)p;
    printf("Address = %d, value = %d \n",p0,*p0);
    printf("Address = %d, value = %d \n",p0+1,*(p0+1));
    return 0;
}
