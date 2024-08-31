#include<stdio.h>
int main(){
  int a,b;
  char oper;
  printf("enter the value of a and b");
  scanf("%d%d",&a,&b);
  printf("enter the operator (+,-,*,/)");
  scanf(" %c",&oper);
  switch(oper){
    case '+':
    printf("the sum of a and b is %d",a+b);
    break;
    case '-':
    printf("the difference of a and b is %d",a-b);
    break;
    case '*':
    printf("the product of a and b is %d",a*b);
    break;
    case '/':
    printf("the division of a and b is %d",a/b);
    break;
    default:
    printf("invalid operator");  
  }

}
