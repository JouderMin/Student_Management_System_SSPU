//
// Created by zjy on 2021/5/5.
//
#include "io.h"
#include "DataSort.h"
#include "FileOperation.h"
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::printf;

void menu() {
    cout << "程序设计与实践大作业" << endl;
    cout << "学生信息管理系统" << endl;
    cout << "周张珉 钟勇 朱苏雨 张荐阳" << endl;
    cout << "-------------------------" << endl;
    cout << "欢迎使用学生信息管理系统，请输入以下标号以访问对应功能" << endl;
    cout << "1、新建学生信息" << endl;
    cout << "2、修改学生信息" << endl;
    cout << "3、删除学生信息" << endl;
    cout << "4、显示所有学生信息" << endl;
    cout << "5、查询学生信息" << endl;
    cout << "6、显示所有有不及格分数的学生信息" << endl;
    cout << "0、退出程序" << endl;
}

bool numberRepeat(long long number) {
    auto operation = new FileOperation;
    int i          = 0;
    StudentData temp{};

    while (operation->getLog(i, temp)) {
        if (temp.number == number) {
            delete operation;
            return false;
        }
        i++;
    }
    delete operation;
    return true;
}

void displayData(FileOperation & file) {
    vector<StudentData> data;

    file.allLog(data);
    if (data.empty()) {
        cout << "无记录" << endl;
        return;
    }
    printf("序号     学号      名字     班级     科目1 科目2 科目3 总分\n");
    for (int i = 0; i < data.size(); i++) {
        printf("%-4d %11lld  %-7s  %-9d  %-5d %-5d %-5d %-4d\n", i + 1, data.at(i).number, data.at(i).name, data.at(i).classCode,
               data.at(i).result_course_1, data.at(i).result_course_2, data.at(i).result_course_3, sum(data.at(i)));
    }
}

void displayVectorData(vector<StudentData> data) {
    if (data.empty()) {
        cout << "无记录" << endl;
        return;
    }
    printf("序号     学号      名字     班级     科目1 科目2 科目3 总分\n");
    for (int i = 0; i < data.size(); i++) {
        printf("%-4d %11lld  %-7s  %-9d  %-5d %-5d %-5d %-4d\n", i + 1, data.at(i).number, data.at(i).name, data.at(i).classCode,
               data.at(i).result_course_1, data.at(i).result_course_2, data.at(i).result_course_3, sum(data.at(i)));
    }
}

void displayVectorDataWithAvgr(vector<StudentData> data) {
    if (data.empty()) {
        cout << "无记录" << endl;
        return;
    }
    long long avgr_1 = 0, avgr_2 = 0, avgr_3 = 0;
    printf("序号     学号      名字     班级     科目1 科目2 科目3\n");
    printf("序号     学号      名字     班级     科目1 科目2 科目3 总分\n");
    for (int i = 0; i < data.size(); i++) {
        printf("%-4d %11lld  %-7s  %-9d  %-5d %-5d %-5d %-4d\n", i + 1, data.at(i).number, data.at(i).name, data.at(i).classCode,
               data.at(i).result_course_1, data.at(i).result_course_2, data.at(i).result_course_3, sum(data.at(i)));
        avgr_1 += data.at(i).result_course_1;
        avgr_2 += data.at(i).result_course_2;
        avgr_3 += data.at(i).result_course_3;
    }
    avgr_1 /= (signed)data.size();
    avgr_2 /= (signed)data.size();
    avgr_3 /= (signed)data.size();
    cout << "科目1的平均分为" << avgr_1 << endl;
    cout << "科目2的平均分为" << avgr_2 << endl;
    cout << "科目3的平均分为" << avgr_3 << endl;
}

void addLog() {
    StudentData temp{};
    auto * operations = new FileOperation;

    cout << "添加新学生记录向导" << endl;
    cout << "请输入9位数的班级id" << endl;
    cin.sync();
    cin >> temp.classCode;
    while (cin.fail() || temp.classCode < 100000000 || temp.classCode > 999999999) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.classCode;
    }
    cout << "请输入11位数的学号" << endl;
    cin.sync();
    cin >> temp.number;
    while (cin.fail() || !numberRepeat(temp.number) || temp.number < 10000000000 || temp.number > 99999999999) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.number;
    }
    cout << "请输入名字" << endl;
    cin.sync();
    cin.getline(temp.name, 20);
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin.getline(temp.name, 20);
    }
    cout << "请输入第一门分数" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    while (cin.fail() || temp.result_course_1 < 0 || temp.result_course_1 > 100) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_1;
    }
    cout << "请输入第二门分数" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    while (cin.fail() || temp.result_course_2 < 0 || temp.result_course_2 > 100) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_2;
    }
    cout << "请输入第三门分数" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    while (cin.fail() || temp.result_course_3 < 0 || temp.result_course_3 > 100) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_3;
    }
    operations->addLog(temp);
    cout << "添加成功" << endl;
    delete operations;
}

