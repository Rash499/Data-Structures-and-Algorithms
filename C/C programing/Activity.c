#include<stdio.h>
int main(){
 printf("Enter the size of the array: ");
 int n;
 scanf("%d",&n);

 printf("Enter numbers: \n");
 int num[n];
 for(int i =0; i<n; i++){
    
    scanf("%d",&num[i]);
    
 } 
 printf("Display numbers \n");
 for(int j=0; j<n; j++){
    printf("%d\n",num[j]);
 } 
 return 0; 
}