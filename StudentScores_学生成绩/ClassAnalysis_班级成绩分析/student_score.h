/*
 * 班级成绩分析器共享的数据类型和函数声明。
 * include guard 可避免同一头文件被重复包含。
 */
#ifndef STUDENT_SCORE_H
#define STUDENT_SCORE_H

/* 保存一位学生的身份、三科成绩及计算得到的总分。 */
typedef struct {
    int id;
    int chinese;
    int math;
    int english;
    int total;
} StudentScore;

/* 保存全班平均总分、最高分学生学号和全部科目及格人数。 */
typedef struct {
    double average_total;
    int top_id;
    int all_passed_count;
} StudentStatistics;

/* 计算学生总分与平均分；成功返回总分，参数无效时返回 -1。 */
int calculate_total(StudentScore *student,int *total_scores_one_student,double *average_one_student);

#endif
