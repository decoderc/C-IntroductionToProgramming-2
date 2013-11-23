#include <stdio.h>
#include <math.h>
#include <conio.h>

void main()
{
     int x,e,t=0;
     float w,y,z=1,m;
     for(x=1;x<=10;x++){
     y=sqrt(x);
     z=z*y;
     }
     for(w=1;w<=8;w++){
     e=pow(w,2);
     t=t+e;
     }
     m=t+z;
     printf("total=%f\n",m);
     
     
  
  getch();	
  return 0;
}

