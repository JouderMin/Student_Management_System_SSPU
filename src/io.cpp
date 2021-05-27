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
    cout << "3、删除学生信息" << endl;
    cout << "4、显示所有学生信息" << endl;
    cout << "5、查询学生信息" << endl;
    cout << "0、退出程序" << endl;
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
void modifyLog() {
    StudentData temp{};
    FileOperation operations;
    int numberToChange;
    cout << "请输入需要修改的学生编号" << endl;
    cin >> numberToChange;
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
    operations.modifyLog(numberToChange, temp);
}
void showLog() {
    StudentData temp{};
    FileOperation operation;
    int numberToLook;
    cout << "请输入查询学生信息" << endl;
    cin >> numberToLook;
    if (operation.getLog(numberToLook, temp)) {
        cout << temp.number;
        cout << temp.name;
        cout << temp.classCode;
        cout << temp.result_course_1;
        cout << temp.result_course_2;
        cout << temp.result_course_3;
    } else {
        cout << "查询错误，请检查学号是否输入错误";
        showLog();
    }
}
void deleteLog() {
    FileOperation operation;
    int numberToDelete;
    cout << "请输入需要删除学生的编号" << endl;
    cin >> numberToDelete;
    operation.deleteLog(numberToDelete);
}
void showAll() {
    FileOperation operations;
    std::vector<StudentData> temp;
    operations.allLog(temp);
    int todo = 0;
    cout << "按总分排序请按1，按班级排序请按2，按学号排序请按3，按单科排序请按4,不排序请按5" << endl;
    cin >> todo;
    StudentData switchtemp;
    bool risefall = 0;
    switch (todo) {
    case 1: {
        cout << "输入0以升序排列，输入1以降序排列" << endl;
        cin >> risefall;
        int sum1 = 0;
        int sum2 = 0;
        for (auto i : temp) {
            sum1 = i.result_course_1 + i.result_course_2 + i.result_course_3;
            for (auto j : temp) {
                sum2 = j.result_course_1 + j.result_course_2 + j.result_course_3;
                if (risefall) {
                    if (sum2 > sum1) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                } else {
                    if (sum2 < sum1) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                }
                sum2       = 0;
                switchtemp = {0, 0, 0, 0, 0, 0};
            }
            sum1 = 0;
        }
        risefall = 0;
        cout << "以下是所有学生数据" << endl;
        for (auto i : temp) {
            cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " " << i.result_course_3
                 << endl;
        }
    } break;
    case 2: {
        cout << "输入0以升序排列，输入1以降序排列" << endl;
        cin >> risefall;
        for (auto i : temp) {
            for (auto j : temp) {
                if (risefall) {
                    if (i.classCode > j.classCode) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                } else {
                    if (i.classCode < j.classCode) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                }
                switchtemp = {0, 0, 0, 0, 0, 0};
            }
        }
        risefall = 0;
        cout << "以下是所有学生数据" << endl;
        for (auto i : temp) {
            cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " " << i.result_course_3
                 << endl;
        }
        break;
    }
    case 3: {
        cout << "输入0以升序排列，输入1以降序排列" << endl;
        cin >> risefall;
        for (auto i : temp) {
            for (auto j : temp) {
                if (risefall) {
                    if (i.number > j.number) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                } else {
                    if (i.number < j.number) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                }
                switchtemp = {0, 0, 0, 0, 0, 0};
            }
        }
        risefall = 0;
        cout << "以下是所有学生数据" << endl;
        for (auto i : temp) {
            cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " " << i.result_course_3
                 << endl;
        }
        break;
    }
    case 4: {
        int course = 0;
        cout << "按科目一成绩排序请按1，按科目二成绩排序请按2，按科目三成绩排序请按3" << endl;
        cin >> course;
        switch (course) {
        case 1: {
            cout << "输入0以升序排列，输入1以降序排列" << endl;
            cin >> risefall;
            for (auto i : temp) {
                for (auto j : temp) {
                    if (risefall) {
                        if (i.result_course_1 > j.result_course_1) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    } else {
                        if (i.result_course_1 < j.result_course_1) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    }
                    switchtemp = {0, 0, 0, 0, 0, 0};
                }
            }
            risefall = 0;
            cout << "以下是所有学生数据" << endl;
            for (auto i : temp) {
                cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " "
                     << i.result_course_3 << endl;
            }
            break;
        }
        case 2: {
            cout << "输入0以升序排列，输入1以降序排列" << endl;
            cin >> risefall;
            for (auto i : temp) {
                for (auto j : temp) {
                    if (risefall) {
                        if (i.result_course_2 > j.result_course_2) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    } else {
                        if (i.result_course_2 < j.result_course_2) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    }
                    switchtemp = {0, 0, 0, 0, 0, 0};
                }
            }
            risefall = 0;
            cout << "以下是所有学生数据" << endl;
            for (auto i : temp) {
                cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " "
                     << i.result_course_3 << endl;
            }
            break;
        }
        case 3: {
            cout << "输入0以升序排列，输入1以降序排列" << endl;
            cin >> risefall;
            for (auto i : temp) {
                for (auto j : temp) {
                    if (risefall) {
                        if (i.result_course_3 > j.result_course_3) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    } else {
                        if (i.result_course_3 < j.result_course_3) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    }
                    switchtemp = {0, 0, 0, 0, 0, 0};
                }
            }
            risefall = 0;
            cout << "以下是所有学生数据" << endl;
            for (auto i : temp) {
                cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " "
                     << i.result_course_3 << endl;
            }
            break;
        }
        }
    }
    case 5: {
        cout << "以下是所有学生数据" << endl;
        for (auto i : temp) {
            cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " " << i.result_course_3
                 << endl;
        }
    }
    }
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
