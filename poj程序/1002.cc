#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;


int main(){
    map<string,int> Num;
    map<string,int>::iterator iter;
    int T;
    char str[305];
    char str1[10];

#ifndef ONLINE_JUDGE
    freopen("F://input.txt","r",stdin);
#endif
    while(~scanf("%d",&T)) {
        Num.clear();
        while(T--) {
            int k = 0;
            scanf("%s",str);
            int len = strlen(str);
            for(int i = 0; i < len; i++) {
                if(k == 3){
                    str1[k] = '-';
                    k++;
                    i--;
                    continue;
                }
                if(str[i] >='A' && str[i] <= 'Z' ) {
                    switch(str[i]) {
                        case 'A':
                        case 'B':
                        case 'C': str1[k++] = '2';break;
                        case 'D':
                        case 'E':
                        case 'F': str1[k++] = '3';break;
                        case 'G':
                        case 'H':
                        case 'I': str1[k++] = '4';break;
                        case 'J':
                        case 'K':
                        case 'L': str1[k++] = '5';break;
                        case 'M':
                        case 'N':
                        case 'O': str1[k++] = '6';break;
                        case 'P':
                        case 'R':
                        case 'S': str1[k++] = '7';break;
                        case 'T':
                        case 'U':
                        case 'V': str1[k++] = '8';break;
                        case 'W':
                        case 'X':
                        case 'Y': str1[k++] = '9';break;
                        default : continue;
                    }
                }
                else if(str[i] >='0' && str[i] <= '9')
                    str1[k++] = str[i];
                else
                    continue;
            }
            str1[k] = '\0';
            //cout <<"str1"<<str1 <<endl;
            Num[str1]++;
        }
        int flag = 0;
        for(iter = Num.begin();iter != Num.end();iter++) {
            if(iter->second > 1){
                cout << iter->first ;
                printf(" %d\n",iter->second);
                flag = 1;
            }
        }
        if(flag == 0)
            cout <<"No duplicates."<<endl;
    }
return 0;
}
