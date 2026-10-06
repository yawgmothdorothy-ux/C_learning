/*
 * 班级成绩分析程序的入口。
 * 读取学生人数、每位学生的学号和三科成绩，计算个人与班级统计，
 * 最后按学号查询一位学生的信息。
 */
#include "student_score.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    /* 累加所有学生的总分，供计算班级平均总分使用。 */
    int total_scores = 0;

    /* 最高总分从 -1 开始，保证第一个合法学生会成为当前第一名。 */
    int highest_score = -1;

    /* 输入、查询和查找状态。 */
    int student_count;

    int one_student_id;

    int found = 0;

    /* 人数必须成功读入，且限制在本练习支持的范围内。 */
    if (scanf("%d", &student_count) != 1 ||
    student_count < 1 || student_count > 100) {
    printf("学生人数输入错误\n");
    return 1;
    }

    /* 为每位学生分别保存总分、平均分和完整的学生信息。 */
    int *total_scores_one_student = (int *)malloc(student_count * sizeof(int));
    if (total_scores_one_student == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for total_scores_one_student.\n");
        return -1;
    }

    double *average_one_student = (double *)malloc(student_count * sizeof(double));
    if (average_one_student == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for average_one_student.\n");
        free(total_scores_one_student);
        return -1;
    }

    StudentScore *students = (StudentScore *)malloc(student_count * sizeof(StudentScore));
    if (students == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for students.\n");
        free(total_scores_one_student);
        free(average_one_student);
        return -1;
    }

    /* 结构体成员清零，作为班级统计量的初始状态。 */
    StudentStatistics statistics = {0};

    /* 逐个读取学生资料，验证成绩，并更新每位学生和班级的统计结果。 */
    for(int i = 0; i < student_count; i++){
        if (scanf("%d %d %d %d",
          &students[i].id,
          &students[i].chinese,
          &students[i].math,
          &students[i].english) != 4) {
          printf("第 %d 个学生的信息输入不完整或格式错误\n", i + 1);

        free(students);
        free(average_one_student);
        free(total_scores_one_student);
        return 1;
    }

        if (students[i].chinese < 0 || students[i].chinese > 100 ||
            students[i].math < 0 || students[i].math > 100 ||
            students[i].english < 0 || students[i].english > 100) {
            printf("学生成绩输入错误\n");
            free(students);
            free(average_one_student);
            free(total_scores_one_student);
            return 1;
        }

        /* 通过函数计算并写回该学生的总分和平均分。 */
        total_scores_one_student[i] = calculate_total(&students[i], &total_scores_one_student[i], (double *)&average_one_student[i]);

        /* 使用严格大于号；若总分并列，保留先录入的学生。 */
        if(total_scores_one_student[i] > highest_score){
            highest_score = total_scores_one_student[i];
            statistics.top_id = students[i].id;
        }

        /* 三科都达到 60 分才计为全部科目及格。 */
        if (students[i].chinese >= 60 && students[i].math >= 60 && students[i].english >= 60) {
            statistics.all_passed_count++;
        }

        /* 输出当前学生成绩，并累加总分。 */
        printf("学生ID: %d, 总分: %d, 平均分: %.2f\n", students[i].id, total_scores_one_student[i], (double)average_one_student[i]);

        total_scores += total_scores_one_student[i];

    }

    /* 转成 double 后相除，以保留班级平均总分的小数部分。 */
    statistics.average_total = (double)total_scores / student_count+0.0;

    /* 读取待查询学号；输入无效时先释放已申请的全部内存。 */
    if (scanf("%d", &one_student_id) != 1) {
    printf("查询学号输入错误\n");
    free(students);
    free(average_one_student);
    free(total_scores_one_student);
    return 1;
    }

    /* 顺序查找学号，找到后输出资料并停止搜索。 */
    for(int i = 0; i < student_count; i++){
        if(students[i].id == one_student_id){
            printf("被咨询学生ID: %d, 总分: %d, 语文: %d, 数学: %d, 英语: %d, 平均分: %.2f\n", students[i].id, total_scores_one_student[i], students[i].chinese, students[i].math, students[i].english, (double)average_one_student[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("未找到%d号学生\n", one_student_id);
    }

    /* 无论是否找到查询对象，都输出班级整体统计结果。 */
    printf("平均总分: %.2f\n", statistics.average_total);
    printf("最高分学生ID: %d, 总分: %d\n", statistics.top_id, highest_score);
    printf("所有科目及格人数: %d\n", statistics.all_passed_count);

    /* 释放 main 中申请的三块动态内存。 */
    free(students);
    free(average_one_student);
    free(total_scores_one_student);
    return 0;
}
