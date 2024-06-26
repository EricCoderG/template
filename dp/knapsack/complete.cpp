/*
[PROBLEM]
有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。
第 i 种物品的体积是 vi ，价值是 wi 。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

第一行两个整数，N，V ，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行两个整数 vi , wi ，用空格隔开，分别表示第 i 种物品的体积和价值。
输出一个整数，表示最大价值。
[INPUT]
4 5
1 2
2 4
3 4
4 5
[OUTPUT]
10
*/

#include <iostream>

using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N];

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = v[i]; j <= m; ++j) {
            f[j] = max(f[j - v[i]] + w[i], f[j]);
        }
    }

    cout << f[m] << endl;

    return 0;
}