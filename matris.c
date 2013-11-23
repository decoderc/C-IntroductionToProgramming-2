#include <stdio.h>  
#include <conio.h> 

main()      
{

    int a[3][2],b[2][3],c[3][3] = { 0 },i,j,k; 

    printf ("Birinci Matris: n");     

    for (i = 0; i < 3; i++) {         
    for (j = 0; j < 2; j++) {         

        printf (" [%d,%d]: ",i+1,j+1);      
        scanf ("%d", &a[i][j]);             
    }
    }

    printf ("Ikinci Matris: n");       

    for (j = 0; j < 2; j++) {          
    for (k = 0; k < 3; k++) {          

        printf (" [%d,%d]: ",j+1,k+1);      
        scanf ("%d", &b[j][k]);             
    }
    }

    for (i = 0; i < 3; i++) {          
    for (j = 0; j < 3; j++) {          
    for (k = 0; k < 2; k++)            

        c[i][j] += a[i][k] * b[k][j];          
    }
        printf("n");
    }

    printf ("Sonuc:n");          

    for (i = 0; i < 3; i++) {    
    for (k = 0; k < 3; k++)      

        printf ("t%d",c[i][k]);      
        printf ("n");                
    }
    
    getch();                      
    return 0;                     
}
