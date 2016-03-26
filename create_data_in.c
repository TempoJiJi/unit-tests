#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    FILE *fp = fopen("data-merge.in","w");
    int n,i,j;
    srand((unsigned)time(NULL));
    fprintf(fp,"\n");
    /*
     *	Considered about the time of excute, generate 100 data only
     */
    for(i=0; i<100; i++) {
        n = (rand() / (i+1)) % 50 + 1;
        fprintf(fp,"%d\n",n);
        for(j=0; j<n; j++) {
            int value = rand() % 1000 + 1;
            fprintf(fp,"%d ",value);
        }
        if(i==99)
            fprintf(fp,"\n");
        else
            fprintf(fp,"\n\n");
    }
    fclose(fp);
}

