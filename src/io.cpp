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
    cout << "3����ʾ����ѧ����Ϣ" << endl;
    cout << "4����ѯѧ����Ϣ" << endl;
    cout << "0���˳�����" << endl;
}
void add() {
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

void selection() {
    int userSelect;
    while (true) {
        system("cls");
        menu();
        cin >> userSelect;
        if (cin.fail() || userSelect < 0 || userSelect > 4) {
            cout << "���������" << endl;
            cin.clear();
            cin.sync();
            cin >> userSelect;
        }
        switch (userSelect) {
        case 0:
            std::exit(0);
        case 1:
            add();
            break;
            // TODO ʣ��ĺ�����δʵ�֡�

        default:
            cout << "���������" << endl;
            break;
        }
    }
}
