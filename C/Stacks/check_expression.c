#include <stdio.h>
void push(char);
char pop(void);
void stackPrint(void);
int nextStackPosition(void);
int main()
{
char expr[20];
char sch; /* the stack top value */
int i=0;
int good=1; /* 1 indicates: so far so good */
printf("Enter the expression to check:\n");
scanf("%s", expr);
while (expr[i] != '\0') {
switch (expr[i]) {
case '(': case '[': case '{': /* push onto stack */
push(expr[i]);
/* stackPrint();*/
break;
case ')':
sch = pop();
if (sch != '(') /* imbalance */
good = 0;
break;
case ']':
sch = pop();
if (sch != '[') /* imbalance */
good = 0;
break;
case '}':
sch = pop();
if (sch != '{') /* imbalance */
good = 0;
break;
}
if (!good)
break; /* go out of while loop */
i++;
}
if (good && nextStackPosition()==0)
printf("The input expression is balanced.\n");
else
printf("The input expression is not balanced.\n");
return 0;
}