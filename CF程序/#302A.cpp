#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define PI  3.1415926535898
#define ll  long long
using namespace std;
int main () {
    int i,j,k,m,n,t;
    int len, res, ans, key, sum;char temp;
    char String[10000],String1[10000];
    int flag[100];
    while(~scanf("%d",&n)){
        getchar();
        gets (String);
        len = strlen(String);
        if(n > len)
            cout << "NO" << endl;
        else {
            strcpy(String1,String);
            sort(String1,String1 + len );
            temp = String1[0];
            k = 1;
            for(i = 0 ; i < len; i++)
                if(temp != String1 [i] ) {
                    k++;
                    temp = String1[i];
                }
            if(k < n )  cout << "NO" << endl;
            else {
                cout << "YES" << endl;
                memset(flag,0,sizeof(flag));
                putchar(String[0]);
                flag[String[0] - 'a' + 1] = 1;
                n--;
                for(i = 1; i < len; i++){
                    if(flag[String[i] - 'a' + 1] == 0 && n != 0) {
                        cout  << endl << String[i] ;
                        n--;
                        flag[String[i] - 'a' + 1] = 1;
                    }
                    else
                         cout << String[i];
                }
                cout << endl;
            }
        }
    }
return 0;
}
