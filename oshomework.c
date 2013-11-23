#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

/* Mutex ve cond değişkenleri */
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_cond  = PTHREAD_COND_INITIALIZER;

pthread_mutex_t creating_theads_mutex = PTHREAD_MUTEX_INITIALIZER;
int creating_theads = 0;

int *sharedMatrisA;
int *sharedMatrisB;
int *sharedMatrisC;
int m;
int n;
int k;

void *matrisHesapla(int satirno) {

    printf("Thread #%d init.\n",satirno+1);
    fflush(stdout);

    /* Hala thread yaratma asamasindaysak bekle. */
    if(creating_theads > 0) {
        printf("Thread #%d digerlerinin yaratilmasini beklemek uzere kitlenecek.\n",satirno+1);
        fflush(stdout);
        /* Yaratılınca bir bekle önce. */
        pthread_mutex_lock( &condition_mutex );
        printf("Thread #%d mutex locked.\n",satirno+1);
        fflush(stdout);
        pthread_cond_wait( &condition_cond, &condition_mutex );
        printf("Thread #%d cond wait ended.\n",satirno+1);
        fflush(stdout);
        pthread_mutex_unlock( &condition_mutex );

        printf("Thread #%d calismaya devam ediyor.\n",satirno+1);
        fflush(stdout);
    } else {
        pthread_mutex_unlock(&creating_theads_mutex);
        printf("Thread #%d beklemeye fırsat bulamadan tüm threadler yaratılmış.\n",satirno+1);
        fflush(stdout);
    }

    printf("Thread #%d hesaplamaya basladi.\n",satirno+1);
    int ic1,ic2;
    for(ic1=0; ic1<k; ic1++) {
        for(ic2=0; ic2<n; ic2++)  {
            /* Her thread kendi satırına yazdıgı için problem olmaz, mutexe gerek yok. */
            sharedMatrisC[(satirno*k) + ic1] += sharedMatrisA[(satirno*n) + ic2] * sharedMatrisB[(ic2*k)+ic1];
        }
    }
    printf("Thread #%d hesaplamayi bitirdi ve sonlandi.\n",satirno+1);
 }

int main() {

    /* Acilis yazilari BASLANGICI */
    printf("TURKIYE\n");
    printf("31-03-2012\n");
    printf("Bugun gunlerden cumartesi\n");
    printf("http://gist.github.com\n");
    printf("Threads\n\n");
    /* Acilis yazilari SONU */

    FILE *fp;
    if((fp=fopen("input.txt","r")) == NULL) {
        printf ("Dosya acilamadi.");
        exit(-1);
    }

    fscanf(fp,"%d %d %d",&m, &n, &k);

    int matrisA[m][n];
    int matrisB[n][k];
    int matrisC[m][k];
    sharedMatrisA = &matrisA;
    sharedMatrisB = &matrisB;
    sharedMatrisC = &matrisC;

    int i;
    int j;

    for(i=0;i<m;i++) {
         for(j=0;j<k;j++) {
            matrisC[i][j] = 0;
        }
    }

    /* A MATRISINI OKU */
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            fscanf(fp,"%d",&matrisA[i][j]);
        }
    }

    /* B MATRISINI OKU */
    for(i=0;i<n;i++) {
        for(j=0;j<k;j++) {
            fscanf(fp,"%d",&matrisB[i][j]);
        }
    }

    fclose(fp);

    /* EKRANA MATRISLERI YAZDIR */
    printf("Matris A:\n");
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            printf("%d\t", matrisA[i][j]);
        }
        printf("\n");
    }

    printf("\nMatris B:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<k;j++) {
            printf("%d\t", matrisB[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    pthread_t threads[m];
    fflush(stdout);


    creating_theads = 1;
    printf("Threadler yaratılıyor...\n");
    fflush(stdout);
    for(i=0;i<m;i++) {
        printf("Thread #%d/%d yaratıldı.\n",i+1,m);
        fflush(stdout);
        pthread_create(&threads[i], NULL, &matrisHesapla, i);
    }

    pthread_mutex_lock(&creating_theads_mutex);
    creating_theads = 0;
    pthread_mutex_unlock(&creating_theads_mutex);

    printf("Thread yaratimi tamamlamdi. Simdi beklemelerin bitmesi icin mesaj gonderilecek.\n");
    fflush(stdout);

    /* Threadler çalışabilirler */
    pthread_mutex_lock( &condition_mutex );
    pthread_cond_broadcast( &condition_cond );
    pthread_mutex_unlock( &condition_mutex );

    printf("Beklemekte olabilecek threadlere isleme baslamasini soyleyen mesaj gonderildi.\n");

    fflush(stdout);
    for(i=0;i<m;i++) {
        printf("Main thread #%d/%d'nin bitmesini bekliyor...\n",i+1,m);
        pthread_join(threads[i],NULL);
    }

    printf("\nMatris C:\n");
    for(i=0;i<m;i++) {
        for(j=0;j<k;j++) {
            printf("%d\t", matrisC[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("...ve bize ayrilan surenin sonuna geldik...\n");
    printf("...bir sonraki odevde gorusmek uzere, esen kalin efendim...\n");
    exit(0);

}
