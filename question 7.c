#include<stdio.h>
#include<stdlib.h>
typedef struct{
char name[50];
int qty;
float price;
}M;
int main(){
int n,i,ch;
float val=0;
printf("meds:");
scanf("%d",&n);
M*a=(M*)malloc(n*sizeof(M));
for(i=0;i<n;i++){
scanf("%s%d%f",a[i].name,&a[i].qty,&a[i].price);
}
while(1){
printf("1add 2remove 3exit:");
scanf("%d",&ch);
if(ch==1){
a=realloc(a,(n+1)*sizeof(M));
scanf("%s%d%f",a[n].name,&a[n].qty,&a[n].price);
n++;
}
else if(ch==2&&n>0){
n--;
a=realloc(a,n*sizeof(M));
}
else break;
}
FILE*fp=fopen("medicine_inventory.txt","w");
for(i=0;i<n;i++){
val+=a[i].qty*a[i].price;
fprintf(fp,"%s %d %.2f\n",a[i].name,a[i].qty,a[i].price);
}
fprintf(fp,"value=%.2f\n",val);
fclose(fp);
free(a);
}

