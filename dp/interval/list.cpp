/*
[PROBLEM]
设有 N 堆石子排成一排，其编号为 1,2,3,…,N
每堆石子有一定的质量，可以用一个整数来描述，现在要将这 N 堆石子合并成为一堆
每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同。
例如有 4 堆石子分别为 1 3 5 2， 我们可以先合并 1、2 堆，代价为 4，得到 4 5 2， 
又合并 1、2 堆，代价为 9，得到 9 2 ，再合并得到 11，总代价为 4+9+11=24
问题是：找出一种合理的方法，使总的代价最小，输出最小代价。


第一行一个数 N表示石子的堆数 N
第二行 N个数，表示每堆石子的质量(均不超过 1000)。
输出一个整数，表示最小代价。
[INPUT]
4
1 3 5 2
[OUTPUT]
22
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;
int f[N][N];
int a[N], s[N];
int n;

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    memset(f, 0x3f, sizeof f);

    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (len == 1) {
                f[i][j] = 0;
                continue;
            }

            for (int k = i; k <= j - 1; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    cout << f[1][n] << endl;

    return 0;
}