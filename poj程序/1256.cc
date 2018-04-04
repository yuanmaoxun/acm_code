#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;

bool cmp(char a,char b) {
    if(a >= 'a' && a <='z' && b >= 'a' && b <= 'z') {
        return a < b;
    }
    if(a >= 'A' && a <='Z' && b >= 'A' && b <= 'Z') {
        return a < b;
    }
    if(a >= 'a' && a <='z' && b >= 'A' && b <= 'Z') {
        return a < (b+32);
    }
    if(a >= 'A' && a <='Z' && b >= 'a' && b <= 'z') {
        return (a+32) <= b;
    }
}


int main() {
    int T;
    char str[15];
#ifndef ONLINE_JUDGE
freopen("F://input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(~scanf("%d",&T)) {
        while(T--) {
            scanf("%s",str);
            int len = strlen(str);
            sort(str,str+len,cmp);
            cout << str << endl;
            while(next_permutation(str,str+len,cmp)) {
                cout << str <<endl;
            }
        }
    }

return 0;
}
