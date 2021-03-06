#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, M = 30010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int res;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
    dfn[u] = low[u] = ++timestamp;

    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) cnt++;
        } else low[u] = min(low[u], dfn[v]);
    }

    if (u != from) cnt++; 

    res = max(res, cnt);
}

int main() {
    while (scanf("%d%d", &n, &m), n || m) {
        memset(dfn, 0, sizeof dfn);
        memset(h, -1, sizeof h);
        idx = timestamp = 0;

        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }
        
        res = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (!dfn[i]) {
                cnt++;
                tarjan(i, i);
            }
        
        printf("%d\n", res + cnt - 1);
    }

    return 0;
}