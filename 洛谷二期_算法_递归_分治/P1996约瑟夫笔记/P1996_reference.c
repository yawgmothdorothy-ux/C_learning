#include <stdio.h>

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        return 0;
    }

    int alive[n];
    for (int i = 0; i < n; i++) {
        alive[i] = 1;
    }

    int pos = 0;        // 当前访问的位置，始终在 0..n-1 内。
    int reported = 0;   // 本轮已经报出的数。
    int remaining = n;  // 尚未淘汰的人数。

    while (remaining > 0) {
        if (alive[pos]) {
            // 只有在场的人报数；先报数，再检查是否淘汰。
            reported++;
            if (reported == m) {
                // 先输出当前人的编号，再标记淘汰。
                printf("%d%c", pos + 1, remaining == 1 ? '\n' : ' ');
                alive[pos] = 0;
                remaining--;
                reported = 0;
            }
        }

        // 无论是否在场，每轮都移动一次；绕圈不会重置报数。
        pos = (pos + 1) % n;
    }

    return 0;
}
