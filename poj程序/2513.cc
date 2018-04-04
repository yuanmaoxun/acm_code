#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct node
{
    int x;
    node *next[26];
};

int deg[510005], father[510005], cnt, ant;
node *root, memory[5100050];

node *create()
{
    node *p = &memory[ant++];
    int i;
    for(i = 0; i < 26; i++)
    {
        p->next[i] = NULL;
    }
    return p;
};

void insert(char *s, int x)
{
    node *p = root;
    int i, k;
    for(i = 0; s[i]; i++)
    {
        k = s[i] - 'a';
        if(p->next[k] == NULL)
        {
            p->next[k] = create();
        }
        p = p->next[k];
    }
    p->x = x;
}

int search(char *s)
{
    node *p = root;
    int i, k;
    for(i = 0; s[i]; i++)
    {
        k = s[i] - 'a';
        if(p->next[k] == NULL) return 0;
        p = p->next[k];
    }
    return p->x;
}

void init()
{
    int i;
    for(i = 1; i <= 510000; i++)
    {
        father[i] = i;
    }
    memset(deg, 0, sizeof(deg));
    cnt = 0;
}

int find(int x)
{
    if(x != father[x])
    {
        father[x] = find(father[x]);
    }
    return father[x];
}

void Union(int x, int y)
{
    father[x] = y;
}

bool judge()    //ÅÐ¶ÏÊÇ·ñÂú×ãÅ·À­
{
    int i, k, odd = 0;
    for(i = 1; i <= cnt; i++)
    {
        if(deg[i]%2 == 1) odd++;
    }
    if(odd != 0 && odd != 2) return false;
    k = find(1);
    for(i = 2; i <= cnt; i++)
    {
        if(k != find(i)) return false;
    }
    return true;
}

int main()
{
    int x, y, fx, fy;
    char s1[15], s2[15];
    init();
    root = create();
    while(scanf("%s %s", s1, s2) != EOF)
    {
        x = search(s1);     //Ó³ÉäÇó±àºÅËÙ¶ÈÌ«Âý
        y = search(s2);     //ÓÃ×ÖµäÊ÷À´Çó±àºÅ
        if(x == 0) insert(s1, x = ++cnt);
        if(y == 0) insert(s2, y = ++cnt);
        deg[x]++;
        deg[y]++;
        fx = find(x);
        fy = find(y);
        if(fx != fy) Union(fx, fy);
    }
    if(judge()) printf("Possible\n");
    else printf("Impossible\n");

    return 0;
}
