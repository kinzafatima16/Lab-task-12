#include<stdio.h>
#include<stdlib.h>
typedef struct{
char title[50],id[20];
int checkoutTime,dueDays,dueDate;
}B;
int main(){
int n,i,t;
printf("records:");
scanf("%d",&n);
B*a=(B*)malloc(n*sizeof(B));
for(i=0;i<n;i++){
scanf("%s%s%d%d",a[i].title,a[i].id,&a[i].checkoutTime,&a[i].dueDays);
a[i].dueDate=a[i].checkoutTime+a[i].dueDays;
}
printf("add:");
scanf("%d",&t);
a=realloc(a,(n+t)*sizeof(B));
for(i=n;i<n+t;i++){
scanf("%s%s%d%d",a[i].title,a[i].id,&a[i].checkoutTime,&a[i].dueDays);
a[i].dueDate=a[i].checkoutTime+a[i].dueDays;
}
FILE*fp=fopen("checkout.csv","a");
for(i=0;i<n+t;i++){
fprintf(fp,"%s,%s,%d,%d,%d\n",a[i].title,a[i].id,a[i].checkoutTime,a[i].dueDays,a[i].dueDate);
}
fclose(fp);
free(a);
}

