#include "student_score.h"
#include <stdio.h>
#include <stdlib.h>

int calculate_total(StudentScore *student, int *total_scores_one_student, double *average_one_student) {
    if (student == NULL || total_scores_one_student == NULL || average_one_student == NULL) {
        return -1; // Error: Null pointer
    }
    student->total = student->chinese + student->math + student->english;
    *total_scores_one_student = student->total;
    *average_one_student = (double)student->total / 3.0;
    return student->total;
}
