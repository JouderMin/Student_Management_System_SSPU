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
    cout << "���������ʵ������ҵ" << endl;
    cout << "ѧ����Ϣ����ϵͳ" << endl;
    cout << "������ ���� ������ �ż���" << endl;
    cout << "-------------------------" << endl;
    cout << "��ӭʹ��ѧ����Ϣ����ϵͳ�����������±���Է��ʶ�Ӧ����" << endl;
    cout << "1���½�ѧ����Ϣ" << endl;
    cout << "2���޸�ѧ����Ϣ" << endl;
    cout << "3��ɾ��ѧ����Ϣ" << endl;
    cout << "4����ʾ����ѧ����Ϣ" << endl;
    cout << "5����ѯѧ����Ϣ" << endl;
    cout << "0���˳�����" << endl;
}
void addLog() {
    StudentData temp{};
    auto * operations = new FileOperation;
    cout << "������༶" << endl;
    cin.sync();
    cin >> temp.classCode;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.classCode;
    }
    cout << "������ѧ��" << endl;
    cin.sync();
    cin >> temp.number;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.number;
    }
    cout << "����������" << endl;
    cin.sync();
    cin.getline(temp.name, 20);
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.name;
    }
    cout << "�������һ�ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_1;
    }
    cout << "������ڶ��ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_2;
    }
    cout << "����������ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_3;
    }
    operations->addLog(temp);
    delete operations;
}
void modifyLog() {
    StudentData temp{};
    FileOperation operations;
    int numberToChange;
    cout << "��������Ҫ�޸ĵ�ѧ�����" << endl;
    cin >> numberToChange;
    cout << "�������µ�ѧ����Ϣ" << endl;
    cout << "������༶" << endl;
    cin.sync();
    cin >> temp.classCode;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.classCode;
    }
    cout << "������ѧ��" << endl;
    cin.sync();
    cin >> temp.number;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.number;
    }
    cout << "����������" << endl;
    cin.sync();
    cin.getline(temp.name, 20);
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.name;
    }
    cout << "�������һ�ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_1;
    }
    cout << "������ڶ��ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_2;
    }
    cout << "����������ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_3;
    }
    operations.modifyLog(numberToChange, temp);
}
void showLog() {
    StudentData temp{};
    FileOperation operation;
    int numberToLook;
    cout << "�������ѯѧ����Ϣ" << endl;
    cin >> numberToLook;
    if (operation.getLog(numberToLook, temp)) {
        cout << temp.number;
        cout << temp.name;
        cout << temp.classCode;
        cout << temp.result_course_1;
        cout << temp.result_course_2;
        cout << temp.result_course_3;
    } else {
        cout << "��ѯ��������ѧ���Ƿ��������";
        showLog();
    }
}
void deleteLog() {
    FileOperation operation;
    int numberToDelete;
    cout << "��������Ҫɾ��ѧ���ı��" << endl;
    cin >> numberToDelete;
    operation.deleteLog(numberToDelete);
}
void showAll() {
    FileOperation operations;
    std::vector<StudentData> temp;
    operations.allLog(temp);
    cout << "����������ѧ������" << endl;
    for (auto i : temp) {
        cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " " << i.result_course_3
             << endl;
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
            cout << "���������" << endl;
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
            cout << "���������" << endl;
            break;
        }
    }
}
