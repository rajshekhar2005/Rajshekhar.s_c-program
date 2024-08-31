#include<stdio.h>
void main(){
  int n,factorial=1;
  printf("enter the positve number");
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    {
      factorial=factorial*i;
    }
  printf("%d",factorial);

}
