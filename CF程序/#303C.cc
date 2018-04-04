#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int m,i,j,t,n;
    long long a[100005];
    long long k,sum;
    while(cin >> n){
        for(i=0;i<n;i++)
            cin >> a[i];
        sort (a,a+n);
        sum = a[0];k=1;
        for(i = 1;i<n;i++){
             if(a[i]>=sum){
                k++;
            sum+=a[i];
            }
        }
        cout << k << endl;
    }
return 0;
}
