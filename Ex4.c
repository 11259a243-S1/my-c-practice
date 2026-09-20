#include <stdio.h>
#include <ctype.h>
int main () {
char exp[100];
int stack[50];
int top = -1;
int num = 0, is_buildingn = 0;
printf ("enter postfix expression:\n");
//Read the line including spaces
scanf("%[^\n]",exp);
for (int i = 0; exp[i] !='\0'; i++) {
char ch = exp[i];
  // 4.If operan (digit), accumalate number
if (isdigit(ch)){
num = num* 10 +(ch -'0');
is building = 1;
}
  // 5. If space or  newline , accumulate number
else if (ch == '+' || ch == '_' || ch == '/')}
if (is_building){
stack[++top] = num;
num = 0;
is_building = 0;
}
}
//6. If operator,pop two operands and compute
else if(ch== '+'|| ch == '-'||ch == '*'||ch == '/') {
//Push any pending number before operating
if(is_building) {
stack[++top] = num;
num = 0;
is_building = 0;
}
int op2 = stack [top--];
int op1 = stack [top--];

switch (ch) {
case '+': stack[++top] = op1 + op2; break;
case '-': stack[++top] = op1 - op2; break;
case '*': stack[++top] = op1 * op2; break;
case '/': stack[++top] = op1 / op2; break;
}
}
}
//8.Result is the remaining value on the stack
printf("%d\n",stack[top]);
return 0;
}
