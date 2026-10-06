#include "student_score.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int total_scores = 0;

    int highest_score = -1;

    int student_count;

    int one_student_id;

    int found = 0;

    if (scanf("%d", &student_count) != 1 ||
    student_count < 1 || student_count > 100) {
    printf("学生人数输入错误\n");
    return 1;
    }

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

    StudentStatistics statistics = {0};

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

        total_scores_one_student[i] = calculate_total(&students[i], &total_scores_one_student[i], (double *)&average_one_student[i]);

        if(total_scores_one_student[i] > highest_score){
            highest_score = total_scores_one_student[i];
            statistics.top_id = students[i].id;
        }

        if (students[i].chinese >= 60 && students[i].math >= 60 && students[i].english >= 60) {
            // Student passed all subjects
            statistics.all_passed_count++;
        }

        printf("学生ID: %d, 总分: %d, 平均分: %.2f\n", students[i].id, total_scores_one_student[i], (double)average_one_student[i]);

        total_scores += total_scores_one_student[i];

    }

    statistics.average_total = (double)total_scores / student_count+0.0;

    if (scanf("%d", &one_student_id) != 1) {
    printf("查询学号输入错误\n");
    free(students);
    free(average_one_student);
    free(total_scores_one_student);
    return 1;
    }

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

    printf("平均总分: %.2f\n", statistics.average_total);
    printf("最高分学生ID: %d, 总分: %d\n", statistics.top_id, highest_score);
    printf("所有科目及格人数: %d\n", statistics.all_passed_count);

    free(students);
    free(average_one_student);
    free(total_scores_one_student);
    return 0;
}
