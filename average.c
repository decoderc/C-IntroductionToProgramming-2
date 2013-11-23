#include <stdio.h>
#include <conio.h>

int main()
{
    int sayici=0,dersnotu,toplam=0;
    float ortalama;
    
    printf("notu gir:(cikis icin -1 gir)");
    scanf("%d",&dersnotu);
    
    while(dersnotu!=-1)
    {
                       toplam=toplam+dersnotu;
                       sayici=sayici+1;
                       printf("notu gir.(cikis icin -1 gir)");
                       scanf("%d",&dersnotu);
                       }
                       if (sayici!=0){
                       ortalama=(float)toplam/sayici;
                       printf("sinifin ders ortalamasi:%.3f",ortalama);
                       }
                       else
                       printf("hic not girilmemis.");
                       
    
  
                       getch();	
                       return 0;
}
