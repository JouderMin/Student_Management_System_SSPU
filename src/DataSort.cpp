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

bool sort_by_num_core(const StudentData & a, const StudentData & b) {
    return a.number < b.number;
}

bool sort_by_class_core(const StudentData & a, const StudentData & b) {
    return a.classCode < b.classCode;
}

bool sort_by_course_result_1_core(const StudentData & a, const StudentData & b) {
    return a.result_course_1 > b.result_course_1;
}

bool sort_by_course_result_2_core(const StudentData & a, const StudentData & b) {
    return a.result_course_2 > b.result_course_2;
}

bool sort_by_course_result_3_core(const StudentData & a, const StudentData & b) {
    return a.result_course_3 > b.result_course_3;
}

vector<StudentData> sort_by_sum() {
    auto * file = new FileOperation;
    vector<StudentData> data;
    file->allLog(data);
    delete file;
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_num_core);
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_sum_core);

    return data;
}

vector<StudentData> sort_by_num() {
    auto * file = new FileOperation;
    vector<StudentData> data;
    file->allLog(data);
    delete file;
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_num_core);
    return data;
}

vector<StudentData> sort_by_class() {
    auto * file = new FileOperation;
    vector<StudentData> data;
    file->allLog(data);
    delete file;
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_num_core);
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_class_core);
    return data;
}

vector<StudentData> sort_by_course_result_1() {
    auto * file = new FileOperation;
    vector<StudentData> data;
    file->allLog(data);
    delete file;
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_num_core);
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_course_result_1_core);
    return data;
}

vector<StudentData> sort_by_course_result_2() {
    auto * file = new FileOperation;
    vector<StudentData> data;
    file->allLog(data);
    delete file;
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_num_core);
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_course_result_2_core);
    return data;
}

vector<StudentData> sort_by_course_result_3() {
    auto * file = new FileOperation;
    vector<StudentData> data;
    file->allLog(data);
    delete file;
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_num_core);
    stable_sort(data.begin(), data.begin() + (signed)data.size(), sort_by_course_result_3_core);
    return data;
}
