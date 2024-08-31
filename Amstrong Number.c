#include<stdio.h>
#include<math.h>
void main()
{
  int n,originalnum,rem,res=0,digits=0;
  printf("Enter a number\n");
  scanf("%d",&n);  
  originalnum=n;
  while(originalnum!=0)
  {
    originalnum/=10;
    digits++;
    printf("iterations:%d,digits counted for:%d\n",digits,digits);
  }
  originalnum=n;
  while(originalnum!=0)
    {
      rem=originalnum%10;
      res+=pow(rem,digits);
      originalnum/=10;
    }
  if(res==n)
    printf("%d is an armstrong number\n",n);
  else
    printf("%d is not an armstrong number\n",n);
}
