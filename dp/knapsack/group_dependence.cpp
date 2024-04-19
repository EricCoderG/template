/*
[PROBLEM]
输入文件的第1行，为两个正整数，用一个空格隔开：N m，其中N表示总钱数，m为希望购买物品的个数。
从第2行到第m+1行，第j行给出了编号为j-1的物品的基本数据，每行有3个非负整数v p q，
其中v表示该物品的价格，p表示该物品的重要度（1~5），q表示该物品是主件还是附件。
如果q=0，表示该物品为主件，如果q>0，表示该物品为附件，q是所属主件的编号。
输出文件只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<200000）。
[INPUT]
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
[OUTPUT]
2200
*/

#include <iostream>
#include <vector>

#define v first
#define w second

using namespace std;

typedef pair<int, int> pii;

const int N = 60, M = 32001; 

pii master[N];
vector<pii> servent[N];
int f[M];

int main() {

    int n, m;
    cin >> m >> n;

    for (int i = 1; i <= n; ++i) {
        int v, p, q; 
        cin >> v >> p >> q;
        p *= v; 
        if (!q) master[i] = pii(v, p); 
        else servent[q].emplace_back(v, p); 
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < 1 << servent[i].size(); k++) {
                int v = master[i].v, w = master[i].w;
                for (int u = 0; u < servent[i].size(); u++) {
                    if (k >> u & 1) {
                        v += servent[i][u].v;
                        w += servent[i][u].w;
                    }
                }
                if (j >= v) {
                    f[j] = max(f[j], f[j - v] + w);
                }
            }
        }
    }  

    cout << f[m] << endl;
    
    return 0;
}

