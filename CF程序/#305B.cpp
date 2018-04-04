#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
    int row[500];
    int a[500][500];
    while(~scanf("%d%d%d",&n,m,&q)){
        for(i=0;i<n;i++){
                num=0;
            for(j=0;j<m;j++)
             {scanf("%d",&a[i][j]);
               if(a[i][j]==1)
                  num++;
             }
        row[i]=num;
   }
   for(k=0;k<q;k++){
        scanf("%d%d",&i,&j);
        if(a[i][j]==0)
            row[i]++;
        }
}
