#include<stdio.h>
#include<conio.h>
int main()
{
 int a[4][5]={1,2,3,4,5,11,12,13,14,15,21,22,23,24,25,31,32,33,34,35},i,j,sum[4];
 for(i=0; i<4; i++)
{
  sum[i]=0;
 for(j=0; j<5; j++)
 {
  sum[i]+=a[i][j];
 }
}
 for(i=0; i<4; i++)
{
  printf("\n");
 for(j=0; j<5; j++)
 {
  printf("%d",a[i][j]);
 }
}
printf("\n\n");
 for(i=0; i<4; i++)
{
  printf("\n%d",sum[i]);
}
 getche();
 return 0;
}
