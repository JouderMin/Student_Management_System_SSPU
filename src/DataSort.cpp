//
// Created by 祖安 on 2021/5/29.
//

#include "DataSort.h"
#include "FileOperation.h"
#include <algorithm>

using std::sort;
using std::vector;

int sum(StudentData a) {
    return a.result_course_1 + a.result_course_2 + a.result_course_3;
}

bool sort_by_sum_core(const StudentData & a, const StudentData & b) {
    return sum(a) > sum(b);
}

vector<StudentData> sort_by_sum() {
    auto * file = new FileOperation;
    vector<StudentData> data;
    file->allLog(data);
    delete file;
    sort(data.begin(), data.begin() + (signed)data.size(), sort_by_sum_core);

    return data;
}
