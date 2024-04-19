/*
[PROBLEM]
有 N 种物品和一个容量是 V 的背包。
物品一共有三类：
第一类物品只能用1次（01背包）；
第二类物品可以用无限次（完全背包）；
第三类物品最多只能用 si 次（多重背包）；
每种体积是 vi ，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。输出最大价值。


第一行两个整数，N，V ，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
si=−1 表示第 i 种物品只能用1次；
si=0 表示第 i 种物品可以用无限次；
si>0 表示第 i 种物品可以使用 si 次；
输出一个整数，表示最大价值。
[INPUT]
4 5
1 2 -1
2 4 1
3 4 0
4 5 2
[OUTPUT]
8
*/

#include <iostream>

using namespace std;

const int N = 100005;
int f[N], w[N], v[N];

int main() {

    int n, m;
    cin >> n >> m;

    int cnt = 1;

    for (int i = 1; i <= n; ++i) {
        int a, b, s;
        cin >> a >> b >> s;
        if (s < 0) s = 1;
        else if (s == 0) s = m / b;

        int k = 1;
        while (k <= s) {
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
            ++cnt;
        }

        if (s > 0) {
            v[cnt] = a * s;
            w[cnt] = b * s;
            ++cnt;
        }
        
    }

    for (int i = 1; i <= cnt; ++i) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;

    return 0;
}