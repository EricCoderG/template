/*
[PROBLEM]
小明想要处理一批图片，将相似的图片分类。他首先对图片的特征采样，得到图片之间的相似度，然后按照以下规则判断图片是否可以归为一类:
1)相似度>0表示两张图片相似，
2)如果A和B相似，B和C相似，但A和C不相似。那么认为A和C间接相似，可以把ABC归为一类，但不计算AC的相似度
3)如果A和所有其他图片都不相似，则A自己归为一类，相似度为0.给定一个大小为NxN的矩阵M存储任意两张图片的相似度，
M[i][j]即为第i个图片和第j个图片的相似度，请按照"从大到小”的顺序返回每个相似类中所有图片的相似度之和。

第一行一个数N，代表矩阵M中有N个图片，下面跟着N行，每行有N列数据，空格分隔 代表N个图片之间的相似度。
每个相似类的相似度之和。格式为:一行数字，分隔符为1个空格。
[INPUT]
5
0 0 50 0 0
0 0 0 25 0
50 0 0 0 15
0 25 0 0 0
0 0 15 0 0
[OUTPUT]
65 25
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 910;
int a[N][N];
int n, m;
int p[N];
int num[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[i][j] > 0) {
                int px = find(i), py = find(j);
                if (px != py) {
                    p[px] = py;
                    num[py] += a[i][j] + num[px];
                } else {
                    num[py] += a[i][j];
                }
            }
        }
    }

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (p[i] == i) {
            res.push_back(num[i]);
        }
    }
    sort(res.begin(), res.end());
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }

    return 0;
}