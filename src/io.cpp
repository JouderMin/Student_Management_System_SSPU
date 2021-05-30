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

void displayData(FileOperation & file) {
    vector<StudentData> data;
    int i;

    file.allLog(data);
    printf("���  ѧ��  ����  �༶  ��Ŀ1 ��Ŀ2 ��Ŀ3\n");
    for (i = 0; i < data.size(); i++) {
        printf("%d %d  %s  %d  %d %d %d\n", i, data.at(i).number, data.at(i).name, data.at(i).classCode, data.at(i).result_course_1,
               data.at(i).result_course_2, data.at(i).result_course_3);
    }
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
        cin.getline(temp.name, 20);
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

    displayData(operations);
    cout << "��������Ҫ�޸ĵ�ѧ�����" << endl;
    cin.sync();
    cin >> numberToChange;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "��������" << endl;
        cin >> numberToChange;
    }
    while (!operations.getLog(numberToChange, temp)) {
        cout << "��Ŵ�������������" << endl;
        cin.sync();
        cin >> numberToChange;
        if (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "��������" << endl;
            cin >> numberToChange;
        }
    }
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
        cin.getline(temp.name, 20);
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
    auto operation = new FileOperation;
    int numberToLook;

    cout << "�������ѯѧ����Ϣ" << endl;
    cin.sync();
    cin >> numberToLook;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> numberToLook;
    }
    while (!operation->getLog(numberToLook, temp)) {
        cout << "��ѯ��������ѧ���Ƿ��������" << endl;
    }
    printf("%d  %s  %d  %d %d %d\n", temp.number, temp.name, temp.classCode, temp.result_course_1, temp.result_course_2,
           temp.result_course_3);
}

void deleteLog() {
    FileOperation operation;
    int numberToDelete;

    displayData(operation);
    cout << "��������Ҫɾ��ѧ���ı��" << endl;
    cin >> numberToDelete;
    while (!operation.deleteLog(numberToDelete)) {
        cout << "ɾ��ʧ�ܣ���������������Ƿ���Ч" << endl;
    }
    cout << "ɾ���ɹ�" << endl;
}

void showAll() {
    FileOperation operations;
    std::vector<StudentData> temp;
    operations.allLog(temp);
    int todo = 0;
    cout << "���ܷ������밴1�����༶�����밴2����ѧ�������밴3�������������밴4" << endl;
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
