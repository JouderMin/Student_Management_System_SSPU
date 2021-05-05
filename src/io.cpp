//
// Created by zjy on 2021/5/5.
//
#include "io.h"
#include <iostream>

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

int io(int operation) {
    switch (operation) { case 1: }
}