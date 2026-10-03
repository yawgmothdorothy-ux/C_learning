# 动态数组最大连续子数组和

这是一个 C 语言练习项目：从标准输入读取整数数组，使用动态内存保存数据，再通过动态规划求出非空连续子数组的最大和。项目重点是练习多文件编程、函数接口、指针、动态内存和 DP 状态。

## 项目文件

```text
week01_max_subarray/
├── main.c              # 输入、分配输入数组、调用算法、输出并释放数组
├── memory.h            # 动态数组分配函数的声明
├── memory.c            # 动态数组分配函数的实现
├── Max_subarray.h      # 最大连续子数组函数的声明
└── Max_subarray.c      # 最大连续子数组算法的实现
```

## 算法思路

令 `dp[i]` 表示：**必须以 `arr[i]` 结尾的非空连续子数组中，元素和的最大值。**

到达 `i` 时有两种选择：从 `arr[i]` 重新开始，或接上以 `arr[i - 1]` 结尾的最佳连续段：

```text
dp[0] = arr[0]
dp[i] = max(arr[i], dp[i - 1] + arr[i])
```

算法另外维护 `themax`，记录已经计算过的所有 `dp[i]` 中的最大值。`dp[i]` 是“以 i 结尾”的最优值；`themax` 才是整个数组中的答案。这样全负数数组也会返回其中最大的负数，而不会错误地返回 0。

例如输入数组 `[2, 4, -9, 4]`，状态依次为 `[2, 6, -3, 4]`，最大连续子数组和为 `6`。

## 多文件调用关系

C 的多文件调用分成三个部分：

1. **头文件声明接口**：`memory.h` 声明 `create_int_array`，`Max_subarray.h` 声明 `max_subarray`。声明写清返回类型、函数名和参数类型。
2. **源文件实现函数**：`memory.c` 和 `Max_subarray.c` 分别提供对应函数的函数体。定义的名字和参数类型必须与声明相匹配。
3. **调用并链接**：`main.c` 包含相应头文件并调用函数；编译时把所有参与实现的 `.c` 文件一起交给 GCC，链接器才能把调用与实现连起来。

头文件是接口说明，不会自动把对应 `.c` 文件编译进去。不要在 `.c` 文件中 `#include` 另一个 `.c` 文件。

## 动态内存的分工

- `main` 调用 `create_int_array(count)` 分配输入数组 `arr`，填入数据后传给算法，最后由 `main` 调用 `free(arr)`。
- `max_subarray` 只读取 `arr`。它自己分配临时 DP 数组 `dp`，完成计算后调用 `free(dp)`。
- `malloc` 分配失败会返回 `NULL`，使用指针前必须检查；每块成功分配的内存应由负责它的代码释放一次。
- `const int *arr` 表示算法通过 `arr` 读取数据，不修改数组。因此输入应在 `main` 中写入，算法函数不应对 `arr[i]` 调用 `scanf`。

## 今天排查的问题

### 1. 把 `count` 读了两次

最初在 `main` 中先调用了一次 `scanf`，随后又在输入校验的 `if` 条件中调用 `scanf`。第二次读取会把数组的第一个元素当作新的 `count`，从而改变数组长度并使后续输入错位。

修复方法：把读取和校验合并成唯一一次调用：

```c
if (scanf("%d", &count) != 1 || count < 1 || count > 10000) {
    printf("数量输入错误\n");
    return 1;
}
```

### 2. 在只读数组上读取输入

算法接口使用 `const int *arr`，但曾试图在算法函数内部通过 `scanf` 写入 `arr[i]`。`const` 表示算法不应修改这块数组。

修复方法：由 `main` 负责读入数组元素，再把数组传给算法；算法只计算并返回结果。

### 3. 混淆函数返回状态和计算结果

`max_subarray` 用返回值表示计算是否成功：成功返回 `1`，失败返回 `0`；最大和通过 `long long *out_sum` 写回给调用者。调用方应先检查状态，再使用 `out_sum`。

### 4. 多文件构建只编译了当前文件

VS Code 原来的任务参数使用 `${file}`，这只会编译当前打开的 `.c` 文件。其他文件中的函数实现没有参与链接，会出现 `undefined reference` 一类错误。

在项目目录可以用下面的命令编译：

```bash
gcc -Wall -Wextra -g main.c memory.c Max_subarray.c -o program
```

运行：

```bash
./program
```

如果使用 VS Code 的 `tasks.json`，应在 `args` 中列出 `main.c`、`memory.c` 和 `Max_subarray.c`。`.h` 文件通过 `#include` 使用，不需要作为独立编译单元添加到命令中。

## 测试用例

| 输入 | 预期输出 | 检查内容 |
|---|---:|---|
| `4`，数组 `2 4 -9 4` | `6` | 选择一段连续元素，而非只看末尾状态 |
| `3`，数组 `-8 -3 -6` | `-3` | 全负数时仍选择非空子数组 |
| `1`，数组 `7` | `7` | 单元素边界 |
| `9`，数组 `-2 1 -3 4 -1 2 1 -5 4` | `6` | 综合 DP 测试 |
| 数量 `0` 或大于 `10000` | 输入错误 | 数量边界 |

建议进一步检查每次读取数组元素的 `scanf` 返回值。若输入的元素个数不足，程序应报错并释放 `arr`，不能继续使用未读入的数组元素。项目当前 DP 使用 `int`，因此也应遵守练习范围：元素值在 `[-100000, 100000]`，数量不超过 `10000`。

## 更新 GitHub 上的文件

在本地仓库根目录执行：

```bash
git status
git add week01_max_subarray/README.md week01_max_subarray/main.c week01_max_subarray/Max_subarray.c week01_max_subarray/Max_subarray.h week01_max_subarray/memory.c week01_max_subarray/memory.h
git diff --cached
git commit -m "Update max subarray project"
git push origin main
```

`git add` 把本地修改放入暂存区，`git diff --cached` 查看将要提交的内容，`git commit` 在本地记录修改，`git push` 上传到 GitHub。若推送提示远端有本地尚未包含的提交，先执行 `git pull --rebase origin main`，再重新推送。

不要把编译生成的 `program` 或其他可执行文件加入提交；它们可以通过 `.gitignore` 排除。
