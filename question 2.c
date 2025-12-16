#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
char name[50],roll[20];
int seat;
}S;
int chk(char*s,int i){
if(s[i]=='\0')return 1;
if((s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))return chk(s,i+1);
return 0;
}
int main(){
int n,i,t;
printf("students:");
scanf("%d",&n);
S*o=(S*)malloc(n*sizeof(S));
for(i=0;i<n;i++){
scanf("%s%s%d",o[i].name,o[i].roll,&o[i].seat);
while(!chk(o[i].roll,0))scanf("%s",o[i].roll);
}
printf("add:");
scanf("%d",&t);
o=realloc(o,(n+t)*sizeof(S));
for(i=n;i<n+t;i++){
scanf("%s%s%d",o[i].name,o[i].roll,&o[i].seat);
while(!chk(o[i].roll,0))scanf("%s",o[i].roll);
}
FILE*fp=fopen("seating.txt","w");
for(i=0;i<n+t;i++){
fprintf(fp,"%s %s %d\n",o[i].name,o[i].roll,o[i].seat);
}
fclose(fp);
free(o);
}

