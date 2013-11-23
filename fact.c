#include <stdio.h>
int Faktoriyel(int x)
{
int f = 1;
while (x != 1)
f = f * x--;
return f;
}
void Fakt_Test(int x, int f_x)
{
int tmp1 = x;
int tmp2 = f_x;
if (x == 0 && f_x == 1)
printf("\n0 ! == 1 ifadesi gecerlidir.\n");
else
{
while (x != 1)
f_x = f_x / x--;
if (f_x == 1)
printf("\n%d ! == %d ifadesi gecerlidir.\n", tmp1, tmp2);
else
printf("\n%d ! == %d ifadesi gecerli degildir.\n", tmp1, tmp2);
}
}
int main(void)
{
int sayi = 5;
printf("%d sayisinin faktoriyeli : %d\n", sayi, Faktoriyel(sayi));
getchar();
}
