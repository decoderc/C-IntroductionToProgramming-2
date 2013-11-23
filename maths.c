#include <stdio.h>
#include <math.h>
#include <conio.h>
void main()
{
     float x,y;
     printf("x=");
     scanf("%f",&x);
     if(x>0)
            y=sqrt((3*(pow(x,2)))+(4*x));
     else
            y=4*(tan(x));
     printf("y=%f\n",y);
     
getch();
return 0;
}


