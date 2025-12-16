#include<stdio.h>
#include<stdlib.h>
int tot(int*a,int i,int n){
if(i==n)return 0;
return a[i]+tot(a,i+1,n);
}
int main(){
int n,i,t,*a,max=0,idx=0;
printf("gates:");
scanf("%d",&n);
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)scanf("%d",a+i);
printf("add:");
scanf("%d",&t);
a=realloc(a,(n+t)*sizeof(int));
for(i=n;i<n+t;i++)scanf("%d",a+i);
for(i=0;i<n+t;i++){
if(a[i]>max){
max=a[i];
idx=i;
}
}
FILE*fp=fopen("attendance.txt","w");
fprintf(fp,"total=%d\nmaxgate=%d\n",tot(a,0,n+t),idx);
fclose(fp);
free(a);
}

