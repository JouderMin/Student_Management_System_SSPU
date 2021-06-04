//
// Created by 祖安 on 2021/5/29.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_SSPU_DATASORT_H
#define STUDENT_MANAGEMENT_SYSTEM_SSPU_DATASORT_H

#include "StudentData.h"
#include <vector>

using std::vector;

vector<StudentData> sort_by_sum();
vector<StudentData> sort_by_num();
vector<StudentData> sort_by_class();
vector<StudentData> sort_by_course_result_1();
vector<StudentData> sort_by_course_result_2();
vector<StudentData> sort_by_course_result_3();

#endif // STUDENT_MANAGEMENT_SYSTEM_SSPU_DATASORT_H
