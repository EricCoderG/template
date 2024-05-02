/*
[PROBLEM]
小美有一棵有 n个节点的树，根节点为1号节点，树的每个节点是红色或者黑色，她想知道有多少节点的子树中同时包含红点和黑点。

第一行输入一个整数 n(1<=n<=10^5)表示节点数量。
第二行输入一个长度为 n 的字符串 s 表示节点的颜色，第i 个节点的颜色为si ，
若 si 为 'B' 表示节点的颜色为黑色，若 si 为 'R' 则表示节点的颜色为红色。
接下来n-1 行，每行输入两个整数 u,v(1<=u,v<=n)表示树上的边。
输出一个整数表示答案。
[INPUT]
3
BRB
1 2
2 3
[OUTPUT]
2
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n, res;
string colors;
vector<vector<int>> graph(N); //防止直接开数组超空间

pii dfs(int u, int f) { // (idx, father)
    pii cur = {0, 0};
    if (colors[u - 1] == 'B') cur.first = 1;
    else cur.second = 1;

    for (auto v : graph[u]) {
        if (v == f) continue;
        pii cur_v = dfs(v, u);
        
        cur.first += cur_v.first;
        cur.second += cur_v.second;
    }

    if (cur.first > 0 && cur.second > 0) {
        ++res;
    }

    return cur;
}

int main() {

    cin >> n >> colors;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1);

    cout << res;
}