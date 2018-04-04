#include <stdio.h>

#define N 50

int main(){
int a[N][N]={0};
int i,j;
int n;
int k;
scanf("%d",&n);
i = 0;
j = n/2;
a[0][j]=1;
for(k = 2; k <= n*n; k++){
if( i == 0 && j == n-1 ){ //先判断前一个数是不是最右上角的数，若是后   一个数直接填在前一个数下方
i=i+1;
a[i][j] = k;
continue;
}
i = (i-1+n)%n; //计算前一个数右上角的坐标
j = (j+1)%n;
if(a[i][j] != 0){ //若前一个数的右上角有元素，后一个   数直接填在前一个数下方
i = ((i+1)%n+1)%n; //恢复坐标
j = (j-1+n)%n;
a[i][j] = k;
}else{ //上述条件均不满足，后一个数放在前一个数的   右上角
a[i][j] = k;
}
}

for(i = 0; i < n; i++){
for(j = 0; j < n; j++){
printf("%d ",a[i][j]);
}
printf("\n");
}
return 0;
}