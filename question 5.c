#include<stdio.h>
#include<stdlib.h>
int main(){
int n,i,t;
float *a,sum=0,max=0,cost;
printf("rentals:");
scanf("%d",&n);
a=(float*)malloc(n*sizeof(float));
for(i=0;i<n;i++)scanf("%f",a+i);
printf("add:");
scanf("%d",&t);
a=realloc(a,(n+t)*sizeof(float));
for(i=n;i<n+t;i++)scanf("%f",a+i);
for(i=0;i<n+t;i++){
sum+=*(a+i);
if(*(a+i)>max)max=*(a+i);
}
FILE*fp=fopen("Rental_Invoices.txt","w");
for(i=0;i<n+t;i++){
cost=*(a+i)*100;
fprintf(fp,"%d %.2f %.2f\n",i+1,*(a+i),cost);
}
fprintf(fp,"total=%.2f\nmax=%.2f\n",sum,max);
fclose(fp);
free(a);
}

