#include<stdio.h>
#include<string.h>
struct myStructure{
    int age;
    char letter;
    char name[10];
};
int main(){
struct myStructure s1 = {22,'A',"rashmika"};
struct myStructure s2;
s2=s1;
s2.age = 23;
s2.letter = 'B';
strcpy(s2.name,"Dilmith");

printf("%d\n%c\n%s\n\n",s1.age,s1.letter,s1.name);
printf("%d\n%c\n%s\n",s2.age,s2.letter,s2.name);
return 0;
}