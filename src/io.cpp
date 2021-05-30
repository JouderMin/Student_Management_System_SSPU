//
// Created by zjy on 2021/5/5.
//
#include "io.h"
#include "DataSort.h"
#include "FileOperation.h"
#include <cstdio>
#include <iostream>

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
    cout << "0、退出程序" << endl;
}

void displayData(FileOperation & file) {
    vector<StudentData> data;
    int i;

    file.allLog(data);
    printf("序号  学号  名字  班级  科目1 科目2 科目3\n");
    for (i = 0; i < data.size(); i++) {
        printf("%d %d  %s  %d  %d %d %d\n", i, data.at(i).number, data.at(i).name, data.at(i).classCode, data.at(i).result_course_1,
               data.at(i).result_course_2, data.at(i).result_course_3);
    }
}

void addLog() {
    StudentData temp{};
    auto * operations = new FileOperation;

    cout << "请输入班级" << endl;
    cin.sync();
    cin >> temp.classCode;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.classCode;
    }
    cout << "请输入学号" << endl;
    cin.sync();
    cin >> temp.number;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.number;
    }
    cout << "请输入名字" << endl;
    cin.sync();
    cin.getline(temp.name, 20);
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin.getline(temp.name, 20);
    }
    cout << "请输入第一门分数" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_1;
    }
    cout << "请输入第二门分数" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_2;
    }
    cout << "请输入第三门分数" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_3;
    }
    operations->addLog(temp);
    delete operations;
}

void modifyLog() {
    StudentData temp{};
    FileOperation operations;
    int numberToChange;

    displayData(operations);
    cout << "请输入需要修改的学生编号" << endl;
    cin.sync();
    cin >> numberToChange;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "请检查输入" << endl;
        cin >> numberToChange;
    }
    while (!operations.getLog(numberToChange, temp)) {
        cout << "编号错误，请重新输入" << endl;
        cin.sync();
        cin >> numberToChange;
        if (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "请检查输入" << endl;
            cin >> numberToChange;
        }
    }
    cout << "请输入新的学生信息" << endl;
    cout << "请输入班级" << endl;
    cin.sync();
    cin >> temp.classCode;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.classCode;
    }
    cout << "请输入学号" << endl;
    cin.sync();
    cin >> temp.number;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.number;
    }
    cout << "请输入名字" << endl;
    cin.sync();
    cin.getline(temp.name, 20);
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin.getline(temp.name, 20);
    }
    cout << "请输入第一门分数" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_1;
    }
    cout << "请输入第二门分数" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_2;
    }
    cout << "请输入第三门分数" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> temp.result_course_3;
    }
    operations.modifyLog(numberToChange, temp);
}

void showLog() {
    StudentData temp{};
    auto operation = new FileOperation;
    int numberToLook;

    cout << "请输入查询学生信息" << endl;
    cin.sync();
    cin >> numberToLook;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "错误的输入" << endl;
        cin >> numberToLook;
    }
    while (!operation->getLog(numberToLook, temp)) {
        cout << "查询错误，请检查学号是否输入错误" << endl;
    }
    printf("%d  %s  %d  %d %d %d\n", temp.number, temp.name, temp.classCode, temp.result_course_1, temp.result_course_2,
           temp.result_course_3);
}

void deleteLog() {
    FileOperation operation;
    int numberToDelete;

    displayData(operation);
    cout << "请输入需要删除学生的编号" << endl;
    cin >> numberToDelete;
    while (!operation.deleteLog(numberToDelete)) {
        cout << "删除失败，请检查输入的数字是否有效" << endl;
    }
    cout << "删除成功" << endl;
}

void showAll() {
    FileOperation operations;
    std::vector<StudentData> temp;
    operations.allLog(temp);
    int todo = 0;
    cout << "按总分排序请按1，按班级排序请按2，按学号排序请按3，按单科排序请按4" << endl;
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
            continue;
        }
        switch (switcher) {
        case 0:
            exit(0);
        case 1:
            addLog();
            break;
        case 2:
            modifyLog();
            break;
        case 3:
            deleteLog();
            break;
        case 4:
            showAll();
            break;
        case 5:
            showLog();
            break;
        default:
            cout << "错误的输入" << endl;
            break;
        }
    }
}
