#include <iostream>
using namespace std;

const int N = 1010, M = 510, K = 110;
int n, m, k;
// v1是消耗精灵球数量，v2是消耗皮卡丘的体力
int v1[K], v2[K];
int f[2][N][M];

int main() {
    // n是精灵球数量，m是皮卡丘体力值，k是野生小精灵数量
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) scanf("%d%d", &v1[i], &v2[i]);

    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= n; j++)
            for (int l = 0; l < m; l++) {
                f[i & 1][j][l] = f[i - 1 & 1][j][l];
                if (j >= v1[i] && l >= v2[i])
                    f[i & 1][j][l] = max(f[i & 1][j][l], f[i - 1 & 1][j - v1[i]][l - v2[i]] + 1);
            }
    
    int t = m - 1;
    while (t > 0 && f[k & 1][n][t - 1] == f[k & 1][n][m - 1]) t--;

    printf("%d %d\n", f[k & 1][n][m - 1], m - t);

    return 0;
}