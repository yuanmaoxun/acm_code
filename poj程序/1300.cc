#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define Maxn 105
using namespace std;

int main() {
    int Edge[Maxn];  //��¼ÿ�����������
    char str[Maxn];
    int m,n;
    int i,j;
    int Count = 0;
    while(gets(str)) {

        if(strcmp(str,"ENDOFINPUT") == 0){
            break;
        }
        sscanf(str,"%*s%d%d",&m,&n);
        Count = 0;
        memset(Edge,0,sizeof(Edge));
        for(int i = 0; i < n; i++) {
            int k = 0;  //��ȡ���ݵ���ʼλ��
            gets(str);
            while(sscanf(str+k,"%d",&j) == 1) {
                Count++;
                Edge[i]++;
                Edge[j]++;
                while(str[k] && str[k]==' ') k++;
                while(str[k] && str[k]!=' ') k++;
            }
        }
        gets(str);
        int Even = 0; int Odd = 0;
        for(i = 0; i < n; i++) {
            if(Edge[i]%2==0){
                Even++;
            }
            else
                Odd++;
        }
        if(m == 0&&Odd == 0){
            printf("YES %d\n",Count);
        }
        else if(Odd == 2 && Edge[0]%2!=0 && Edge[m]%2!=0 && m!=0){
            printf("YES %d\n",Count);
        }
        else
            printf("NO\n");
    }
    return 0;
}

