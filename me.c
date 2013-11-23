#include <stdio.h>
#include <stdlib.h>
int kare(int);
int main()
{
    int a;
    printf("bir sayi gir:");
    scanf("%d",&a);
    printf("\nGrimis oldugunuz sayinin karesi:%d",kare(a));
    getch();
    return 0;
}
int kare(int y)
{
    int x;
    if (y%2==0)
    x=y*y;
    else
    x=(y+1)*(y+1);
    return x;
}
  
