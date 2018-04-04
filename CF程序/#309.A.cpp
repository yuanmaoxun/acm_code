#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
    int i,j,k,m,n;
    char a[25];
    int len,sum;
    while(gets(a)){
        len = strlen(a);
        sum = 26 + len*25;
        cout << sum << endl;
    }
return 0;
}
