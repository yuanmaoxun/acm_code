#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i;
    double p,q;
    while(cin>>p>>q){
        p /= 100;
        q /= 100;
        for (i=1; i<=32767; i++) {
            if (ceil(q*i) >= floor(p*i)+2) {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}

