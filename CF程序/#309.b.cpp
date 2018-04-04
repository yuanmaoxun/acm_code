#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
    int i,j,k,m,n,Max;
    string a[105];
    string temp;
    while(~scanf("%d",&n)) {
        for(i=0;i<n;i++)
           cin >> a[i];
        Max = 0;
        for(i=0;i<n;i++) {
            temp = a[i];k=0;
            for(j = 0;j < n;j++ )
                if(temp == a[j])
                    k++;
            if(k>Max) {
                Max = k;
            }
        }
        cout << Max <<endl;
    }
return 0;
}

