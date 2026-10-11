#include <stdio.h>

// 一个节点代表一个人：保存编号和“下一位仍在场的人”的地址。
typedef struct Node {
    int id;
    struct Node *next;
} Node;

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        return 0;
    }

    // 用 C99 变长数组一次准备所有节点，重点练习链接与删除。
    // 节点存在数组里，但遍历顺序由 next 决定，是循环链表。
    // 没有调用 malloc，因此不需要 free；出圈只是从链上摘掉。
    Node nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i].id = i + 1;
        nodes[i].next = &nodes[(i + 1) % n];
    }

    Node *current = &nodes[0];    // 本轮从此人开始，他报 1。
    Node *previous = &nodes[n - 1]; // current 的前驱，方便删除。
    int remaining = n;

    while (remaining > 0) {
        // 起点已算第 1 人，只需前进 m-1 次。
        // 完整一圈不改变位置，所以取模跳过整圈。
        int steps = (m - 1) % remaining;
        for (int i = 0; i < steps; i++) {
            previous = current;
            current = current->next;
        }

        printf("%d%c", current->id, remaining == 1 ? '\n' : ' ');
        remaining--;
        if (remaining == 0) {
            break; // 最后一人也输出，随后结束，不再维护空环。
        }

        // previous -> current -> 下一人
        // 改为 previous ----------> 下一人，淘汰者不再被访问。
        previous->next = current->next;
        current = previous->next; // 下一人重新报 1，前驱保持不动。
    }

    return 0;
}
