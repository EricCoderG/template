/*
[PROBLEM]
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi ，价值是 wi 。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

第一行两个整数，N，V ，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi ，用空格隔开，分别表示第 i 件物品的体积和价值。
输出最大价值。
[INPUT]
4 5
1 2
2 4
3 4
4 5
[OUTPUT]
8
*/

#include <iostream>

using namespace std;

const int N = 1010;
int f[N];

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            f[j] = max(f[j - v] + w, f[j]);
        }
    }
    cout << f[m] << endl;

    return 0;
}