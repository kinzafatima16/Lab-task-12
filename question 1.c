#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,i,t,*a,th,max=0,sum=0,c=0;
    printf("hours: ");
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++){
        scanf("%d",a+i);
    }
    printf("add hours: ");
    scanf("%d",&t);
    a=realloc(a,(n+t)*sizeof(int));
    for(i=n;i<n+t;i++) {
        scanf("%d",a+i);
    }
    printf("threshold: ");
    scanf("%d",&th);
    for(i=0;i<n+t;i++){
        if(*(a+i)>max)max=*(a+i);
        sum+=*(a+i);
        if(*(a+i)>th)c++;
    }
    FILE *fp=fopen("fitness_tracker.txt","w");
    fprintf(fp,"max=%d\ntotal= %d\nabove = %d\n",max,sum,c);
    fclose(fp);
    free(a);
}

