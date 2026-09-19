#include <stdio.h>
int main() {
    int a[50],n,i,pos,v;
    //Read size and elements 
    scanf("%d",&n);
    for(i=0;i<n;i++);
    scanf("%d",&a[i]);
//Traverse
i=0;
while (i<n) 
printf("%d",a[i++]);
printf("\n");
//Insert
scanf("%d %d",&v,&pos);
for(i=n-1;i>= pos;i--)a[i+1]=a[i];
a[pos]=v;
n++;
//Display
i=0;
while(i<n)
printf("%d",a[i++]);
}
printf("\n");
{
//Delete
i=0;
while(i<n)
printf("%d",a[i++]);
return 0;
}