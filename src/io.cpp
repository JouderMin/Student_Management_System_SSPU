//
// Created by zjy on 2021/5/5.
//
#include "io.h"
#include "FileOperation.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void menu() {
    cout << "程序设计与实践大作业" << endl;
    cout << "学生信息管理系统" << endl;
    cout << "周张珉 钟勇 朱苏雨 张荐阳" << endl;
    cout << "-------------------------" << endl;
    cout << "欢迎使用学生信息管理系统，请输入以下标号以访问对应功能" << endl;
    cout << "1、新建学生信息" << endl;
    cout << "2、修改学生信息" << endl;
    cout << "3、显示所有学生信息" << endl;
    cout << "4、查询学生信息" << endl;
    cout << "0、退出程序" << endl;
}
void add() {
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
        cin >> temp.name;
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
void modify() {
    StudentData temp;
    FileOperation operations;
    int numbertochange;
    cout << "请输入需要修改的学生编号" << endl;
    cin >> numbertochange;
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
        cin >> temp.name;
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
    operations.modifyLog(numbertochange, temp);
}
void showlog() {
    StudentData temp;
    FileOperation operation;
    int numbertolook;
    cout << "请输入查询学生信息" << endl;
    cin >> numbertolook;
    if (operation.getLog(numbertolook, temp)) {
        cout << temp.number;
        cout << temp.name;
        cout << temp.classCode;
        cout << temp.result_course_1;
        cout << temp.result_course_2;
        cout << temp.result_course_3;
    } else {
        cout << "查询错误，请检查学号是否输入错误";
        showlog();
    }
}
void deletestudent() {
    FileOperation operation;
    int numbertodelete;
    cout << "请输入需要删除学生的编号" << endl;
    cin >> numbertodelete;
    operation.deleteLog(numbertodelete);
}
void showall() {
}
