#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int i,j,k,m,n,t,len;
    char a[100005],b[100005],c[100005];
    while(gets(a)){
        gets(b);
        k=0;
        t=1;
        len = strlen(a);
        for(i=0;i<len;i++)
            if(a[i]!=b[i])
                k++;
        if(k%2==1)
            printf("impossible\n");
        else{
            for(i=0;i<len;i++){
                if(a[i]!=b[i]&&t==1)
                {c[i]=a[i]; t=0; }
                else if(a[i]!=b[i]&&t==0)
                { c[i] = b[i];
                   t=1;
                }
                else {c[i] = a[i];

                }
                }c[len] = '\0';
            puts(c);
            }
            }
return 0;
}
