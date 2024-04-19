/*
[TAG]
有 N 种物品和一个容量是 V 的背包。
第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi 。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。输出最大价值。

第一行两个整数，N，V ，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
输出一个整数，表示最大价值。
[INPUT]
4 5
1 2 3
2 4 1
3 4 3
4 5 2
[OUTPUT]
10
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 2010;
typedef pair<int, int> pii;
int f[N];

int main() {

    int n, m;
    cin >> n >> m;
    vector<pii> vv;

    for (int i = 1; i <= n; ++i) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2) {
            s -= k;
            vv.emplace_back(k * w, k * v);
        }
        if (s) vv.emplace_back(s * w, s * v);
    }

    for (pii p : vv) {
        for (int j = m; j >= p.second; j--) {
            f[j] = max(f[j], f[j - p.second] + p.first);
        }
    }

    cout << f[m] << endl;

    return 0;
}