/* 单个学生成绩计算函数的实现。 */
#include "student_score.h"
#include <stdio.h>
#include <stdlib.h>

int calculate_total(StudentScore *student, int *total_scores_one_student, double *average_one_student) {
    /* 任一参数为空时无法读取学生成绩或写出结果。 */
    if (student == NULL || total_scores_one_student == NULL || average_one_student == NULL) {
        return -1; // Error: Null pointer
    }

    /* 计算三科总分，并通过输出指针返回总分与平均分。 */
    student->total = student->chinese + student->math + student->english;
    *total_scores_one_student = student->total;
    *average_one_student = (double)student->total / 3.0;
    return student->total;
}
