# 基础练习

| 目录 | 文件与内容 |
| --- | --- |
| Billing_阶梯电价 | [electricity_calculator.c](Billing_阶梯电价/electricity_calculator.c)：按电表起止读数计算阶梯费用 |
| SpecialNumbers_特殊数字 | [nine_nine_graph.c](SpecialNumbers_特殊数字/nine_nine_graph.c)：判断能否被 62 整除或是否含相邻数位“62” |
| SpecialNumbers_特殊数字 | [rate.c](SpecialNumbers_特殊数字/rate.c)：在区间内寻找第 k 个 63 的倍数、完全平方数和各位相同的数 |

每个 `.c` 文件都是独立程序。`nine_nine_graph.c` 沿用原文件名，实际内容是数位判断；`rate.c` 从原 Alice_and_bob 目录按内容归入本目录。

进入源文件所在目录后编译，例如：

```bash
gcc -std=c11 -Wall -Wextra rate.c -o rate -lm
./rate
```