void modifyLog() {
    StudentData temp{};
    FileOperation operations;
    int numberToChange = -1;

    cout << "修改学生记录向导" << endl;
    displayData(operations);
    cout << "请输入需要修改的学生编号，输入0以回到上一层" << endl;
    cin.sync();
    cin >> numberToChange;
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "请检查输入" << endl;
        cin >> numberToChange;
    }
    if (!numberToChange) {
        return;
    }
    while (!operations.getLog(numberToChange - 1, temp)) {
        cout << "编号错误，请重新输入" << endl;
        cin.sync();
        cin >> numberToChange;
        while (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "请检查输入" << endl;
            cin >> numberToChange;
        }
        if (!numberToChange) {
            return;
        }
    }
    cout << "请输入新的学生信息" << endl;
    cout << "请输入第一门分数" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    while (cin.fail() || temp.result_course_1 < 0 || temp.result_course_1 > 100) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_1;
    }
    cout << "请输入第二门分数" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    while (cin.fail() || temp.result_course_2 < 0 || temp.result_course_2 > 100) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_2;
    }
    cout << "请输入第三门分数" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    while (cin.fail() || temp.result_course_3 < 0 || temp.result_course_3 > 100) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_3;
    }
    if (!operations.modifyLog(numberToChange - 1, temp)) {
        cout << "修改失败" << endl;
        return;
    }
    cout << "修改成功" << endl;
}

bool getLog(long long number, StudentData & data) {
    auto operation = new FileOperation;
    std::map<long long, StudentData> harsh;
    int i = 0;
    StudentData temp{};

    while (operation->getLog(i, temp)) {
        harsh.insert(std::map<long long, StudentData>::value_type(temp.number, temp));
        i++;
    }
    auto iter = harsh.find(number);
    delete operation;

    if (iter != harsh.end()) {
        data = iter->second;
        return true;
    } else {
        return false;
    }
}

void showLog() {
    StudentData temp{};
    long long numberToLook = 1;

    cout << "请输入查询学生学号，输入0以回到上一层" << endl;
    cin.sync();
    cin >> numberToLook;
    while (cin.fail() || numberToLook < 10000000000 || numberToLook > 99999999999) {
        if (!numberToLook) {
            return;
        }
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> numberToLook;
    }
    while (!getLog(numberToLook, temp)) {
        cout << "查询错误，请检查学号是否输入错误" << endl;
        return;
    }
    printf("    学号      名字     班级     科目1 科目2 科目3 总分\n");
    printf("%11lld  %-7s  %-9d  %-5d %-5d %-5d %-4d\n", temp.number, temp.name, temp.classCode, temp.result_course_1,
           temp.result_course_2, temp.result_course_3, sum(temp));
}

void deleteLog() {
    FileOperation operation;
    int numberToDelete;

    displayData(operation);
    cout << "请输入需要删除学生的编号，输入0以回到上一层" << endl;
    cin.sync();
    cin >> numberToDelete;
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> numberToDelete;
    }
    if (!numberToDelete) {
        return;
    }
    while (!operation.deleteLog(numberToDelete)) {
        cout << "删除失败，请检查输入的数字是否有效" << endl;
        cin >> numberToDelete;
    }
    cout << "删除成功" << endl;
}

void sortInSolo() {
    int todo = 0;
    cout << "按第一门课程成绩排序请按1，按第二门课程成绩排序请按2，按第三门课程成绩排序请按3" << endl;
    cin >> todo;
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> todo;
    }
    switch (todo) {
    case 1:
        displayVectorDataWithAvgr(sort_by_course_result_1());
        break;
    case 2:
        displayVectorDataWithAvgr(sort_by_course_result_2());
        break;
    case 3:
        displayVectorDataWithAvgr(sort_by_course_result_3());
        break;
    default:
        cout << "错误的输入" << endl;
    }
}

void showAll() {
    int todo = 0;
    cout << "按总分排序请按1，按班级排序请按2，按学号排序请按3，按单科排序请按4" << endl;
    cin >> todo;
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> todo;
    }
    switch (todo) {
    case 1:
        displayVectorDataWithAvgr(sort_by_sum());
        break;
    case 2:
        displayVectorDataWithAvgr(sort_by_class());
        break;
    case 3:
        displayVectorDataWithAvgr(sort_by_num());
        break;
    case 4:
        sortInSolo();
        break;
    default:
        cout << "错误的输入" << endl;
    }
}

void showWarning() {
    vector<StudentData> all = sort_by_class();
    vector<StudentData> warning(all.size());

    auto it = std::copy_if(all.begin(), all.end(), warning.begin(), [](StudentData a) {
        return a.result_course_1 < 60 || a.result_course_2 < 60 || a.result_course_3 < 60;
    });
    warning.resize(std::distance(warning.begin(), it));
    displayVectorData(warning);
}

void functionSwitch() {
    int switcher;

    while (true) {
        system("cls");
        menu();
        cin.sync();
        cin >> switcher;
        if (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "错误的输入" << endl;
            system("pause");
            continue;
        }
        switch (switcher) {
        case 0:
            exit(0);
        case 1:
            system("cls");
            addLog();
            system("pause");
            break;
        case 2:
            system("cls");
            modifyLog();
            system("pause");
            break;
        case 3:
            system("cls");
            deleteLog();
            system("pause");
            break;
        case 4:
            system("cls");
            showAll();
            system("pause");
            break;
        case 5:
            system("cls");
            showLog();
            system("pause");
            break;
        case 6:
            system("cls");
            showWarning();
            system("pause");
            break;
        default:
            system("cls");
            cout << "错误的输入" << endl;
            system("pause");
            break;
        }
    }
}
