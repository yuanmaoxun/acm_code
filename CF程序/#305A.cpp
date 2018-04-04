#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;
string temp,temp1;
char a[1005],b[1005];
char *p,*q;
int main(){
    int i, j, k,l, m,len,n;
    while(gets(a)){
        cin >> k;
        getchar();
        len = strlen(a);
        if(len%k!=0)
            cout << "NO" << endl;
        else {
                n=0;
                l=0;
        while(l<len) {
            for(p=a+l,q=p+len/k-1;p<=q;p++,q--){
                if(*p!=*q)
                    break;
            }
            if(p>=q) n++;
            l+=len/k;
            }
            if(n == k)
                cout << "YES" <<endl;
            else
                cout << "NO" << endl;
             }
    }
return 0;
}
