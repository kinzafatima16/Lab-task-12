#include<stdio.h>
#include<stdlib.h>
int main(){
int n,i,t,c=0;
float *a,hi=-999,lo=999,th;
printf("readings:");
scanf("%d",&n);
a=(float*)malloc(n*sizeof(float));
for(i=0;i<n;i++)scanf("%f",a+i);
printf("add:");
scanf("%d",&t);
a=realloc(a,(n+t)*sizeof(float));
for(i=n;i<n+t;i++)scanf("%f",a+i);
printf("threshold:");
scanf("%f",&th);
for(i=0;i<n+t;i++){
if(*(a+i)>hi)hi=*(a+i);
if(*(a+i)<lo)lo=*(a+i);
if(*(a+i)>th)c++;
}
FILE*fp=fopen("temperature_summary.txt","w");
fprintf(fp,"high=%.2f\nlow=%.2f\nalert=%d\n",hi,lo,c);
fclose(fp);
free(a);
}

