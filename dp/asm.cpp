/*
[PROBLEM]
阿福是一名经验丰富的大盗。趁着月黑风高，阿福打算今晚洗劫一条街上的店铺。
这条街上一共有 N 家店铺，每家店中都有一些现金。阿福事先调查得知，只有当他同时洗劫了两家相邻的店铺时，街上的报警系统才会启动。

输入的第一行是一个整数 T (T≤50)，表示一共有T组数据。
接下来的每组数据，第一行是一个整数 N (1≤N≤100,000)，表示一共有N家店铺。
第二行是 N 个被空格分开的正整数，表示每一家店铺中的现金数量。每家店铺中的现金数量均不超过1000。
[INPUT]
2
3
1 8 2
4
10 7 6 14
[OUTPUT]
8
24
*/

#include <iostream>

using namespace std;

const int N = 100005, INF = 0x3f3f3f3f;

int w[N], f[N][2];

void solve() {
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];

    for (int i = 1; i <= n; ++i) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + w[i];
    }

    cout << max(f[n][0], f[n][1]) << endl;
}

int main() {

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}