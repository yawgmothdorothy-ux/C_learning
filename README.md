# C_learning · C 语言学习记录

按练习内容、题目来源和项目版本整理。普通目录统一采用 `English_中文` 命名；源码保留原文件名，方便对照题号和学习过程。

## 目录导航

| 分类 | 内容 |
| --- | --- |
| [Basics_基础练习](Basics_基础练习/README.md) | 阶梯电价、数位判断、特殊数字筛选 |
| [DynamicProgramming_动态规划](DynamicProgramming_动态规划/README.md) | 最大子段和的单文件与多文件版本、未完成的 DP 草稿 |
| [StudentScores_学生成绩](StudentScores_学生成绩/README.md) | 单文件成绩统计、班级成绩分析项目 |
| [PTA_习题集](PTA_习题集/README.md) | 按循环、条件、字符、数组、模拟、枚举和贪心分类的 26 个练习 |
| [Luogu_洛谷练习](Luogu_洛谷练习/README.md) | 归并排序、数字三角形、数组倒序、约瑟夫问题及图解笔记 |

```text
C_learning/
├── Basics_基础练习/
│   ├── Billing_阶梯电价/
│   └── SpecialNumbers_特殊数字/
├── DynamicProgramming_动态规划/
│   ├── Drafts_未完成练习/
│   └── MaxSubarray_最大子段和/
│       ├── SingleFile_单文件实现/
│       └── MultiFile_多文件实现/
├── StudentScores_学生成绩/
│   ├── SingleFile_单文件统计/
│   └── ClassAnalysis_班级成绩分析/
├── PTA_习题集/
│   ├── Loops_循环与数学/
│   ├── Conditions_条件判断/
│   ├── Characters_字符统计/
│   ├── Arrays_数组与统计/
│   ├── Simulation_过程模拟/
│   ├── Enumeration_枚举求解/
│   └── Greedy_贪心算法/
└── Luogu_洛谷练习/
    ├── Arrays_数组练习/
    ├── DynamicProgramming_动态规划/
    ├── Josephus_约瑟夫问题/
    └── MergeSort_归并排序/
        └── Figures_图解资料/
```

## 存放与运行约定

- 根目录保留 README 和必要配置。新练习放入相应主题目录；题号文件保留在对应平台分类下。
- 同一题的实现、参考版本和笔记放在一起；多文件项目保持独立，避免混入其他带 `main()` 的程序。
- 未完成的动态规划代码放在 `Drafts_未完成练习`，保留原始学习过程。目前所有文件都能确定用途，无需杂项目录。
- `.git`、`.vscode` 是 Git 和 VS Code 使用的固定目录名，不改名；`.gitignore` 是必要配置。
- 编译得到的可执行文件保留在本地、由 `.gitignore` 排除，GitHub 展示源码与学习资料。
- 单文件练习可用 VS Code 的“运行当前 C 文件”；多文件项目使用对应的专用任务或项目 README 中的编译命令。

## 原始学习记录

第一次在github上提交代码，现代程序猿在互联网共享这一块还是太全面了，开源万岁，提交了一个示例，包含我的一个阶梯电价计费程序的c语言代码，剩下的之后再看值不值得提交

提交了一个通过分文件的方式动态分配内存的一维dp算法，以及配套的详细readme,最近又学多元函数，又搞多文件程序，在这样下去我也要分裂出多重人格了

## 2026-10-07：PTA 练习记录

今天整理了 23 个 C 语言练习，从循环求和、字符统计、条件判断，到有界枚举和过程模拟。详细题目索引、调试记录及运行方法见 [PTA 练习 README](PTA_习题集/README.md)。

接下来的目标是减少同类输入输出题的重复练习，把时间更多放在算法思路、边界分析和优化上。

## 2026-10-10：归并排序、三角形 DP 与约瑟夫问题

今天用归并排序解决冒泡排序超时，整理了带程序流程图的图解笔记；数字三角形 DP 统一了从 1 开始的下标，并修正初始化和边界。约瑟夫问题经过多次死循环排查后通过提交，重点理解了位置移动、有效报数、淘汰和剩余人数各自的更新时机。

详细记录见 [今日学习索引](Luogu_洛谷练习/README.md) 和 [约瑟夫错题笔记](Luogu_洛谷练习/Josephus_约瑟夫问题/README.md)。
