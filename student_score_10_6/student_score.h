#ifndef STUDENT_SCORE_H
#define STUDENT_SCORE_H

typedef struct {
    int id;
    int chinese;
    int math;
    int english;
    int total;
} StudentScore;

typedef struct {
    double average_total;
    int top_id;
    int all_passed_count;
} StudentStatistics;

int calculate_total(StudentScore *student,int *total_scores_one_student,double *average_one_student);

#endif
