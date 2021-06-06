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
    cout << "6����ʾ�����в����������ѧ����Ϣ" << endl;
    cout << "0���˳�����" << endl;
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
        cout << "�޼�¼" << endl;
        return;
    }
    printf("���     ѧ��      ����     �༶     ��Ŀ1 ��Ŀ2 ��Ŀ3 �ܷ�\n");
    for (int i = 0; i < data.size(); i++) {
        printf("%-4d %11lld  %-7s  %-9d  %-5d %-5d %-5d %-4d\n", i + 1, data.at(i).number, data.at(i).name, data.at(i).classCode,
               data.at(i).result_course_1, data.at(i).result_course_2, data.at(i).result_course_3, sum(data.at(i)));
    }
}

void displayVectorData(vector<StudentData> data) {
    if (data.empty()) {
        cout << "�޼�¼" << endl;
        return;
    }
    printf("���     ѧ��      ����     �༶     ��Ŀ1 ��Ŀ2 ��Ŀ3 �ܷ�\n");
    for (int i = 0; i < data.size(); i++) {
        printf("%-4d %11lld  %-7s  %-9d  %-5d %-5d %-5d %-4d\n", i + 1, data.at(i).number, data.at(i).name, data.at(i).classCode,
               data.at(i).result_course_1, data.at(i).result_course_2, data.at(i).result_course_3, sum(data.at(i)));
    }
}

void displayVectorDataWithAvgr(vector<StudentData> data) {
    if (data.empty()) {
        cout << "�޼�¼" << endl;
        return;
    }
    long long avgr_1 = 0, avgr_2 = 0, avgr_3 = 0;
    printf("���     ѧ��      ����     �༶     ��Ŀ1 ��Ŀ2 ��Ŀ3\n");
    printf("���     ѧ��      ����     �༶     ��Ŀ1 ��Ŀ2 ��Ŀ3 �ܷ�\n");
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
    cout << "��Ŀ1��ƽ����Ϊ" << avgr_1 << endl;
    cout << "��Ŀ2��ƽ����Ϊ" << avgr_2 << endl;
    cout << "��Ŀ3��ƽ����Ϊ" << avgr_3 << endl;
}

void addLog() {
    StudentData temp{};
    auto * operations = new FileOperation;

    cout << "�����ѧ����¼��" << endl;
    cout << "������9λ���İ༶id" << endl;
    cin.sync();
    cin >> temp.classCode;
    while (cin.fail() || temp.classCode < 100000000 || temp.classCode > 999999999) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.classCode;
    }
    cout << "������11λ����ѧ��" << endl;
    cin.sync();
    cin >> temp.number;
    while (cin.fail() || !numberRepeat(temp.number) || temp.number < 10000000000 || temp.number > 99999999999) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.number;
    }
    cout << "����������" << endl;
    cin.sync();
    cin.getline(temp.name, 20);
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin.getline(temp.name, 20);
    }
    cout << "�������һ�ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    while (cin.fail() || temp.result_course_1 < 0 || temp.result_course_1 > 100) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_1;
    }
    cout << "������ڶ��ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    while (cin.fail() || temp.result_course_2 < 0 || temp.result_course_2 > 100) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_2;
    }
    cout << "����������ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    while (cin.fail() || temp.result_course_3 < 0 || temp.result_course_3 > 100) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_3;
    }
    operations->addLog(temp);
    cout << "��ӳɹ�" << endl;
    delete operations;
}

void modifyLog() {
    StudentData temp{};
    FileOperation operations;
    int numberToChange = -1;

    cout << "�޸�ѧ����¼��" << endl;
    displayData(operations);
    cout << "��������Ҫ�޸ĵ�ѧ����ţ�����0�Իص���һ��" << endl;
    cin.sync();
    cin >> numberToChange;
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "��������" << endl;
        cin >> numberToChange;
    }
    if (!numberToChange) {
        return;
    }
    while (!operations.getLog(numberToChange - 1, temp)) {
        cout << "��Ŵ�������������" << endl;
        cin.sync();
        cin >> numberToChange;
        while (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "��������" << endl;
            cin >> numberToChange;
        }
        if (!numberToChange) {
            return;
        }
    }
    cout << "�������µ�ѧ����Ϣ" << endl;
    cout << "�������һ�ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    while (cin.fail() || temp.result_course_1 < 0 || temp.result_course_1 > 100) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_1;
    }
    cout << "������ڶ��ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    while (cin.fail() || temp.result_course_2 < 0 || temp.result_course_2 > 100) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_2;
    }
    cout << "����������ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    while (cin.fail() || temp.result_course_3 < 0 || temp.result_course_3 > 100) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_3;
    }
    if (!operations.modifyLog(numberToChange - 1, temp)) {
        cout << "�޸�ʧ��" << endl;
        return;
    }
    cout << "�޸ĳɹ�" << endl;
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

    cout << "�������ѯѧ��ѧ�ţ�����0�Իص���һ��" << endl;
    cin.sync();
    cin >> numberToLook;
    while (cin.fail() || numberToLook < 10000000000 || numberToLook > 99999999999) {
        if (!numberToLook) {
            return;
        }
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> numberToLook;
    }
    while (!getLog(numberToLook, temp)) {
        cout << "��ѯ��������ѧ���Ƿ��������" << endl;
        return;
    }
    printf("    ѧ��      ����     �༶     ��Ŀ1 ��Ŀ2 ��Ŀ3 �ܷ�\n");
    printf("%11lld  %-7s  %-9d  %-5d %-5d %-5d %-4d\n", temp.number, temp.name, temp.classCode, temp.result_course_1,
           temp.result_course_2, temp.result_course_3, sum(temp));
}

void deleteLog() {
    FileOperation operation;
    int numberToDelete;

    displayData(operation);
    cout << "��������Ҫɾ��ѧ���ı�ţ�����0�Իص���һ��" << endl;
    cin.sync();
    cin >> numberToDelete;
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> numberToDelete;
    }
    if (!numberToDelete) {
        return;
    }
    while (!operation.deleteLog(numberToDelete)) {
        cout << "ɾ��ʧ�ܣ���������������Ƿ���Ч" << endl;
        cin >> numberToDelete;
    }
    cout << "ɾ���ɹ�" << endl;
}

void sortInSolo() {
    int todo = 0;
    cout << "����һ�ſγ̳ɼ������밴1�����ڶ��ſγ̳ɼ������밴2���������ſγ̳ɼ������밴3" << endl;
    cin >> todo;
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
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
        cout << "���������" << endl;
    }
}

void showAll() {
    int todo = 0;
    cout << "���ܷ������밴1�����༶�����밴2����ѧ�������밴3�������������밴4" << endl;
    cin >> todo;
    while (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
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
        cout << "���������" << endl;
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
            cout << "���������" << endl;
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
            cout << "���������" << endl;
            system("pause");
            break;
        }
    }
}
