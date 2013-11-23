#include <stdio.h>
#include <conio.h>

int main()
{
int a[3][5],sinif,ogrenci;
float toplam=0;
for(sinif=0;sinif<3;sinif++)
{
printf("%d. sinif\n",sinif+1);
for(ogrenci=0;ogrenci<5;ogrenci++){
printf("%d. ogrencinin notunu giriniz:",ogrenci+1);
scanf("%d",&a[sinif][ogrenci]);
}
}
for(sinif=0;sinif<3;sinif++)
{
printf("\n%d. sinif notlari=\n",sinif+1);
for(ogrenci=0;ogrenci<5;ogrenci++){
printf("%d",a[sinif][ogrenci]);
toplam=toplam+a[sinif][ogrenci];
}
printf("\n");
printf("%d. sinifin ortalamasi:%.2f",sinif+1,toplam/5);
toplam=0;
}
  
  getch();	
  return 0;
}
