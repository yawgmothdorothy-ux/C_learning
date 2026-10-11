#include <stdio.h>

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        return 0;
    }

    // C 没有内置 queue 容器，用数组实现容量为 n 的循环队列。
    int queue[n];
    for (int i = 0; i < n; i++) {
        queue[i] = i + 1;
    }

    int head = 0; // 队头下标：下一次出队的位置。
    int tail = 0; // 下一次入队的位置；初始装满 n 人，已绕回 0。
    int size = n; // 当前人数；head == tail 时靠 size 区分满与空。

    while (size > 0) {
        // 前 m-1 人报数后回到队尾，第 m 人出队且不再入队。
        // 转完整一圈后队列顺序不变，故可省去整圈。
        int rotations = (m - 1) % size;
        for (int i = 0; i < rotations; i++) {
            int person = queue[head];
            head = (head + 1) % n; // 先出队，腾出一个位置。
            size--;

            queue[tail] = person;  // 再把同一个人放回队尾。
            tail = (tail + 1) % n;
            size++; // 一出一入，人数不变。
        }

        int eliminated = queue[head];
        head = (head + 1) % n;
        size--; // 被淘汰者不再入队，人数真正减少。
        printf("%d%c", eliminated, size == 0 ? '\n' : ' ');
        // 新队头自然成为下一轮起点，不需要另设报数计数器。
    }

    return 0;
}
