/*
[PROBLEM]
给定一棵树，树中包含 n 个结点（编号1~n）和 n−1 条无向边，每条边都有一个权值。
现在请你找到树中的一条最长路径。
换句话说，要找到一条路径，使得使得路径两端的点的距离最远。
注意：路径中可以只包含一个点。

第一行包含整数 n。
接下来 n−1 行，每行包含三个整数 ai,bi,ci，表示点 ai 和 bi之间存在一条权值为 ci 的边。
输出一个整数，表示树的最长路径的长度。
[INPUT]
6
5 1 6
1 4 5
6 3 9
2 6 8
6 1 7
[OUTPUT]
22
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e4 + 10, M = N << 1;

int n;
int h[N], e[M], w[M], ne[M], idx;
int f1[N], f2[N], res;

void add(int a, int b, int c) {
    e[idx] = b; // 存储每条边的终点
    w[idx] = c; // 存储每条边的权值
    ne[idx] = h[a]; // 存储每个节点的前一条邻接边的索引
    h[a] = idx++; // 存储每个节点的邻接边的最新一条边的索引
}

void dfs(int u, int father) {
    f1[u] = f2[u] = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfs(j, u);
        if (f1[j] + w[i] >= f1[u]) {
            f2[u] = f1[u];
            f1[u] = f1[j] + w[i];
        }
        else if (f1[j] + w[i] > f2[u]) {
            f2[u] = f1[j] + w[i];
        }
        res = max(res, f1[u] + f2[u]);
    }
}

void solve() {

    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1);  //任意选取一个点作为根，这样整棵树的拓扑结构被唯一确定
    cout << res << endl;

}

int main() {

    solve();

    return 0;
}