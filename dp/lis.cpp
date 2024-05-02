/*
[TAG]
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：
虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。
某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数，导弹数不超过1000），
计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入导弹依次飞来的高度。
第一行：最多能拦截的导弹数；
第二行：要拦截所有导弹最少要配备的系统数。
[INPUT]
389 207 155 300 299 170 158 65
[OUTPUT]
6
2
*/

#include <iostream>

using namespace std;

const int N = 1010;
int h[N], f[N], g[N];

int main() {

    int n = 0, ans = 0;
    while (cin >> h[n]) n++;
    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (h[i] <= h[j])
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;

    int cnt = 0; // 表示当前子序列的个数
    for (int i = 0; i < n; ++i) {
        int k = 0; // 序列下标
        while (k < cnt && g[k] < h[i]) ++k;
        g[k] = h[i];
        if (k >= cnt) ++cnt;
    }

    cout << cnt << endl;

    return 0;
}